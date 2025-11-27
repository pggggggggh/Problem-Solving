# [Platinum III] 식당 - 6101 

[문제 링크](https://www.acmicpc.net/problem/6101) 

### 성능 요약

메모리: 67096 KB, 시간: 788 ms

### 분류

다이나믹 프로그래밍, 집합과 맵

### 제출 일자

2025년 11월 28일 01:05:08

### 문제 설명

<p>In the good old days, Farmer John served a boring cuisine comprising but a single type of cow food to his N (1 <= N <= 40000) prize dairy cows. Times change. Today he serves the herd a total of M (1 <= M <= N) different types of food (conveniently numbered 1..M).</p>

<p>The cows are picky. Cow i has a single food preference P_i (1 <= P_i <= M) and will eat only that favorite food.</p>

<p>Each day at feeding time FJ converts the barn into a tastefully lit cafeteria. The cows line up outside to enter the cafeteria in order of their previously-mentioned convenient index number.</p>

<p>Unfortunately, with so many types of food, cleaning up afterwards is very time-consuming. If Farmer John is serving K different types of food, it takes him K*K units of time to clean the barn.</p>

<p>To save time, FJ serves the cows in contiguous groups from the line. After each group, he cleans up the barn and sets out the food for the next group (of course, he only sets out food that cows in the any given group will eat). Determine the minimum amount of total time FJ must spend cleaning the barn. Each group consists of the next contiguous group of cows from the line; each cow belongs to exactly one group; and the barn must be cleaned up after every group, including the last one.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..N+1: Line i+1 contains a single integer: P_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer: the minimum amount of time FJ must spend cleaning the  barn.</li>
</ul>

<p> </p>

