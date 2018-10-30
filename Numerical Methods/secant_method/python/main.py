from secant_method import SecantMethod
from function import funct

# SECANT METHOD:

# INPUT: 
# A FUNCTION THAT TAKES ONE PARAMETER AND RETURNS A VALUE
# A VALUE FOR X2
# A VALUE FOR X1
# AN ERROR ESTIMATION
# THE MAX NUMBER OF STEPS


# OUTPUT:
# THE ROOT FOR THE DESIRED FUNTION
# .

method = SecantMethod(funct,0,3,.00001,30)
x = method.secant_method()
print(x)
