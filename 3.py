#!/usr/bin/python
def main():	
	n,k = raw_input().split()
	n,k = int(n),int(k)
	array = raw_input().split()
	array = [int(x) for x in array]
	count = 0
	hashmap = {}
	for num in  array:
		hashmap[num] = 'True'
	for num in array:
		if hashmap.has_key(num-k):
			count = count+1
	return count
if __name__=='__main__':
	res = main()
	print(res)
 