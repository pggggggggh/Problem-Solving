fun main() {
    val (a, b, n, k) = readInts()
    val sode = (k + n - 1) / n
    val jungde = (sode + b - 1) / b
    print("$jungde ${sode - (jungde - 1) * b}")
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }