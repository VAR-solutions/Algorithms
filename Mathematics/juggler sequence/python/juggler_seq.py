
import math 
  
#This function prints the juggler Sequence 
# contributed by Nikita Tiwari


def printJuggler(n) : 
    a = n 
      
    # print the first term 
    print a, 
      
    # calculate terms until last term is not 1 
    while (a != 1) : 
        b = 0
          
        # Check if previous term is even or odd 
        if (a%2 == 0) : 
              
            # calculate next term 
            b  = (int)(math.floor(math.sqrt(a))) 
   
        else : 
            # for odd previous term calculate 
            # next term 
            b = (int) (math.floor(math.sqrt(a)*math.sqrt(a)*
                                         math.sqrt(a))) 
   
        print b, 
        a = b 
  
printJuggler(3) 
print
printJuggler(9) 
