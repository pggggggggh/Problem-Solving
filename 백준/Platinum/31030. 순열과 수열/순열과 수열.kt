fun main() {
    val n = readInt()
    val a = listOf(0) + readInts()
    val b = listOf(0) + readInts()
    val vis = BooleanArray(n + 1)
    val cycles = mutableListOf<MutableList<Int>>()
    for (i in 1..n) {
        if (vis[i]) continue
        val cycle = mutableListOf<Int>()
        var cur = i
        while (true) {
            if (vis[cur]) break
            vis[cur] = true
            cur = a[cur]
            cycle += cur
        }
        cycles += cycle
    }
    var ans = 0L
    for (cycle in cycles) {
        var mx = 0L
        for (i in 1..n) {
            var cur = i
            var cursum = 0L
            for (x in cycle) {
                cursum += cur.toLong() * b[x]
                cur = a[cur]
            }
            if (cur == i)
                mx = maxOf(mx, cursum)
        }
        ans += mx
    }
    print(ans)
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }