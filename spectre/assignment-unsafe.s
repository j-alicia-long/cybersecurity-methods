
.data
.align 64
r11_format: 
.string "hot   val: %lu\n"

r12_format: 
.string "probe val: %lu\n" 

r13_format: 
.string "cold  val: %lu\n"

.align 64
.fill 25, 1, 0x0
read_targets: 
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
.quad hot_addr
# set to hot_addr to make the probe access cold.
# set to probe_addr to make the probe access 
# hot thanks to speculative execution.
.quad probe_addr

.align 64
.fill 22, 1, 0x0
call_targets: 
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
.quad read_hot
# this function does not read from a register. So, 
# the 15th address in read_targets could be all 0x0s.
# Setting it to probe_addr will push the speculative
# execution (it thinks it is going to execute read_hot)
# to read from probe_addr.
.quad read_nop

.align 128
hot_addr: 
.fill 64, 1, 0x0

.align 128
cold_addr: 
.fill 64, 1, 0x0

.align 128
probe_addr: 
.fill 64, 1, 0x0

.text
.global main
.type main, @function
.extern printf

main: 

# counters for tsc delta accumulation
# r11 is for hot_addr read time
# r12 is for probe_addr read time
# r13 is for cold_addr read time
	mov $0x0, %r11d
	mov $0x0, %r12d
	mov $0x0, %r13d

# setup driver_loop variables
	mov $0x0, %r14d
	mov $0xc000, %r15d

driver_loop_head: 

	push %r11
	push %r12
	push %r13

	mfence

# flush the cache at the addresses that hold these variables.
	clflush (hot_addr)
	clflush (cold_addr)
	clflush (probe_addr)
# clflush is a memory operation and mfence is required if you
# want to guarantee that it is done before beginning to execute
# the next instruction.
	mfence

# setup read_loop variables.
        mov $0x0,%eax
        mov $0xf,%ebx

read_loop_head: 
# At every iteration, the target must be uncached
# so that execution can proceed down the speculative
# path long enough to do the memory access.
# This is not strictly necessary. See "FYI" below
# for additional information.
	clflush (call_targets)
	mfence

	mov read_targets(,%rax,8), %r9 
	mov call_targets(,%rax,8), %r10 

# FYI: If you take out the clflush above for the call_targets,
# the branch predictor has enough time to do its "bad" behavior
# if the number of nops here does not exceed ~10. Fascinating.
#       times 12 nop
        call *%r10

        incq %rax
        cmpq %rbx,%rax
        jb read_loop_head

        # restore the tsc delta accumulation variables.
	pop %r13
	pop %r12
	pop %r11

	mfence

# record tsc before the operation
        call read_tsc
        movq %rbp, %r8
# read the value.
	mov (hot_addr), %r9
# need a load fence here to make sure that the operation completes
# before moving on to the next instruction.
	lfence
# read the tsc after the operation and calculate the difference
# between before/after and add it to the runnning total.
        call read_tsc
        subq %r8, %rbp
        addq %rbp, %r11

# basically the same song/dance as above -- read a different
# location in memory and accumulate tsc deltas into a 
# different register.
        call read_tsc
        movq %rbp, %r8
	mov (probe_addr), %r9
	lfence
        call read_tsc
        subq %r8, %rbp
        addq %rbp, %r12

# basically the same song/dance as above -- read a different
# location in memory and accumulate tsc deltas into a 
# different register.
        call read_tsc
        movq %rbp, %r8
	mov (cold_addr), %r9
	lfence
        call read_tsc
        subq %r8, %rbp
        addq %rbp, %r13

# ++, check and loop(?)
	inc %r14
	cmp %r15, %r14
        jb driver_loop_head

# print r11 (the time to read hot_addr)
        movq %r11, %rsi
        leal r11_format,%edi
        movl $0,%eax
        call printf

# print r12 (the time to read probe_addr)
        movq %r12, %rsi
        leal r12_format,%edi
        movl $0,%eax
        call printf

# print r13 (the time to read cold_addr)
        movq %r13, %rsi
        leal r13_format,%edi
        movl $0,%eax
        call printf

# exit
        movl $0x1,%eax
        int $0x80

# support functions

# read the tsc (time stamp counter) into rbp
# according to x86 developer manual:  Read time-stamp counter into EDX:EAX
# so shift the low 32 bits of RDX(aka EDX) left and OR in lower 32 bits of RAX (aka EAX)
# together to get the whole time stamp counter value
.global read_tsc
.type read_tsc, @function
read_tsc: 
        rdtsc
        shlq $32,%rdx
        orq %rax,%rdx
        movq %rdx,%rbp
        ret
# read *r9 into r9
.global read_hot
.type read_hot, @function
read_hot: 
	mov (%r9), %r9
        ret
# don't do anything
.global read_nop
.type read_nop, @function
read_nop: 
        nop
        ret

