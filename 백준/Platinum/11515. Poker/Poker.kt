enum class Suit {
    C, D, H, S
}

enum class HandType(val value: Int) {
    StraightFlush(8),
    FourCard(7),
    FullHouse(6),
    Flush(5),
    Straight(4),
    ThreeCard(3),
    TwoPair(2),
    OnePair(1),
    None(0)
}

data class Hand(val type: HandType, val ranks: List<Int>) : Comparable<Hand> {
    override fun compareTo(other: Hand): Int {
        if (this.type != other.type) return this.type.value.compareTo(other.type.value)
        val myRank = ranks.sortedDescending()
        val yourRank = other.ranks.sortedDescending()
        for (i in myRank.indices) {
            if (myRank[i] != yourRank[i]) {
                return myRank[i].compareTo(yourRank[i])
            }
        }
        return 0
    }
}

data class Card(val suit: Suit, val number: Int) {
    companion object {
        fun fromString(s: String): Card {
            val number = when (s[0]) {
                in '2'..'9' -> s[0].digitToInt()
                'T' -> 10
                'J' -> 11
                'Q' -> 12
                'K' -> 13
                'A' -> 14
                else -> throw RuntimeException()
            }

            return Card(Suit.valueOf(s[1].toString()), number)
        }
    }
}

data class CardSet(val cards: List<Card>) {
    val sortedNumbers: List<Int>
        get() = cards.map { it.number }.sorted()
    val sortedCnts: List<Map.Entry<Int, Int>>
        get() = sortedNumbers.groupingBy { it }.eachCount().entries.sortedWith(
            compareByDescending<Map.Entry<Int, Int>> { it.value }
                .thenByDescending { it.key }
        )

    init {
        require(cards.size == 5)
    }

    private fun isFlush(): Int? = if (cards.all { it.suit == cards[0].suit }) cards.maxOf { it.number } else null
    private fun isStraight(): Int? {
        if (sortedNumbers == listOf(2, 3, 4, 5, 14)) return 5
        if (sortedNumbers.withIndex()
                .all { (index, number) -> number == sortedNumbers[0] + index }
        ) return sortedNumbers.last()
        return null
    }

    private fun isFourCard(): Int? = if (sortedCnts.getOrNull(0)?.value == 4) sortedCnts[0].key else null
    private fun isFullHouse(): Int? =
        if (sortedCnts.getOrNull(0)?.value == 3 && sortedCnts.getOrNull(1)?.value == 2) sortedCnts[0].key else null

    private fun isTriple(): Int? =
        if (sortedCnts.getOrNull(0)?.value == 3) sortedCnts[0].key else null

    private fun isTwoPair(): Int? =
        if (sortedCnts.getOrNull(0)?.value == 2 && sortedCnts.getOrNull(1)?.value == 2) sortedCnts[0].key else null

    private fun isOnePair(): Int? =
        if (sortedCnts.getOrNull(0)?.value == 2) sortedCnts[0].key else null

    fun calculateHand(): Hand {
        if (isFlush() != null && isStraight() != null) return Hand(HandType.StraightFlush, sortedNumbers)
        if (isFourCard() != null) return Hand(HandType.FourCard, sortedNumbers)
        if (isFullHouse() != null) return Hand(HandType.FullHouse, sortedNumbers)
        if (isFlush() != null) return Hand(HandType.Flush, sortedNumbers)
        if (isStraight() != null) return Hand(HandType.Straight, sortedNumbers)
        if (isTriple() != null) return Hand(HandType.ThreeCard, sortedNumbers)
        if (isTwoPair() != null) return Hand(HandType.TwoPair, sortedNumbers)
        if (isOnePair() != null) return Hand(HandType.OnePair, sortedNumbers)
        return Hand(HandType.None, sortedNumbers)
    }
}

fun main() {
    val t = readInt()
    repeat(t) {
        val s1 = readLine()!!
        val s2 = readLine()!!
        val cardSet1 = CardSet(s1.split(" ").map { Card.fromString(it) })
        val cardSet2 = CardSet(s2.split(" ").map { Card.fromString(it) })

        if (cardSet1.calculateHand() > cardSet2.calculateHand()) println(s1)
        else if (cardSet1.calculateHand() < cardSet2.calculateHand()) println(s2)
        else println("Tie")
    }
}

private fun readInt() = readln().toInt()
private fun readLong() = readln().toLong()
private fun readDouble() = readln().toDouble()
private fun readStrings() = readln().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }