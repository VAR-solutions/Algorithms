fun <T:Comparable<T>>linearSearch(list:List<T>, key:T):Int?{
    for ((index, value) in list.withIndex()) {
        if (value == key) return index
    }
    return null
}

fun main(args: Array<String>) {
    println("\nOrdered list:")
    val ordered = listOf<String>("nik", "ruddof", "alisa", "shashi", "varun")
    println(ordered)
    val name = "shashi"
    val position = linearSearch(ordered, name)
    println("\n${name} is in the position ${position} in the ordered List.")
}
