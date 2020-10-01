"This code ask for a temperature in fahrenheit degrees and convert it to celsius"

temp_far = float(input("Type the temperature in Fahrenheit: "))
temp_cel = (temp_far-32)/1.8
print('%.2f' % temp_cel, "C°")