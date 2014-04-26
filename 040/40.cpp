/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000

We can solve with pen & paper

Number Range		Digits Range
1 - 9				1 - 9
10 - 99				10 - 189
100 - 999			190 - 2889
1000 - 9999			2890 - 38889
10000 - 99999		38890 - 488889
100000 - 999999		488890 - 5888889

d1 =		1
d10 =		1

To find the rest, we will do the following:
for 100: The 100th digit lies within the 10 - 99 range
The 10 to 99 range starts with the 10th digit so we need to find the (100 - 9) = 91st digit in the 10 - 99 range

each number in this range has 2 digits so we need to add the number 45 1/2 to our previous range max

9 + (45 1/2) = 54 1/2 

the numerator of the fraction determines which digit of the next number is the one we are looking for. 
No fraction means take the last digit of the current number. This gives

d100 =		5

Continuing in the same manner:
d1000 =		3
d10000 =	7
d100000 =	2
d1000000 =	1

and their product is 1*1*5*3*7*2*1 = 210
 */