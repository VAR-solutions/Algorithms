fun power(x,n) = 
    let
       fun poweriter(x,n,c,d) = if (c=n) then d else poweriter(x,n,c+1,d*x)
    in 
        poweriter(x,n,0,1)
    end;

fun fastpower(x,n) = if (n=0) then 1 else if n mod 2 = 0 then fastpower(x*x,n div 2) else x*fastpower(x*x,n div 2);