#!/usr/bin/python
def main():	
	n,k = raw_input().split()
	n,k = int(n),int(k)
	l = raw_input().split()
	l = [int(x) for x in l]
	l.sort(reverse=True)
	i = 0
	j = 1
	count = 0
	while(i<n):
		if j==n:
			i=i+1
			j=i+1
			continue
		if l[i]-l[j]>k:
			i=i+1
			j=i+1
			continue
		if l[i]-l[j]==k:
			count=count+1
			j=j+1
			continue
		j=j+1
	return count
if __name__=='__main__':
	res = main()
	print(res)

 