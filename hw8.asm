# File:	hw8.asm
# Purpose:	average of 2, 5, 8, 11
# Author:	William Kim


.data
prompt1: .asciiz "Enter the multiplicand: "
prompt2: .asciiz "Enter the multiplier: "
result: .asciiz "The answer is: "
num1: .word 2
num2: .word 5
num3: .word 8
num4: .word 11
newline: .asciiz "\n"

.text
.globl main

main:
    # Load the four numbers into argument registers $a0 - $a3
    lw $a0, num1      # Load num1 into $a0
    lw $a1, num2      # Load num2 into $a1
    lw $a2, num3      # Load num3 into $a2
    lw $a3, num4      # Load num4 into $a3

    # Call the largestAndAverage subprogram
    jal largestAndAverage

    # Print the largest value in $v0
    li $v0, 4             # Load print string syscall code
    la $a0, result        # Load the result message address
    syscall               # Print the result message

    li $v0, 1             # Load print integer syscall code
    move $a0, $v0         # Move largest value into $a0
    syscall               # Print largest number

    # Print a newline
    li $v0, 4            # Load print string syscall code
    la $a0, newline       # Load newline string address
    syscall               # Print newline

    # Print the average value in $v1
    li $v0, 1             # Load print integer syscall code
    move $a0, $v1         # Move average value into $a0
    syscall               # Print average number

    # Exit the program
    li $v0, 10            # Load exit syscall code
    syscall

# Subprogram: largestAndAverage
# Takes four numbers in $a0 - $a3 and returns the largest in $v0 and the average in $v1
largestAndAverage:
    # Save arguments on the stack
    addi $sp, $sp, -16    # Make space for 4 arguments on the stack
    sw $a0, 0($sp)        # Save $a0 on the stack
    sw $a1, 4($sp)        # Save $a1 on the stack
    sw $a2, 8($sp)        # Save $a2 on the stack
    sw $a3, 12($sp)       # Save $a3 on the stack

    # Get the largest value
    move $t0, $a0         # Move $a0 to $t0
    move $t1, $a1         # Move $a1 to $t1
    jal getLarger         # Call getLarger with $t0 and $t1
    move $s0, $v0         # Save result in $s0

    move $t0, $s0         # Move largest so far to $t0
    move $t1, $a2         # Move $a2 to $t1
    jal getLarger         # Call getLarger with $t0 and $t1
    move $s0, $v0         # Update $s0 with the result

    move $t0, $s0         # Move largest so far to $t0
    move $t1, $a3         # Move $a3 to $t1
    jal getLarger         # Call getLarger with $t0 and $t1
    move $v0, $v0         # Largest is now in $v0

    # Restore arguments from the stack
    lw $a0, 0($sp)        # Restore $a0
    lw $a1, 4($sp)        # Restore $a1
    lw $a2, 8($sp)        # Restore $a2
    lw $a3, 12($sp)       # Restore $a3
    addi $sp, $sp, 16     # Reclaim the stack space

    # Calculate the average
    add $v1, $a0, $a1     # $v1 = $a0 + $a1
    add $v1, $v1, $a2     # $v1 = $v1 + $a2
    add $v1, $v1, $a3     # $v1 = $v1 + $a3
    li $t0, 4             # Load 4 into $t0 (for division)
    div $v1, $t0          # Divide the sum by 4 to get the average
    mflo $v1              # Move quotient to $v1

    jr $ra                # Return to caller

# Subprogram: getLarger
# Compares $a0 and $a1 and returns the larger value in $v0
getLarger:
    move $v0, $a0         # Assume $a0 is the largest
    bgt $a1, $a0, set_v0  # If $a1 > $a0, update $v0 with $a1
    jr $ra                # Return to caller

set_v0:
    move $v0, $a1         # Set $v0 to $a1
    jr $ra                # Return to caller
