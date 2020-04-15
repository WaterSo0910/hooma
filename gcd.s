.data
argument1: .word 512 # Number to find the factorial value of
argument2: .word 480
str1: .string "GCD value of "
str2: .string " and "
str3: .string " is "

.text
main:
        lw       a1, argument1   # Load argument from static data
        lw       a0, argument2
        jal      ra, gcd      	 # Jump-and-link to the 'fact' label

        # Print the result to console
        mv       a2, a1
        lw       a1, argument1
        jal      ra, printResult

        # Exit program
        li       a0, 10
        ecall

gcd:	# gcd(a1,a2)
        addi     sp, sp, -24
        sw       ra, 16(sp)
		# store data
		sw       a1, 8(sp)
        sw       a0, 0(sp)
		# if a0>=1 -> call ngcd()
        addi     t0, a0, -1
        bge      t0, zero, ngcd

        addi     t0, a1, 0
        addi     sp, sp, 24
        sw       t0, 8(sp)
        ret

ngcd:
		# gcd(a0, a1)=> gcd(mod(a1,a0), a0)
        addi     t0, a0, 0
        remu     a0, a1, a0 	# a0 = mod(a1, a0) 
        addi  	 a1, t0, 0		
        jal      ra, gcd
		# gcd做完的a0, a1要load起來
		# 為了下一次ngcd使用
        lw       a0, 0(sp)
        lw       a1, 8(sp)
        lw       ra, 16(sp)
        addi     sp, sp, 24
        sw       a1, 8(sp)


        ret


# expects:
# a0: Value which factorial number was computed from
# a1: Factorial result
printResult:
        mv       t0, a0
        mv       t1, a1
        mv       t2, a2

        la       a1, str1
        li       a0, 4
        ecall

        mv       a1, t1
        li       a0, 1
        ecall

        la       a1, str2
        li       a0, 4
        ecall

        mv       a1, t0
        li       a0, 1
        ecall

		
        la       a1, str3
        li       a0, 4
        ecall

        mv       a1, t2
        li       a0, 1
		ecall

        ret