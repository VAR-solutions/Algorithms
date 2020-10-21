object Fibonacci {
    @JvmStatic
    fun main(args: Array<String>) {
        println(fibonacci(15))
    }

    fun fibonacci(n: Int): Int {
        if (n == 0) return 0 // base case
        val f = IntArray(2)
        f[0] = 1
        f[1] = 1
        for (i in 2..n) {
            f[i % 2] = f[0] + f[1]
        }

        return f[(n + 1) % 2]
    }
}