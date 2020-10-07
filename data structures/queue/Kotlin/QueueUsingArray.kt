class QueueUsingArray (list:MutableList<Any>){

    var items:MutableList<Any> = list

    fun isEmpty():Boolean = items.isEmpty()

    fun size():Int = items.count()

    override  fun toString() = items.toString()

    fun enqueue(element:Any){
        items.add(element)
    }

    fun dequeue():Any?{
        if (this.isEmpty()){
            return null
        } else {
            return items.removeAt(0)
        }
    }

    fun peek():Any?{
        return items[0]
    }
}

fun main(args: Array<String>) {
    var a = QueueUsingArray(mutableListOf("one",2,3,"four"))

    println(a.enqueue(7))
    println(a)
    println(a.dequeue())
    println(a)
    println(a.peek())
    println(a)
    println(a.size())
    println(a.isEmpty())
}