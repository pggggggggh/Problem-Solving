# [Gold III] Stop Counting! - 17594 

[문제 링크](https://www.acmicpc.net/problem/17594) 

### 성능 요약

메모리: 258492 KB, 시간: 412 ms

### 분류

애드 혹, 수학, 누적 합

### 제출 일자

2025년 3월 9일 17:28:12

### 문제 설명

<p>The Martingale casino is creating new games to lure in new gamblers who tire of the standard fare. Their latest invention is a fast-paced game of chance called Stop Counting!, where a single customer plays with a dealer who has a deck of cards. Each card has some integer value.</p>

<p>One by one, the dealer reveals the cards in the deck in order, and keeps track of the sum of the played cards and the number of cards shown. At some point before a card is dealt, the player can call “Stop Counting!” After this, the dealer continues displaying cards in order, but does not include them in the running sums. At some point after calling “Stop Counting!”, and just before another card is dealt, the player can also call “Start Counting!” and the dealer then includes subsequent cards in the totals. The player can only call “Stop Counting!” and “Start Counting!” at most once each, and they must call “Stop Counting!” before they can call “Start Counting!”. A card is “counted” if it is dealt before the player calls “Stop Counting!” or is dealt after the player calls “Start Counting!”</p>

<p>The payout of the game is then the average value of the counted cards. That is, it is the sum of the counted cards divided by the number of counted cards. If there are no counted cards, the payout is 0.</p>

<p>You have an ‘in’ with the dealer, and you know the full deck in order ahead of time. What is the maximum payout you can achieve?</p>

### 입력 

 <p>The first line of the input contains a single integer 1 ≤ <em>N</em> ≤ 1 000 000, the number of cards in the deck.</p>

<p>The second line of input contains <em>N</em> space-separated integers, the values on the cards. The value of each card is in the range [−10<sup>9</sup>, 10<sup>9</sup>]. The cards are dealt in the same order they are given in the input.</p>

### 출력 

 <p>Output the largest attainable payout. The answer is considered correct if the absolute error is less than 10<sup>−6</sup>, or the relative error is less than 10<sup>−9</sup>.</p>

