import math

def part(n):
	partition[n] = []
	partition[n].append([n])
	if n==1:
		return
	binary_summand = [[n-i,i] for i in range(1,int(math.floor(n/2))+1)]
	bin_col = [r[1] for r in binary_summand]
	for i,p in enumerate(binary_summand):
		if partition.has_key(p[0])==False:
			part(p[0])
			for sub in partition[p[0]]:
				partition[n].append(sub+[1])
		else:
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
	except: num = 30
	part(num)
	# print partition[num]
	print 'number of partions of integer ',num,'is',len(partition[num])