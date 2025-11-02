fun main() {
    repeat(readInt()) {
        val (k, n) = readInts()
        val a = List(n) { readInt() }
        println("${a.maxOf { minOf(it, k - it) }} ${a.maxOf { maxOf(it, k - it) }}")
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }