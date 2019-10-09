scala> import scala.collection.mutable.Queue
import scala.collection.mutable.Queue

// create an empty queue
scala> var q = new Queue[String]
q: scala.collection.mutable.Queue[String] = Queue()

// add elements to the queue in the usual ways
scala> var q = new Queue[String]
q: scala.collection.mutable.Queue[String] = Queue()

scala> q += "apple"
res0: scala.collection.mutable.Queue[String] = Queue(apple)

scala> q += ("kiwi", "banana")
res1: scala.collection.mutable.Queue[String] = Queue(apple, kiwi, banana)

scala> q ++= List("cherry", "coconut")
res2: scala.collection.mutable.Queue[String] = Queue(apple, kiwi, banana, cherry, coconut)

// can also use enqueue
scala> q.enqueue("pineapple")

scala> q
res3: scala.collection.mutable.Queue[String] = Queue(apple, kiwi, banana, cherry, coconut, pineapple)
