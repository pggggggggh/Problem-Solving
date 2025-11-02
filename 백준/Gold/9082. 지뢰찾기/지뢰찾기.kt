fun main() {
    repeat(readInt()) {
        val n = readInt()
        val a = readln().map { it - '0' }
        val s = readln()

        listOfNotNull(
            s,
            if (s.first() == '#') '*' + s.drop(1) else null
        ).mapNotNull { cur ->
            val curS = cur.toMutableList()
            for (i in 1 until n) {
                if (curS[i] == '#') {
                    when (curS.slice(maxOf(0, i - 2)..i).count { it == '*' }) {
                        a[i - 1] - 1 -> curS[i] = '*'
                        a[i - 1] -> curS[i] = '.'
                    }
                }
            }
            if (curS.indices.all {
                    curS.slice(maxOf(0, it - 1)..minOf(n - 1, it + 1)).count { it == '*' } == a[it]
                }) {
                curS.count { it == '*' }
            } else null
        }.maxOrNull().also { println(it) }
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }