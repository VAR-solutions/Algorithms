
"""
Says if the year is a leap or common one
"""
year = int(input("Please type a year"))
if (year%4 == 0 and year%100!= 0) or year%400 == 0:
    print("Leap year")
else:
    print("Common year")