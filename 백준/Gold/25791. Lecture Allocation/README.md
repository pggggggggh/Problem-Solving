# [Gold V] Lecture Allocation - 25791 

[문제 링크](https://www.acmicpc.net/problem/25791) 

### 성능 요약

메모리: 198092 KB, 시간: 172 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 2월 5일 22:27:11

### 문제 설명

<p>You are the coordinator for a competitive programming club. You need to hire some teachers to give lectures. There are a fixed number of lectures that need to be given this year. Additionally, there are a limited number of teachers that are willing to give lectures. Each teacher can teach up to three lectures, but not all the teachers need to teach a lecture, i.e., a teacher could teach 0, 1, 2, or 3 lectures. Each teacher charges a different amount depending on the number of lectures they give.</p>

<p>The money not spent will be used to fly the team to other contests, so you want to spend as little money as possible hiring enough teachers to give all the lectures.</p>

<p>Given the number of lectures to teach and how much each teacher charges for giving the lectures, determine the least amount of money necessary such that all the lectures will be taught.</p>

### 입력 

 <p>The first input line contains two integers, L and T (1 ≤ L ≤ 5000, L/3 ≤ T ≤ L), representing (respectively) the number of lectures and the number of teachers. Each of the following T input lines contains three integers, the i th of which contains a<sub>i1</sub>, a<sub>i2</sub>, and a<sub>i3</sub> (0 < a<sub>i1</sub> < a<sub>i2</sub> < a<sub>i3</sub> ≤ 100,000), representing (respectively) how much the i th teacher charges to give 1, 2, and 3 lectures.</p>

### 출력 

 <p>Print on a single line by itself a single positive integer: the least cost for paying the teachers to cover all L lectures. Assume that there are enough teachers to cover all the lectures.</p>

