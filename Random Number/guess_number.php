<?php

$number= $_POST['number'];

$submit = $_POST['submit'];


$randomNumber= mt_rand(1,10);


?>


<form action="" method="POST">
Guess a Number Between 1 and 10: 
<input type="text" name="number" value='9'/> <br><br>

Result: 
<?php 
if ($submit){

if (($number > 0) && ($number <11)){
if ($number != $randomNumber)
{
echo "Incorrect guess. The correct number was $randomNumber. Try again";
}
else 
{
echo "$randomNumber is the correct guess. You got it right.";
}
}

}

?>
<br><br>
<input type="submit" name="submit" value="submit"/><br><br>
</form>
