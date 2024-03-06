



main:
main_prologue:
	push	$ra
main_body:

	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4

	move	$t0, $v0

	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 0

main_epilogue:
	pop	$ra
	jr	$ra

sum4:
sum4_prologue:

	push	$ra
	push	$s0
	push	$s1
	push	$s2
	push	$s3
sum4_body:
	move	$s2, $a2
	move	$s3, $a3

	jal	sum2
	move	$s0, $v0

	move	$a0, $s2
	move	$a1, $s3
	jal	sum2
	move	$s1, $v0

	move	$a0, $s0
	move	$a1, $s1
	jal	sum2

sum4_epilogue:
	pop	$s3
	pop	$s2
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra


sum2:
	add	$v0, $a0, $a1
	jr	$ra