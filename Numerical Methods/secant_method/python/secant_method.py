class SecantMethod:

    def __init__(self, function_, initial_guess_1, initial_guess_2, tol, max_steps):
        self.function = function_
        self.x_2 = initial_guess_1
        self.x_1 = initial_guess_2
        self.tolerance = tol
        self.maxSteps = max_steps

    def secant_method(self):

        
        #VARIABLES INITIALIZE GUESSES FOR X1 AND X2
        x1=self.x_1
        x2=self.x_2

        #EVALUATE X1 AT F(X1)
        fx1=self.function(x1)
        
        #INITIALIZE DELTA VARIABLE FOR LATER USE. THIS VARIABLE WILL REFER TO THE FUNCTION DELTA_X
        deltax = 0
       
        #ITERATE OVER DATA UNTIL VALUE CONVERGES
        for i in range(self.maxSteps):

            #EVALUATE X2 AT F(X2)
            fx2 = self.function(x2)
            
            #EVALUATE DELTA_X
            deltax = self.delta_x(fx2,fx1,x2,x1)

            #PRINT ON TERMINAL APPROXIMATED VALUE
            print("root_apprx= ",x2)
            
            #EXCHANGE POINT POSITIONS. 
            #MAKE X2 EQUAL TO X1
            #MAKE F(X2) EQUAL F(X1)
            #MAKE X2 EQUAL TO X2 - DELTAX
            x1 = x2
            fx1 = fx2
            x2 = x2-deltax

            #IF THE ABSOLUTE VALUE OF DELTA_X IS LESS THAN THE TOLERANCE
            #VALUE HAS BEEN FOUND
            if(abs(deltax) < self.tolerance):
                return x2


    # calculates (f2/f2-1)(x2-x1)
    def delta_x(self,f2,f1,x2,x1):
        #WATCH FOR DIVISION BY ZERO
        if((f2-f1)*(x2-x1) == 0):
            print("Division by zero")
            exit(0)
        else:
            return(f2/(f2-f1))*(x2-x1)
