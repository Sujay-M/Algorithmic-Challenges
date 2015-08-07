import math
def part(num):
	for n in range(1,num+1):
		partition[n] = []
		partition[n].append([n])
		if n==1:
			continue
		binary_summand = [[n-i,i] for i in range(1,int(math.floor(n/2))+1)]
		bin_col = [r[1] for r in binary_summand]
		for i,p in enumerate(binary_summand):
			for sub1 in partition[p[0]]:
				if not any(value in sub1 for value in bin_col[0:i]):
					partition[n].append(sub1+[p[1]])
					for sub2 in partition[p[1]][1:]:
						if not any(value in sub2 for value in bin_col[0:i]):
							partition[n].append(sub1+sub2)
partition = {}
if __name__=='__main__':
	import sys
	try: num = sys.argv[1]
	except: num = 10
	part(num)
	print 'number of partions of integer ',num,'is',len(partition[num])