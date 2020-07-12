 Java Program to find root of an  
 equations using secant method 
class GFG { 
      
     function takes value of x and  
     returns f(x) 
    static float f(float x) { 
          
         we are taking equation  
         as x^3+x-1 
        float f = (float)Math.pow(x, 3)  
                               + x - 1; 
                                 
        return f; 
    } 
      
    static void secant(float x1, float x2, 
                                float E) { 
          
        float n = 0, xm, x0, c; 
        if (f(x1)  f(x2)  0)  
        { 
            do { 
                  
                 calculate the intermediate 
                 value 
                x0 = (x1  f(x2) - x2  f(x1)) 
                             (f(x2) - f(x1)); 
          
                 check if x0 is root of 
                 equation or not 
                c = f(x1)  f(x0); 
          
                 update the value of interval 
                x1 = x2; 
                x2 = x0; 
          
                 update number of iteration 
                n++; 
          
                 if x0 is the root of equation  
                 then break the loop 
                if (c == 0) 
                    break; 
                xm = (x1  f(x2) - x2  f(x1))  
                             (f(x2) - f(x1)); 
                              
                 repeat the loop until the  
                 convergence  
            } while (Math.abs(xm - x0) = E);  
                                                  
            System.out.println(Root of the + 
                     given equation= + x0); 
                      
            System.out.println(No. of 
                      + iterations =  + n); 
        }  
          
        else
            System.out.print(Can not find a
              +  root in the given inteval); 
    } 
      
     Driver code 
    public static void main(String[] args) { 
          
         initializing the values 
        float x1 = 0, x2 = 1, E = 0.0001f; 
        secant(x1, x2, E); 
    } 
} 
  