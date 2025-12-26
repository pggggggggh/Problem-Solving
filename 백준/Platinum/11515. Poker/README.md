# [Platinum V] Poker - 11515 

[문제 링크](https://www.acmicpc.net/problem/11515) 

### 성능 요약

메모리: 28076 KB, 시간: 268 ms

### 분류

구현

### 제출 일자

2025년 12월 26일 14:18:57

### 문제 설명

<p>Poker is a family of gambling card games involving betting and individual play, whereby the winner is determined by the ranks and combinations of players' cards, some of which remain hidden until the end of the game.</p>

<p>Each card has a suit (Club, Diamond, Heart, Spade) and a rank. The ranks are, from lowest (least valuable) to highest (most valuable): ace (low), 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king, ace (high). Although only one ace card exists within each suit, and it is usually ranked as the highest card, under some circumstances the ace card will be treated as the lowest. The suit itself has no bearing on the worth of the card and is only used to determine which category a particular hand belongs to.</p>

<p>Poker hands are made of combinations of 2 to 5 cards in the hand. Cards that are not used in the combination are called kicker cards and can be used to break ties if needed.</p>

<p>The ranking of poker hands (best to worst) is as follows:</p>

<p>A Royal Flush is a hand that includes a 10, Jack, Queen, King, and Ace all of the same suit. If both hands have a Royal Flush, the hands tie.</p>

<p>A Straight Flush is a hand where the ranks of the cards are sequential and they all share the same suit. For example, a hand that has the 5, 6, 7, 8, and 9 of Clubs is a Straight Flush. An Ace can be either low (come before a 2) or high (come after a King). When comparing Straight Flushes, the straight with the highest ranked card wins. If the hands have the same highest ranked card, the hands tie.</p>

<p>A Four of a Kind is a hand that contains four cards of the same rank. For example, a hand that has the 2 of Clubs, 2 of Hearts, 2 of Diamonds, 2 of Spades, and any other card is a Four of a Kind. When comparing Four of a Kinds, the hand with the set of four cards with the highest rank wins.</p>

<p>A Full House is a hand that contains three cards of one rank and two cards of another rank. For example, a hand that has the 2 of Clubs, 2 of Hearts, 2 of Diamonds, 3 of Clubs, and 3 of Hearts is a Full House of 2s over 3s. When comparing Full Houses, the hand with the set of three cards with the highest rank wins.</p>

<p>A Flush is a hand of five cards that all share the same suit. For example, a hand that has the Ace of Spades, 3 of Spades, 7 of Spades, 10 of Spades, and King of Spades is a Flush. When comparing Flushes, the hand with the highest ranked card wins. If both hands have the same high card, compare the next highest card and repeat until a winner is found. If both hands have the same five ranks, the hands tie.</p>

<p>A Straight is a hand where the ranks of the cards are sequential. For example, a hand that has the 5 of Clubs, 6 of Hearts, 7 of Spades, 8 of Diamonds, and 9 of Clubs is a Straight. Like a Straight Flush, an Ace can be either high or low. When comparing Straights, the straight with the highest ranked card wins. If the hands have the same highest ranked card, the hands tie.</p>

<p>A Three of a Kind is a hand that has three cards of the same rank. For example, a hand that has the 2 of Clubs, 2 of Hearts, 2 of Diamonds, 3 of Clubs, and 4 of Clubs is a Three of a Kind of 2s. When comparing Three of a Kinds, the hand with the highest ranking set wins.</p>

<p>A Two Pair is a hand that has two sets of two cards of the same rank. For example, a hand that has the 2 of Clubs, 2 of Hearts, 3 of Clubs, 3 of Hearts, and the 4 of Clubs is a Two Pair. When comparing Two Pairs, the hand that has the highest ranking set wins. If both hands have the same highest ranking set, the hand with the second highest ranking set wins. If those sets have the same rank, the hand with the highest ranking kicker card wins. If the kicker cards have the same rank, the hands tie.</p>

<p>A One Pair is a hand that has one set of two cards of the same rank. For example, a hand that has the 2 of Clubs, 2 of Hearts, 3 of Clubs, 4 of Clubs, and 5 of Clubs is a One Pair. When comparing One Pairs, the hand with the highest rank set wins. If both hands have the same highest ranking set, then the hand with the highest kicker card is the winner. If both hands have the same high kicker card, compare the next highest kicker card and repeat until a winner is found. If both hands have the same kicker cards, the hands tie.</p>

<p>If neither hand has a special combination, the hand with the card with the highest rank wins. If both hands have the same high card, compare the next highest card and repeat until a winner is found. If both hands have the same five cards, ignoring suits, the hands tie.</p>

### 입력 

 <p>Input consists of a number of rounds to score, then two hands for each round.</p>

<p>The first line contains an integer W (1 <= W <= 200) indicating the number of rounds to score.</p>

<p>After the first line, there will be W pairs of lines of strings that describe a poker hand. The strings will be 5 rank and suit combinations separated by spaces. Single digit ranks (2 through 9) are represented by that number; Ten, Jack, Queen, King, and Ace are each represented by the (capitalized) first letter of the word. The suit is also represented by the (capitalized) first letter of its name. For example, "2C 4D 8H TD KS" is the hand that has the 2 of Clubs, 4 of Diamonds, 8 of Hearts, 10 of Diamonds, and King of Spades. Within each round, there will be no duplicate cards.</p>

### 출력 

 <p>For each pair of hands, output a single line containing the hand that wins the poker round or the string Tie if the hands tie. The hand should be displayed the same as it was given in the input file.</p>

