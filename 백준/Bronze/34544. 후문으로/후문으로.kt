fun main() {
    print((1 + List(readInt()) {
        var (x, y) = readInts()
        if (x < 0) x += 1
        if (y < 0) y += 1
        y - x
    }.sum()).let {
        if (it <= 0) it - 1
        else it
    })
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }