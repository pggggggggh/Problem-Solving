# [Platinum II] Black Family Tree - 20681 

[문제 링크](https://www.acmicpc.net/problem/20681) 

### 성능 요약

메모리: 23332 KB, 시간: 88 ms

### 분류

자료 구조, 오프라인 쿼리, 세그먼트 트리, 트리

### 제출 일자

2024년 11월 5일 17:38:24

### 문제 설명

<p>A Time-Turner is a magical device used to travel back in time, spend some time there, and then get back to the current time.</p>

<p>Rose Granger has found a Time-Turner in the libraries of Hogwarts and took it upon herself to go back in time and take out some members of the Black family, in order to save the lives of muggles (humans without any magical ability).</p>

<p>The Black family has n members, numbered 1 to n in order of being born. Member 1 is the first member of the Black family with a recorded history. For each i (2 ⩽ i ⩽ n), member i is a direct descendant of member p<sub>i</sub> (1 ⩽ p<sub>i</sub> < i). i.e., member p<sub>i</sub> and all of his/her ancestors are an ancestor of member i. It is also written in the books that the i-th member of the Black family is responsible for the death of c<sub>i</sub> muggles.</p>

<p>Now Rose has q options. The j-th option is to use the Time-Turner to go back in time and take out all the members from a<sub>j</sub> to b<sub>j</sub> (a<sub>j</sub> ⩽ b<sub>j</sub>) and then come back to the current time. As a consequence of this action, any member of the Black family who has an ancestor among members a<sub>j</sub> to b<sub>j</sub> will never be born. For any member i who is among members a<sub>j</sub> to b<sub>j</sub> (i.e. a<sub>j</sub> ⩽ i ⩽ b<sub>j</sub>), or has an ancestor among members a<sub>j</sub> to b<sub>j</sub>, Rose will save c<sub>i</sub> lives.</p>

<p>For each option, help Rose to find out how many lives she will save if she takes that option.</p>

### 입력 

 <p>The first line of the input contains two integers n and q (2 ⩽ n ⩽ 10<sup>5</sup>, 1 ⩽ q ⩽ 10<sup>5</sup>). The second line contains n space-separated integers c<sub>1</sub> to c<sub>n</sub> (0 ⩽ c<sub>i</sub> ⩽ 10<sup>4</sup>). The third line contains n−1 integers p<sub>2</sub> to p<sub>n</sub> (1 ⩽ p<sub>i</sub> < i). Each of the next q lines contains one option; The j-th line contains two integers a<sub>j</sub> and b<sub>j</sub> (1 ⩽ a<sub>j</sub> ⩽ b<sub>j</sub> ⩽ n).</p>

### 출력 

 <p>For each j (1 ⩽ j ⩽ q), output the number of lives Rose will save if she takes the j-th option.</p>

