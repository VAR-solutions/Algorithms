<?php  
   ini_set("sendmail_from", "sonoojaiswal@javatpoint.com");  
   $to = "sonoojaiswal1987@gmail.com";//change receiver address  
   $subject = "This is subject";  
   $message = "This is simple text message.";  
   $header = "From:sonoojaiswal@javatpoint.com \r\n";  
  
   $result = mail ($to,$subject,$message,$header);  
  
   if( $result == true ){  
      echo "Message sent successfully...";  
   }else{  
      echo "Sorry, unable to send mail...";  
   }  
?>  
