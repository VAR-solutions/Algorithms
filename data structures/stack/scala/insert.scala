import scala.collection.mutable.Stack 
  
// Creating object 
object GfG 
{ 
      
    // Main method 
    def main(args:Array[String]) 
    { 
  
        var s = Stack[Int]() 
      
        // pushing values 
        // one at a time 
        s.push(5) 
        s.push(1) 
        s.push(2) 
        println("s:" + s) 
  
        var s2 = Stack[Int]() 
  
        // pushing multiple values 
        s2.push(5,1,2) 
        println("s2:" + s2) 
      
    } 
} 
