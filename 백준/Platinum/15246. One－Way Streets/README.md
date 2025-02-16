# [Platinum I] One-Way Streets - 15246 

[문제 링크](https://www.acmicpc.net/problem/15246) 

### 성능 요약

메모리: 91308 KB, 시간: 880 ms

### 분류

이중 연결 요소, 자료 구조, 분리 집합, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 트리

### 제출 일자

2025년 2월 16일 16:18:39

### 문제 설명

<p>Once upon a time there was a country with n cities and m bidirectional roads connecting them. Technical development led to faster and larger road vehicles which presented a problem—the roads were becoming too narrow for two vehicles travelling in opposite direction. A decision to solve this problem involved turning all the roads into single-lane, one-way (unidirectional) roads.</p>

<p>Making the roads one-way comes at a cost because some of those pairs of cities that were previously connected might no longer be reachable after the change. The government compiled a list of important pairs of cities for which it has to be possible to start in the first city and reach the second one. Your task is to determine in which direction to direct the traffic on every road. It is guaranteed that a solution exists.</p>

<p>For some roads there is no choice about the direction of traffic if you want to obtain a solution. The traffic will flow from the first to the second city (right direction, indicated by letter R) or from the second city towards the first (left direction, indicated by letter L). However, for some roads there exists a solution with this road directed left, and another (possibly different) solution with the road directed right. You should indicate such roads with a letter B for both directions.</p>

<p>Output a string of length m. Its i-th character should be</p>

<ul>
	<li>R if all solutions require the i-th road to be directed right</li>
	<li>L if all solutions require the i-th road to be directed left</li>
	<li>B if a solution exists where the i-th road is directed left, and a solution also exists where the i-th road is directed right</li>
</ul>

### 입력 

 <p>The first line contains the number of cities n and the number of roads m. The following m lines describe the roads with pairs of numbers a<sub>i</sub> and b<sub>i</sub>, which indicate that there is a road between cities a<sub>i</sub> and b<sub>i</sub>. There can be more than one road between the same pair of cities and a road can even connect the city with itself.</p>

<p>The next line contains the number of pairs of cities p that have to be reachable. The next p lines contain pairs of cities x<sub>i</sub> and y<sub>i</sub>, meaning that there has to be a way to start in city x<sub>i</sub> and reach y<sub>i</sub>.</p>

### 출력 

 <p>Output a string of length m as described in the description of the task.</p>

