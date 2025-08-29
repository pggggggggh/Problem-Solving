# [Gold II] 닭싸움 팀 정하기 - 1765 

[문제 링크](https://www.acmicpc.net/problem/1765) 

### 성능 요약

메모리: 2364 KB, 시간: 0 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 분리 집합

### 제출 일자

2025년 8월 30일 02:26:38

### 문제 설명

<p>Chicago in the 1920s: a battlefield of gangsters.</p>

<p>If two gangsters have ever met each other, then they have become either true friends or mortal enemies. The gangsters live - and die - by the following code of ethics.</p>

<ol>
	<li>A friend of my friend is also my friend.</li>
	<li>An enemy of my enemy is my friend.</li>
</ol>

<p>Two gangsters are in the same gang if and only if they are friends.</p>

<p>Poor you are employed by the Chicago Police Department. You must calculate the maximal possible number of different gangs in Chicago based on what the Department knows about the relations between the individual gangsters.</p>

### 입력 

 <p>The first line of the input gives the number N (2 ≤ N ≤ 1 000) of known gangsters. The gangsters are numbered from 1 to N. The second line gives the number M (1 ≤ M ≤ 5 000) of known facts about these gangsters.</p>

<p>The following M lines list the facts, each fact on its own line. Each fact is of the form F p q or E p q, where 1 ≤ p < q ≤ N are the two gangsters in question. (Each of three components is separated by a space.) If the first letter is F, the line says that p and q are known friends. If it is E, then they are known enemies.</p>

<p>It can be assume that the input is consistent - two gangsters cannot be both friends and enemies of each other.</p>

### 출력 

 <p>The first and only line of the output must contain the maximal possible number of gangs.</p>

