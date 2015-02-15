#!/usr/bin/python
def main():	
	n,k = raw_input().split()
	n,k = int(n),int(k)
	l = raw_input().split()
	l = [int(x) for x in l]
	res = [(x,y) for x in l for y in l if x-y==k]
	return len(res)
if __name__=='__main__':
	res = main()
	print(res)

 