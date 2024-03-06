

max:
	# $a0 = int array[] = &array[0]
	# $a1 = int length
	push	$ra
	push	$s0
max_body: 
	# first element = $t0 = 2
	lw	$s0, ($a0)

max_body_if:
	bne	$a1, 1, max_body_else

	move	$v0, $s0

	b 	max_epilogue
max_body_else:
	addi	$a0, 4
	addi	$a1, -1

	jal	max

	# max_so_far = $t1
	move	$t1, $v0

max_body_else_if:
	ble	$s0, $t1, max_body_else_if_end

	move	$t1, $s0

max_body_else_if_end:

	move	$v0, $t1

	b	max_epilogue
max_body_if_end:

max_epilogue:
	pop	$s0
	pop	$ra
	
	jr	$ra