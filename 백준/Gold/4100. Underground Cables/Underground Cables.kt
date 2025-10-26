import kotlin.math.hypot

class DSU(val n: Int) {
    val par = MutableList<Int>(n) { it }
    val sz = MutableList<Int>(n) { 1 }

    fun find(x: Int): Int = if (par[x] == x) x else find(par[x]).also { par[x] = it }

    fun union(x: Int, y: Int) {
        var i = find(x)
        var j = find(y)
        if (i == j) return
        if (sz[i] < sz[j]) i = j.also { j = i }
        par[j] = i
        sz[i] += sz[j]
    }
}

fun main() {
    while (true) {
        val n = readInt()
        if (n == 0) break
        val a = Array(n) { readDoubles().let { it[0] to it[1] } }

        data class Edge(val u: Int, val v: Int, val w: Double)

        val e = mutableListOf<Edge>()
        for (i in 0 until n) {
            for (j in i + 1 until n) {
                e += Edge(i, j, hypot(a[i].first - a[j].first, a[i].second - a[j].second))
            }
        }
        e.sortBy { it.w }
        val uf = DSU(n + 1)
        var ans = 0.0
        for ((u, v, w) in e) {
            if (uf.find(u) == uf.find(v)) continue;
            uf.union(u, v)
            ans += w
        }
        println("%.2f".format(ans))
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }