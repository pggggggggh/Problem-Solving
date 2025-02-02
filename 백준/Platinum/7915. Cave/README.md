# [Platinum III] Cave - 7915 

[문제 링크](https://www.acmicpc.net/problem/7915) 

### 성능 요약

메모리: 37176 KB, 시간: 344 ms

### 분류

다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 수학, 정수론, 트리

### 제출 일자

2025년 2월 2일 18:11:15

### 문제 설명

<p>Byteasar has discovered a cave. It appears that the cave contains n chambers connected with passages in such a way that there exists a single way of getting from any chamber to any other chamber.</p>

<p>The cave should now be examined more thoroughly, so Byteasar has asked his friends for help. They have all arrived at the cave and they are willing to divide themselves into groups. Each group should examine the same number of chambers, and each chamber should be examined by exactly one group. Additionally, for the groups not to interfere with each others’ work, the members of each group should be able to move between the assigned chambers without passing through chambers assigned to other groups.</p>

<p>How many groups can the explorers be divided into?</p>

### 입력 

 <p>The first line of the input contains one integer n (2 ≤ n ≤ 3 000 000) denoting the number of chambers in the cave. The chambers are numbered 1 through n.</p>

<p>The following n − 1 lines describe connections between the chambers. The i-th of these lines contains an integer a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ i) which represents a passage connecting chambers number i + 1 and a<sub>i</sub>.</p>

### 출력 

 <p>Your program should output a single line containing all integers k, such that the chambers can be divided into k disjoint sets of equal size, and one can move between any two chambers belonging to the same set passing only through chambers from this set. The numbers should be written in an ascending order and separated with single spaces.</p>

