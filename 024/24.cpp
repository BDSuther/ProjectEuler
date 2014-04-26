/*A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

We can do this with pen and paper we need to do 999999 more permutations from the initial 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

9! is 362880	999999 - 2*9!	= 274239		2, 0, 1, 3, 4, 5, 6, 7, 8, 9
8! is 40320		274239 - 6*8!	= 32319			2, 7, 0, 1, 3, 4, 5, 6, 8, 9
7! is 5040		32319 - 6*7!	= 2079			2, 7, 8, 0, 1, 3, 4, 5, 6, 9
6! is 720		2079 - 2*6!		= 639			2, 7, 8, 3, 0, 1, 4, 5, 6, 9
5! is 120		639 - 5*5!		= 39			2, 7, 8, 3, 9, 0, 1, 4, 5, 6
4! is 24		39 - 1*4!		= 15			2, 7, 8, 3, 9, 1, 0, 4, 5, 6
3! is 6			15 - 2*3!		= 3				2, 7, 8, 3, 9, 1, 5, 0, 4, 6
2! is 2			3 - 1*2!		= 1				2, 7, 8, 3, 9, 1, 5, 4, 0, 6
1! is 1			1 - 1*1!		= 0				2, 7, 8, 3, 9, 1, 5, 4, 6, 0

so the 1000000th permutation is 2783915460
*/