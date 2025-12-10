# [Platinum III] 원형 네트워크 - 2215 

[문제 링크](https://www.acmicpc.net/problem/2215) 

### 성능 요약

메모리: 2244 KB, 시간: 36 ms

### 분류

그리디 알고리즘, 스위핑

### 제출 일자

2025년 12월 10일 23:37:27

### 문제 설명

<p>Farmer John wants to connect his N (1 <= N <= 1,000) barns (numbered 1..N) with a new fiber-optic network. However, the barns are located in a circle around the edge of a large pond, so he can only connect pairs of adjacent barns. The circular configuration means that barn N is adjacent to barn 1.</p>

<p>FJ doesn't need to connect all the barns, though, since only certain pairs of cows wish to communicate with each other. He wants to construct as few<br>
connections as possible while still enabling all of these pairs to communicate through the network. Given the list of barns that wish to communicate with each other, determine the minimum number of lines that must be laid. To communicate from barn 1 to barn 3, lines must be laid from barn 1 to barn 2 and also from barn 2 to barn 3(or just from barn 3 to 1,if n=3).</p>

### 입력 

 <ul>
	<li>Line 1: Two integers, N and P (the number of communication pairs, 1 <= P <= 10,000)</li>
	<li>Lines 2..P+1: two integers describing a pair of barns between which communication is desired. No pair is duplicated in the list.</li>
</ul>

### 출력 

 <p>One line with a single integer which is the minimum number of direct connections FJ needs to make.</p>

