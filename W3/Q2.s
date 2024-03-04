


main:
	la	$t1, d		# print one byte across from d:
	lb	$t0, 1($t1)
	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 0		# return;
	jr	$ra


    .data
a:  .word   42
b:  .space  4
c:  .asciiz "abcde"
    .align  2
d:  .byte   1, 2, 3, 4
e:  .word   1, 2, 3, 4
f:  .space  1