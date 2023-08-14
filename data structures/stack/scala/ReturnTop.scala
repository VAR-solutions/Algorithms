import scala.collection.mutable.Stack 
  
// Creating object 
object GfG 
{ 
      
    // Main method 
    def main(args:Array[String]) 
    { 
  
        var s = Stack[Int]() 
  
        s.push(5) 
        s.push(1) 
        s.push(2) 
        println(s) 
        println("Top: " + s.top) 
        println("Popped:" + s.pop) 
        println("Top: " + s.top) 
    } 
} 
