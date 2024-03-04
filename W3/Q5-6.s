# CONSTANTS
N_SIZE = 10

.text

main:
						# 	int i = $t0
scan_loop_init:					
	li	$t0, 0				# i = 0;

scan_loop_cond:
	bge	$t0, N_SIZE, scan_loop_end	# if (i >= N_SIZE) goto scan_loop_end;

scan_loop_body:					
	li	$v0, 5				# scanf("%d", &numbers[i]);
	syscall					# 	syscall 5: scan int
						# 	calculating the address of numbers[i]
	mul	$t1, $t0, 4			# 	$t1 = 4 * i = offset bytes from the address of numbers[0]
	la	$t2, numbers			#	$t2 = &numbers = address of numbers
	add	$t2, $t1, $t2			# 	$t2 = offset + &numbers = &numbers[i]
	sw	$v0, ($t2)			#	save the scanned number in $v0 into &numbers[i]

scan_loop_incr:
	addi	$t0, $t0, 1			# i++;
	b	scan_loop_cond			# goto scan_loop_cond;

scan_loop_end:				

print_loop_init:			
	li	$t0, 0				# i = 0	

print_loop_cond:
	bge	$t0, N_SIZE, print_loop_end	# if (i >= N_SIZE) goto print_loop_end;

print_loop_body:
	mul	$t2, $t0, 4			# calculating offset
	# la	$t3, numbers	
	# add	$t4, $t3, $t2
	# sw	$t1, ($t4)
	lw	$t1, numbers($t2)		# the alternate "shortcut" way of lines 37-39

	li	$v0, 1				# printf("%d", numbers[i]);
	move	$a0, $t1
	syscall

	li	$v0, 11				# printf("\n");
	li	$a0, '\n'
	syscall

print_loop_incr:
	addi	$t0, $t0, 1			# i++;
	b	print_loop_cond			# goto print_loop_cond;

print_loop_end:

end:
	jr	$ra				# return


.data

numbers:	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0