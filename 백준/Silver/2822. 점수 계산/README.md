# [Silver V] 점수 계산 - 2822 

[문제 링크](https://www.acmicpc.net/problem/2822) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

정렬

### 제출 일자

2025년 2월 18일 17:26:43

### 문제 설명

<p>The Croatian version of this contest has the following rules: “Each round of the contest consists of 8 tasks with different point values. Every contestant may solve any of the tasks they choose. However, the contestant’s final score will be the sum of points earned on any 5 tasks such that this sum is maximized.” </p>

<p>Since the organizers were busy coming up with interesting problems for the contest (and translating them), they’ve simply forgotten to solve the problem of determining the points scored by each contestant. Now they are kindly asking you to do it for them. </p>

<p>Write a program that, given the number of points earned by a contestant on each task, determines the total amount of points scored by that contestant, as well as the sorted list of the 5 problems counting towards that score. No contestant will ever score the same amount of points on two different problems. </p>

### 입력 

 <p>Input consists of 8 lines. Each line of input contains a single positive integer X (0 ≤ X ≤ 150), where the number X in row i denotes the number of points earned by the contestant on problem i. All 8 numbers X will be distinct. </p>

### 출력 

 <p>The first line of output must contain the total amount of points scored by the contestant. </p>

<p>The second line of output must contain indices of the 5 problems counting towards the total score, sorted in ascending order, separated by single spaces. Problem indices are positive integers from 1 to 8, inclusive. </p>

