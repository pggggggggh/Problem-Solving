import java.util.PriorityQueue

const val INF = Double.MAX_VALUE / 4

fun main() {
    val (n, m, q) = readInts()
    val adj = Array(n + 1) { mutableListOf<Pair<Int, Double>>() } // 1-indexed

    repeat(m) {
        // 튼튼한 토큰화 사용
        val tok = readStrings()
        val u = tok[0].toInt()
        val v = tok[1].toInt()
        val w = tok[2].toDouble()
        adj[v] += u to w // 역방향 (c에서 다익스트라)
    }

    repeat(q) { idx ->
        val (s, k) = readInts() // s: crime location, k: cars
        val es = readKInts(k)   // k개를 정확히 모을 때까지 읽기

        val dist = DoubleArray(n + 1) { INF }
        val pq = PriorityQueue<Pair<Int, Double>>(compareBy { it.second })
        dist[s] = 0.0
        pq += s to 0.0

        while (pq.isNotEmpty()) {
            val (u, d) = pq.poll()
            if (dist[u] != d) continue
            for ((v, cost) in adj[u]) {
                val nd = d + cost
                if (nd < dist[v]) {
                    dist[v] = nd
                    pq += v to nd
                }
            }
        }

        println("Scenario ${idx + 1}:")
        val best = es.fold(INF) { acc, x -> minOf(acc, dist[x]) }
        println(
            best.takeIf { it != INF }?.let { String.format("%.2f", it) } ?: "Impossible."
        )
        println()
    }
}

/*** robust input helpers ***/
private fun readStrings(): List<String> {
    var line = readlnOrNull()
    // 빈 줄이 올 수 있으므로 스킵
    while (line != null && line.isBlank()) line = readlnOrNull()
    if (line == null) return emptyList()
    return line.trim().split(Regex("\\s+"))
}
private fun readInts(): List<Int> = readStrings().map { it.toInt() }

private fun readKInts(k: Int): List<Int> {
    val res = ArrayList<Int>(k)
    while (res.size < k) {
        val toks = readStrings()
        for (t in toks) {
            res += t.toInt()
            if (res.size == k) break
        }
    }
    return res
}