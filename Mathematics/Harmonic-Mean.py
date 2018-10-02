# Implementation of compution 
# of arithmetic mean, geometric mean 
# and harmonic mean 
# contributed by Nikita Tiwari
import math 

# Function to calculate arithmetic 
# mean, geometric mean and harmonic mean 
def compute( a, b) : 
	AM = (a + b) / 2
	GM = math.sqrt(a * b) 
	HM = (GM * GM) / AM 
	return HM 

a = int(input())
b = int(input())
HM = compute(a, b) 
print("Harmonic Mean between " , a, 
	" and ", b , " is " , HM ) 
