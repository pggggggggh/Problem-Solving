# [Platinum II] Juice (Large) - 12662 

[문제 링크](https://www.acmicpc.net/problem/12662) 

### 성능 요약

메모리: 2304 KB, 시간: 124 ms

### 분류

애드 혹, 브루트포스 알고리즘, 자료 구조, 기하학, 우선순위 큐, 슬라이딩 윈도우, 스위핑, 삼분 탐색, 두 포인터

### 제출 일자

2025년 1월 12일 02:04:21

### 문제 설명

<p>You are holding a party. In preparation, you are making a drink by mixing together three different types of fruit juice: Apple, Banana, and Carrot. Let's name the juices A, B and C.</p>

<p>You want to decide what fraction of the drink should be made from each type of juice, in such a way that the maximum possible number of people attending the party like it.</p>

<p>Each person has a minimum fraction of each of the 3 juices they would like to have in the drink. They will only like the drink if the fraction of each of the 3 juices in the drink is greater or equal to their minimum fraction for that juice.</p>

<p>Determine the maximum number of people that you can satisfy.</p>

### 입력 

 <ul>
	<li>One line containing an integer <strong>T</strong>, the number of test cases in the input file.</li>
</ul>

<p>For each test case, there will be:</p>

<ul>
	<li>One line containing the integer <strong>N</strong>, the number of people going to the party.</li>
	<li><strong>N</strong> lines, one for each person, each containing three space-separated numbers "A B C", indicating the minimum fraction of each juice that would like in the drink. A, B and C are integers between 0 and 10000 inclusive, indicating the fraction in parts-per-ten-thousand. A + B + C ≤ 10000.</li>
</ul>

<p>Limits</p>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 12</li>
	<li>1 ≤ <strong>N</strong> ≤ 5000</li>
</ul>

### 출력 

 <ul>
	<li><strong>T</strong> lines, one for each test case in the order they occur in the input file, each containing the string "Case #X: Y" where X is the number of the test case, starting from 1, and Y is the maximum number of people who will like your drink.</li>
</ul>

