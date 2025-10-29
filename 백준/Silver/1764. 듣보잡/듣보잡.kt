fun main() {
    val (n, m) = readInts()
    val a = mutableListOf<String>()
    repeat(n) { a += readLine()!! }
    val s = mutableSetOf<String>()
    repeat(m) { s += readLine()!! }

    a.filter { it in s }.sortedBy { it }.also {
        println(it.size)
        println(it.joinToString("\n"))
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }