class StackUsingArray(size:Int){
    private var stackSize = size;
    private var stackArr = IntArray(stackSize);
    private var top = -1;

    fun push(entry: Int) {
        if (this.isStackFull()) {
            println("Stack is full. Increasing the capacity.")
            this.increaseStackCapacity()
        }

        top += 1
        println("Adding: $entry")
        this.stackArr[top] = entry
    }

    fun pop(): Any {
        if (this.isStackEmpty()) {
            throw Exception("Stack is empty. Can not remove element.")
        }
        var entry = this.stackArr[top--]
        println("Removed entry: $entry")
        return entry
    }

    fun size(): Any {
        return top+1
    }
    fun peek(): Any {
        return stackArr[top]
    }

    private fun increaseStackCapacity() {
        val newStack = IntArray(this.stackSize * 2)
        for (i in 0 until stackSize) {
            newStack[i] = this.stackArr[i]
        }
        this.stackArr = newStack
        this.stackSize = this.stackSize * 2
    }

    fun isStackEmpty(): Boolean {
        return top == -1
    }
    private fun isStackFull(): Boolean {
        return top == stackSize - 1
    }
}

fun main(args: Array<String>) {
    val stack = StackUsingArray(2)
    stack.push(1)
    stack.push(7)
    println("is stack empty : " + stack.isStackEmpty())
    println("size of stack : " + stack.size())
    println("peek : " + stack.peek())
}