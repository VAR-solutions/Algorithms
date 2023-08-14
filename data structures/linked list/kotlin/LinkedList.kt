class Node<T>(value: T){
    var value:T = value
    var next: Node<T>? = null
    var previous:Node<T>? = null
}
class LinkedList<T> {
    private var head:Node<T>? = null
    var isEmpty:Boolean = head == null
    fun first():Node<T>? = head
    fun last(): Node<T>? {
            var node = head
            if (node != null){
                while (node?.next != null) {
                    node = node?.next
                }
                return node
            } else {
                return null
            }
    }
    fun count():Int {
        var node = head
        if (node != null){
            var counter = 1
            while (node?.next != null){
                node = node?.next
                counter += 1
            }
            return counter
        } else {
            return 0
        }
    }
    fun nodeAtIndex(index: Int) : Node<T>? {
        if (index >= 0) {
            var node = head
            var i = index
            while (node != null) {
                if (i == 0) return node
                i -= 1
                node = node.next
            }
        }
        return null
    }
    fun append(value: T) {
        var newNode = Node(value)
        var lastNode = this.last()
        if (lastNode != null) {
            newNode.previous = lastNode
            lastNode.next = newNode
        } else {
            head = newNode
        }
    }
    fun removeAll() {
        head = null
    }
    fun removeNode(node: Node<T>):T {
        val prev = node.previous
        val next = node.next
        if (prev != null) {
            prev.next = next
        } else {
            head = next
        }
        next?.previous = prev
        node.previous = null
        node.next = null
        return node.value
    }
    fun removeLast() : T? {
        val last = this.last()
        if (last != null) {
            return removeNode(last)
        } else {
            return null
        }
    }
    fun removeAtIndex(index: Int):T? {
        val node = nodeAtIndex(index)
        if (node != null) {
            return removeNode(node)
        } else {
            return null
        }
    }
    override fun toString(): String {
        var s = "["
        var node = head
        while (node != null) {
            s += "${node.value}"
            node = node.next
            if (node != null) { s += ", " }
        }
        return s + "]"
    }
}
fun main(args: Array<String>) {
    var ll = LinkedList<String>()
    ll.append("John")
    println(ll)
    ll.append("Carl")
    println(ll)
    ll.append("Zack")
    println(ll)
    ll.append("Tim")
    println(ll)
    ll.append("Steve")
    println(ll)
    ll.append("Peter")
    println(ll)
    print("\n\n")
    println("first item: ${ll.first()?.value}")
    println("last item: ${ll.last()?.value}")
    println("second item: ${ll.first()?.next?.value}")
    println("penultimate item: ${ll.last()?.previous?.value}")
    println("\n4th item: ${ll.nodeAtIndex(3)?.value}")
    println("\nthe list has ${ll.count()} items")
}
