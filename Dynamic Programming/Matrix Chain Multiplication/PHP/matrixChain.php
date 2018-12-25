<?php  

function MatrixChainOrder(&$p, $i, $j) 
{ 
    if($i == $j) 
        return 0; 
    $min = PHP_INT_MAX; 
    for ($k = $i; $k < $j; $k++) 
    { 
        $count = MatrixChainOrder($p, $i, $k) + MatrixChainOrder($p, $k + 1, $j) + $p[$i - 1] * $p[$k] * $p[$j]; 
  
        if ($count < $min) 
            $min = $count; 
    } 
    return $min; 
} 
  
$arr = array(1, 2, 3, 4, 3); 
$n = sizeof($arr); 
  
echo "Minimum number of multiplications is " . MatrixChainOrder($arr, 1, $n - 1); 

?> 
