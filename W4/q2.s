# &flag[0][0] = &flag
# &flag[0][7] = &flag + 7
# &flag[1][0] = &flag + 12
# &flag[1][7] = &flag + 12 + 7
# &flag[2][7] = &flag + 12 + 12 + 7 = &flag + 12 * 2 +  7
# &flag[row][col] = &flag + n_col * row + col

.data
flag:	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

.text
# CONSTANTS
FLAG_ROWS = 6
FLAG_COLS = 12

main:

main_prologue:
	# everything you push

main_body:
main_loop_rows_init:
	# $t0 = row, $t1 = col
	li	$t0, 0		# int row = 0;
main_loop_rows:
	bge	$t0, FLAG_ROWS, main_loop_rows_end

	li	$t1, 0		# int col = 0;
main_loop_cols:
	bge	$t1, FLAG_COLS, main_loop_cols_end

	# $t4 = &flag[row][col] = &flag + row *n_col + col
	# $t2 = flag[row][col]
	# la	$t3, flag
	# mul	$t4, $t0, FLAG_COLS
	# add	$t4, $t4, $t1
	# add	$t4, $t4, $t3
	# lb	$t2, ($t4)
	mul	$t4, $t0, FLAG_COLS
	add	$t4, $t4, $t1
	lb	$t2, flag($t4)

	# printf("%c", flag[row][col]);
	move	$a0, $t2
	li	$v0, 11
	syscall

	addi	$t1, 1
	b	main_loop_cols

main_loop_cols_end:
	li	$a0, '\n'
	li	$v0, 11
	syscall

	addi	$t0, 1
	b	main_loop_rows
main_loop_rows_end:

main_epilogue:
	# everything you pop

	li	$v0, 0
	jr	$ra
