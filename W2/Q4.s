# Prints the square of a number

main:
	# $t0 = x, $t1 = y
	li	$v0, 4
	la	$a0, prompt_str
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

epilogue:
	li	$v0, 0
	jr	$ra

.data

prompt_str:
	.asciiz	"Enter a number: "

# prompt_number:
# 	.ascii "Enter a number: \0"