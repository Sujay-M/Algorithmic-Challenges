num = raw_input("enter the number")
dig = [int(x) for x in num[::-1]]
n = len(dig)
cur = ans = 0
add = 45
for i,x in enumerate(dig):
	right = int(num[n-i:]) if i>0 else 0
	ans += cur*x + (10**i)*(x*(x-1)/2) + x*(right+1 if right>=0 else 0)
	cur = cur*10+(add*10**i)
	print ans
print ans