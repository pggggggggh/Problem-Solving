fun main() {
    repeat(readInt()) {
        val (a, b) = readStrings()
        val aidx = a.indices.filter { a[it] == 'b' }
        val bidx = b.indices.filter { b[it] == 'b' }
        println(aidx.zip(bidx).sumOf { (x, y) -> kotlin.math.abs(x - y) })
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }