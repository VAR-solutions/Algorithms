<?php 
// PHP program for Fibonacci Series using Space Optimized Method 
  
function fib( $n) 
{ 
    $a = 0;  
    $b = 1;  
    $c; 
    $i; 
    if( $n == 0) 
        return $a; 
    for($i = 2; $i <= $n; $i++) 
    { 
        $c = $a + $b; 
        $a = $b; 
        $b = $c; 
    } 
    return $b; 
} 

$n = 9; 
echo fib($n); 
?> 
