# William Kim
# Ch9Q2
# CS40A

.data
prompt: .asciiz "Enter a number from 0 to 15: "
output: .asciiz "Your number in hexadecimal is: "
hex_values: 
    .asciiz "0x0"
    .asciiz "0x1"
    .asciiz "0x2"
    .asciiz "0x3"
    .asciiz "0x4"
    .asciiz "0x5"
    .asciiz "0x6"
    .asciiz "0x7"
    .asciiz "0x8"
    .asciiz "0x9"
    .asciiz "0xa"
    .asciiz "0xb"
    .asciiz "0xc"
    .asciiz "0xd"
    .asciiz "0xe"
    .asciiz "0xf"
invalid_message: .asciiz "Invalid input! Please enter a number from 0 to 15.\n"

.text
.globl main

main:
    li $v0, 4              
    la $a0, prompt         
    syscall

    li $v0, 5              
    syscall
    move $t0, $v0          

    blt $t0, 0, invalid_input 
    bgt $t0, 15, invalid_input 

    la $t1, hex_values      
    sll $t2, $t0, 2         
    add $t1, $t1, $t2       

    li $v0, 4               
    la $a0, output          
    syscall

    li $v0, 4               
    move $a0, $t1           
    syscall

    li $v0, 10              
    syscall

invalid_input:
    li $v0, 4               
    la $a0, invalid_message  
    syscall
    j main                  
