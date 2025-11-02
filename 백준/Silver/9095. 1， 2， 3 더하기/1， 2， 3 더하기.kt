fun main() {
    val dp = IntArray(12)
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    for (i in 3..11) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    repeat(readInt()) { println(dp[readInt()]) }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }