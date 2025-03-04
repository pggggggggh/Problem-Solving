# [Platinum IV] 보트 정박 - 23024 

[문제 링크](https://www.acmicpc.net/problem/23024) 

### 성능 요약

메모리: 9308 KB, 시간: 324 ms

### 분류

이분 탐색, 자료 구조, 세그먼트 트리

### 제출 일자

2025년 3월 5일 00:45:53

### 문제 설명

<p>Albert makes a living by letting boats anchor at his docks.</p>

<p>There are n docks along the place, numbered from1  to n (from left to right). The i-th dock can be used to anchor any boat whose length is P[i] or less. Each dock can be used for at most one boat. Today, Albert expects m boats to enter his docks (from boat 1 to boat m). Let B[j] be the length of boat j.</p>

<p>Each boat anchors at a dock or passes through according to the following rules:</p>

<ol>
	<li>The boat moves from left to right, and anchors at the first empty dock where it can anchor. (That is, if dock i is empty and P[i] ≥ B[j], then boat j can anchor at dock i.)</li>
	<li>If the boat cannot anchor at any dock, it just passes through without anchoring.</li>
</ol>

<p>For instance, let n = 3, m = 5, P = [2, 2, 2], and B = [1, 2, 3, 2, 1] as shown in the image bloew.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6f04aa92-4c78-409d-8ac4-0d2845dba093/-/preview/" style="height: 136px; width: 500px;"></p>

<p>In this case, the boats enter (and exit) the docks as follows.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fd140e5f-9708-4bd8-803f-9bbebf5e9099/-/preview/" style="height: 149px; width: 500px;"></p>

<ul>
	<li>Boat 1 (of length 1) anchors at dock 1. (Left)</li>
	<li>Boat 2 (of length 2) anchors at dock 2. (Center)</li>
	<li>Boat 3 (of length 3) passes through without anchoring as dock 3 is too short for it.</li>
	<li>Boat 4 (of length 2) anchors at dock 3. (Right)</li>
	<li>Boat 5 (of length 1) passes through.</li>
</ul>

<p>After every boat has either anchored or passed, let A[i] be the number of the boat anchored at dock i. If no boat is anchored, we define A[i] = 0.</p>

<p>Albert wants to calculate A[1] × 1 + A[2] × 2 + ... + A[n] × n. Help Albert calculate this! In the example above, the answer is 17 as A = [1, 2, 4].</p>

### 입력 

 <p>The first line of the input will contain an integer T, the number of test cases.</p>

<p>Each test case will consist of three lines. The first line will contain n and m, separated by whitespace. The second line will contain n integers (P[1], ..., P[n]), separated by whitespace. The third line will contain m integers (B[1], ..., B[m]), separated by whitespace.</p>

### 출력 

 <p>Output the answer of each test case in each line.</p>

