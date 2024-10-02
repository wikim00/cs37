# File:	project4.asm
# Purpose:	create for loop that will print every other capital letter in alphabet
# Author:	William Kim

               .data                      
newline: .asciiz "\n"              

        .text                      
        .globl main               

# main program
main:                              
        li $t0, 65                 # Load ASCII value of 'A' (65) into $t0
        li $t1, 0                  # create a counter for letters

#for loop that prints
print_loop:                        
        beq $t1, 13, exit_loop      # If counter reaches 13, exit the loop (last letter 'Z')

        # Print the current letter
        move $a0, $t0              # Move current letter into $a0
        li $v0, 11                 # Load syscall code to print
        syscall                     # syscall to print

        # adding spaces
        li $a0, ' '                # Load space character into $a0
        li $v0, 11                 # Load syscall code
        syscall                     # Print the space

        # Update for the next iteration
        addi $t0, $t0, 2           # jump to next capital letter
        addi $t1, $t1, 1           # Increment the counter
        j print_loop               # Jump back to the start of the loop

exit_loop:                        # Exit point of the loop
        li $a0, 10                 # Load ASCII value
        li $v0, 11                 # Load syscall code
        syscall                     # Print the newline

        li $v0, 10                 # Load syscall code for exit
        syscall                     # Exit the program
