.data
strPromptFirst: .asciiz "Enter an integer value n:"
strResult: .asciiz "Sum is: "
strCR: .asciiz "\n"

.text
.global main

main:
    # STEP 1 -- get the first operand
    # Print a prompt asking user for input
    li $v0, 4              # syscall number 4 will print string whose address is in $a0
    la $a0, strPromptFirst  # load address of the string
    syscall                 # actually print the string

    # Now read in the first operand
    li $v0, 5              # syscall number 5 will read an int
    syscall                 # actually read the int
    move $s0, $v0          # save result in $s0 for later

    # STEP 2 -- Call the function to calculate the sum
    move $a0, $s0          # move the input integer n to register $a0
    jal sum                # jump to the function sum to calculate the sum
    move $s1, $v0          # move the final sum value to register $s1

    # STEP 3 -- print the sum
    # First print the string prelude
    li $v0, 4              # syscall number 4 -- print string
    la $a0, strResult      # address of string
    syscall                 # actually print the string

    # Then print the actual sum
    li $v0, 1              # syscall number 1 -- print int
    move $a0, $s1          # put the result in $a0 for print
    syscall                 # actually print the int

    # STEP 4 --
    # Finally print a carriage return
    li $v0, 4              # syscall for print string
    la $a0, strCR          # address of string with a carriage return
    syscall                 # actually print the string

    # STEP 5 -- exit
    li $v0, 10             # syscall number 10 is to terminate the program
    syscall                 # exit now

# Sum Function
sum:
    # Input: $a0 = n (the integer to sum up to)
    # Output: $v0 = sum of integers from 1 to n
    move $v0, $zero        # Initialize sum to 0
    move $t0, $zero        # Initialize counter to 0

    # Loop from 1 to n
loop:
    addi $t0, $t0, 1       # Increment counter
    add $v0, $v0, $t0      # Add counter to sum
    bne $t0, $a0, loop     # Repeat until counter equals n

    jr $ra                  # Return to caller
