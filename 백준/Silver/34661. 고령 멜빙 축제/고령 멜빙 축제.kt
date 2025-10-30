fun main() {
    val t = readInt()
    repeat(t) {
        val (n, m) = readInts()
        List(n) { readln() }.fold(0) { acc, string ->
            acc + string.count { it == '.' }
        }.let { println(if (it % 2 == 1) "sewon" else "pizza") }
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }