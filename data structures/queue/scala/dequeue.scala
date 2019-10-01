scala> val next = q.dequeue
next: String = apple

// 'apple' is removed from the queue
scala> q
res0: scala.collection.mutable.Queue[String] = Queue(kiwi, banana, cherry, coconut, pineapple)

// take the next element
scala> val next = q.dequeue
next: String = kiwi

// 'kiwi' is removed from the queue
scala> q
res1: scala.collection.mutable.Queue[String] = Queue(banana, cherry, coconut, pineapple)
