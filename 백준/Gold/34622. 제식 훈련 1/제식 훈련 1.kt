fun main() {
    val arr = readInts()
    val n = arr[0]
    val m = arr[1]
    val d = arr[2]
    val e = arr[3]
    val x = arr[4]
    val y = arr[5]

    val ans = mutableListOf<IntArray>()
    if (x >= 0 && y >= 0) {
        ans += intArrayOf(1, 1, x + e)
        ans += intArrayOf(2, 1, y + e)
        ans += intArrayOf(2, 2, e)
    } else if (x >= 0 && y <= 0) {
        ans += intArrayOf(1, 2, x + e)
        ans += intArrayOf(2, 2, d - y)
        ans += intArrayOf(2, 1, e)
    } else if (x <= 0 && y >= 0) {
        ans += intArrayOf(2, 1, d - x)
        ans += intArrayOf(1, 1, y + e)
        ans += intArrayOf(1, 2, e)
    } else {
        ans += intArrayOf(2, 2, d - x)
        ans += intArrayOf(1, 2, d - y)
        ans += intArrayOf(1, 1, e)
    }
    val realans = ans.filter { it[2] != 0 }
    println(realans.size)
    realans.forEach { println(it.joinToString(" ")) }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }