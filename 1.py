#!/usr/bin/python

'''
counts the number of substring that are palindromes
'''
def countPalindrome(s):
	l = []
	n = len(s)
	for i in range(n):
		cur = s[i]
		l2 = []
		for j in range(i,n):
			if cur==s[j]:
				l2.append(j)
		l.append(l2)
	count = 0
	for i in range(n):
		l2 = l[i]
		for j in l2:
			sub = s[i:j+1]			
			rev = sub[::-1]			
			if sub==rev:
				count = count+1
	return count
if __name__=='__main__':
	string = str(raw_input('enter the string\n'))
	# string = 'dijid'
	palindromes = countPalindrome(string)
	print(palindromes)



	
