n = int(raw_input("enter n: "))
l = [[(1,1)],[(2,1)],[(3,1)]]
cur = 4
while cur<=n:
	high = 0
	for i in l[0]:
		if i[0]>high:
			high = i[0]
	new = [(2*high,high)]
	for i in l[2]:
		flag = 0
		ind = 0
		while ind<len(new):
			item = new[ind]
			if item[0]<i[0] and item[1]<=i[1]:
				del new[ind]
			elif item[0]>=(i[0]+i[1]) and item[1]>=i[1]:
				flag = 1
				break
			else:
				ind+=1
		if flag==0:
			new = new+[(i[0]+i[1],i[1])]
	l[0] = l[1]
	l[1] = l[2]
	l[2] = new
	possible = [x[0] for x in new]
	print cur," - ",max(possible)
	cur+=1