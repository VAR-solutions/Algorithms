fun quicksort(items:List<Int>):List<Int>{
    if (items.count() < 2){
        return items
    }
    val pivot = items[items.count()/2]

    val equal = items.filter { it == pivot }
//    println("pivot value is : "+equal)

    val less = items.filter { it < pivot }
//    println("Lesser values than pivot : "+less)

    val greater = items.filter { it > pivot }
//    println("Greater values than pivot : "+greater)

    return quicksort(less) + equal + quicksort(greater)
}
fun main(args: Array<String>) {
    println("\nOriginal list:")
    val numbers = listOf<Int>(2, 4, 7, 3, 6, 9, 5, 1, 0)
    println(numbers)
    println("\nOrdered list:")
    val ordered =  quicksort(numbers)
    println(ordered)
}
