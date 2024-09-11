# [Gold II] Crisis on the Farm - 6180 

[문제 링크](https://www.acmicpc.net/problem/6180) 

### 성능 요약

메모리: 36244 KB, 시간: 12 ms

### 분류

분류 없음

### 제출 일자

2024년 9월 11일 18:37:30

### 문제 설명

<p>Farmer John and his herd of exotic dancing bovines have been practicing for his new moosical, "The Street Cow Named Desire". At one point in the middle of rehearsal, his cows are stacked on top of each other in N (1 <= N <= 1,000) sets of 30, one cow standing on the back of the other (they are quite amazing cows). Thus, the pasture is dotted with both these stacks of 30 cows and also, in separate locations, M (1 <= M <= 1,000) haystacks. Below is a sample of one way they might be laid out:</p>

<pre>                8 .........
                7 ....CH.H.         C = stack of 30 cows
                6 .........
                5 .........         H = haystack
                4 ..C.HH...
                3 .........
                2 .....C.HH
                1 .........
                  123456789</pre>

<p>As the musical's conductor, Farmer John has four whistles with various tones. One whistle commands the cow at the bottom of each stack to move (along with all the stacked cows) one unit north, another indicates a move to the south, one indicates a move to the east, and a fourth to order a move to the west.</p>

<p>Any time the stack of cows enters a grid location with a haystack, the cow on the top of the stack (even if the stack has height one) will jump onto the haystack while the remaining cows move into the same location as the haystack. Thus, if the bottom cow encounters 30 haystacks (perhaps different haystacks, perhaps not), the stack of 30 cows is exhausted with all the cows standing on top of haystacks (or standing on cows on haystacks). The sturdy haystacks can each support an unlimited number of cows.</p>

<p>Farmer John glances across his pasture to Farmer Don's milking facility to see, to his horror, a huge milk tank exploding and unleashing a giant tidal wave of milk making its way toward the performing cows! Since any cows on a haystack are safe, FJ must now do what he can to save the lives of as many cows as possible using what has turned from a simple dance routine into a lifesaving technique.</p>

<p>Given the number of times K (1 <= K <= 30) farmer John can blow a whistle until the wave of milk crashes over the pasture and also the X_i, Y_i positions (1 <= X_i <= 1,000; 1 <= Y_i <= 1,000) of the N stacks of cows and M haystacks (none of which currently has any cows on it), report the greatest number of cows that can be saved and find a sequence of whistle blows that does the job. The sequence should be reported in terms of the four directions, 'E' for east, 'N' for north, 'W' for west, 'S' for south.  Among all such sequences, farmer John wants the lexicographically least. Initial locations of cows and haystacks will not share the same coordinates in the input file.</p>

<p>Cows can be moved to any location, including ones outside the pasture.</p>

### 입력 

 <ul>
	<li>Line 1: Three space-separated integers: N, M, and K</li>
	<li>Lines 2..N+1: Line i+1 describes the X,Y location of a stack of 30 cows using two space-separated integers: X_i and Y_i</li>
	<li>Lines N+2..N+M+1: Line i+N+1 describes the X,Y location of a haystack using two space-separated integers: X_i and Y_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the most number of cows that can be saved.</li>
	<li>Line 2: K characters, the lexicographically least sequence of commands FJ should issue to maximize the number of cows saved.</li>
</ul>

<p> </p>

