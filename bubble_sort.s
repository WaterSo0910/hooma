.data
N:      .word   10

arr:   .word 5,3,6,7,31,23,43,12,45,1
str1:   .string "Array: "
str2:   .string "Sorted: "
str3:   .string "\n"
space:  .string " "

.text
main:


        lw      t0, N

        la      a1, str1
        li      a0, 4
        ecall

        la      a1, str3
        li      a0, 4
        ecall
   

        la      a0, arr
        jal     ra, printArray
        
        la      a1, str3
        li      a0, 4
        ecall

        la      a1, str2
        li      a0, 4
        ecall


        la      a0, arr
        jal     ra, bubblesort

        jal     ra, printArray

        la      a1, str3
        li      a0, 4
        ecall

        li      a0, 10
        ecall
bubblesort:
        addi    sp, sp, -8 # make room on stack for 5 registers
        sw      ra, 4(sp) # save return address on stack
        sw      a0, 0(sp) # save x22 on stack
        li      a1, 0 # i = 0
        j       sort_for1
sort_for1:
        bge     a1, t0, exit1 # go to exit1 if i >= n
        addi    a2, a1, -1 # j = i - 1
        j       sort_for2
sort_for2:
        blt     a2, zero, exit2 # go to exit2 if j < 0
        slli    t1, a2, 2  # x5 = j * 8
        add     t1, a0, t1  # x5 = v + (j * 8)
        lw      t2, 0(t1)  # x6 = v[j]
        lw      t3, 4(t1)  # x7 = v[j + 1]
        ble     t2, t3, exit2   # go to exit2 if x6 < x7
        mv      t1, a2  # second swap parameter is j
        jal     ra, swap  # call swap
        addi    a2, a2, -1
        j       sort_for2  # go to for2tst
exit2: 
        addi    a1, a1, 1 # i += 1
        j       sort_for1 # go to for1tst
exit1: 

        lw      a0, 0(sp)  # restore x22 from stack
        lw      ra, 4(sp)  # restore return address from stack
        addi    sp, sp, 8  # restore stack pointer
        ret

swap:
        
        slli    t2, t1, 2
        add     t2, t2, a0
        lw      a4, 0(t2)
        lw      a3, 4(t2)
        sw      a3, 0(t2)
        sw      a4, 4(t2)
        ret


        
printArray:
        addi    sp, sp, -8
        sw      ra, 4(sp)
        sw      a0, 0(sp)
        li      a1, 0
        j       print_for

print_for:
        bge     a1, t0, exit1
        slli    t1, a1, 2
        add     t1, a0, t1
        lw      t2, 0(t1)
        mv      t0, a0
        mv      t1, a1

        mv      a1, t2
        li      a0, 1
        ecall
        
        la      a1, space
        li      a0, 4
        ecall

        mv      a0, t0
        mv      a1, t1
        lw      t0, N
        addi    a1, a1, 1
        j       print_for