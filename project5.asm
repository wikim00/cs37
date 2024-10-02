.data
prompt1: .asciiz "Enter an integer n: "
prompt2: .asciiz "The sum of numbers from 1 to n is: "
newline: .asciiz "\n"

.text
main:
    # Prompt the user for an integer n
    li $v0, 4
    la $a0, prompt1
    syscall

    # Read the integer n from the user
    li $v0, 5
    syscall
    move $a0, $v0

    # Call the recursive function to find the sum
    jal recursive_sum

    # Print the result
    li $v0, 4
    la $a0, prompt2
    syscall

    li $v0, 1
    move $a0, $v0
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    # Exit the program
    li $v0, 10
    syscall

recursive_sum:
    # Base case: n is 0
    beq $a0, $zero, return_zero

    # Recursive case: n is not 0
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    addi $a0, $a0, -1
    jal recursive_sum

    lw $ra, 0($sp)
    addi $sp, $sp, 4

    add $v0, $v0, $a0
    addi $v0, $v0, 1  # Add 1 to include the current value

    jr $ra

return_zero:
    move $v0, $zero
    jr $ra