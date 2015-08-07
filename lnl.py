l = raw_input("enter numbers\n").split()
nums = [int(x) for x in l]
small = {}
out = [0]*len(nums)
cur = -1
for i,item in enumerate(nums):
	while item<cur:
		temp = cur
		cur = small[cur]
		del small[temp]
	small[item] = cur
	out[i] = cur
	cur = item
print out
