num = raw_input("enter the number")
dig = [int(x) for x in num[::-1]]
n = len(dig)
cur = ans = 0
for i,x in enumerate(dig):
	ans += cur*x + (10**i if x>=6 else 0) - (10**i-int(num[n-i:])-1 if x==6 and i>0 else 0)
	cur = cur*10 + 10**i
print ans
