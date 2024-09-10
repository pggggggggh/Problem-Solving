# [Gold III] Trick or Treat on the Farm - 6072 

[문제 링크](https://www.acmicpc.net/problem/6072) 

### 성능 요약

메모리: 26784 KB, 시간: 56 ms

### 분류

깊이 우선 탐색, 함수형 그래프, 그래프 이론, 그래프 탐색

### 제출 일자

2024년 9월 10일 11:08:51

### 문제 설명

<p>Every year in Wisconsin the cows celebrate the USA autumn holiday of Halloween by dressing up in costumes and collecting candy that Farmer John leaves in the N (1 <= N <= 100,000) stalls conveniently numbered 1..N.</p>

<p>Because the barn is not so large, FJ makes sure the cows extend their fun by specifying a traversal route the cows must follow.  To implement this scheme for traveling back and forth through the barn, FJ has posted a "next stall number" next_i (1 <= next_i <= N) on stall i that tells the cows which stall to visit next; the cows thus might travel the length of the barn many times in order to collect their candy.</p>

<p>FJ mandates that cow i should start collecting candy at stall i. A cow stops her candy collection if she arrives back at any stall she has already visited.</p>

<p>Calculate the number of unique stalls each cow visits before being forced to stop her candy collection.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: next_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..N: Line i contains a single integer that is the total number of unique stalls visited by cow i before she returns to a stall  she has previously visited.</li>
</ul>

<p> </p>

