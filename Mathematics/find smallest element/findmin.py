""" The program will ask how many numbers do you wish to compare, then ask for the numbers, 
put them into a list and show the smallest number of the list"""

n = int(input("How many numbers do you wish to compare? "))
count=0
numbers_list = []
while (count<n):
	x = int(input("Type a number: "))
	numbers_list.append(x)
	count+=1

numbers_list.sort()
print("Smallest element is: ", *numbers_list[:1]) 