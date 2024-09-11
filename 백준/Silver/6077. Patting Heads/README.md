# [Silver II] Patting Heads - 6077 

[문제 링크](https://www.acmicpc.net/problem/6077) 

### 성능 요약

메모리: 12192 KB, 시간: 320 ms

### 분류

구현, 수학, 정수론

### 제출 일자

2024년 9월 11일 19:11:49

### 문제 설명

<p>It's Bessie's birthday and time for party games! Bessie has instructed the N (1 <= N <= 100,000) cows conveniently numbered 1..N to sit in a circle (so that cow i [except at the ends] sits next to cows i-1 and i+1; cow N sits next to cow 1). Meanwhile, Farmer John fills a barrel with one billion slips of paper, each containing some integer in the range 1..1,000,000.</p>

<p>Each cow i then draws a number A_i (1 <= A_i <= 1,000,000) (which is not necessarily unique, of course) from the giant barrel.  Taking turns, each cow i then takes a walk around the circle and pats the heads of all other cows j such that her number A_i is exactly divisible by cow j's number A_j; she then sits again back in her original position.</p>

<p>The cows would like you to help them determine, for each cow, the number of other cows she should pat.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: A_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..N: On line i, print a single integer that is the number of other cows patted by cow i.</li>
</ul>

<p> </p>

