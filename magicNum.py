import math
#recursive
def magic(num):
	if num==0:
		return 0
	n = int(math.log(num,2))
	return (5**(n+1))+magic(num-(2**n))
num = int(raw_input("enter the number :"))
#out = magic(num)
#print out
#iterative
out1 = 0
while(num!=0):
	n =  int(math.log(num,2))
	out1 += 5**(n+1)
	num -= 2**n
print out1
