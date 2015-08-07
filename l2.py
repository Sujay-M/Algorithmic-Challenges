l = raw_input("enter numbers\n").split()
nums = [int(x) for x in l]
large = 0
second_large = 0
for i in nums:
	if(i>second_large):
		if i>large:
			second_large = large
			large = i
		else:
			second_large = i
print("large = ",large)
print("second_large = ",second_large)