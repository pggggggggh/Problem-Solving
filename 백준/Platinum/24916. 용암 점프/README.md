# [Platinum III] 용암 점프 - 24916 

[문제 링크](https://www.acmicpc.net/problem/24916) 

### 성능 요약

메모리: 2996 KB, 시간: 268 ms

### 분류

애드 혹, 다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2024년 12월 10일 22:18:05

### 문제 설명

<p>경기과학고등학교 학습실에는 때때로 용암이 찬다. 이 용암 바닥에 왼쪽에서 오른쪽으로 1부터 <em>N</em>까지의 정수 번호가 매겨진 <em>N</em> 개의 발판이 떠 있다. <em>i</em>의 번호가 매겨진 발판의 위치는 하나의 정수 <em>a<sub>i</sub></em>로 표현되며, 각 발판의 위치는 서로 다르다. 다시 말해, 1 ≤ <em>i</em> < <em>j</em> ≤ <em>N</em>인 두 정수 <em>i</em>, <em>j</em>에 대하여 <em>a<sub>i</sub></em> < <em>a<sub>j</sub></em>이다. 용암 바닥은 밟을 수 없으며, 발판만 밟을 수 있다. 안타깝게도, 한 번 밟은 발판은 발판에서 발을 떼는 순간 용암 바닥 아래로 영원히 가라앉아 다시 밟을 수 없게 된다.</p>

<p>정후는 정후의 친구 이환이가 각 위치 <em>a<sub>i</sub></em>에서 몇 번의 점프를 통해 마지막에 밟고 있는 하나의 발판을 제외한 모든 발판을 가라앉게 할 수 있는지 궁금하다. 하지만 운동 과잉인 이환이는 한 번 <em>x</em>만큼의 거리를 뛴 이후에는 2<em>x</em> 이상만큼의 거리만을 뛸 수 있다. 처음에는 어느 거리를 뛰어도 상관없다.</p>

<p>정후의 궁금증을 해결해 주자.</p>

### 입력 

 <p>첫 번째 줄에 테스트 케이스의 수를 나타내는 하나의 정수 <em>T</em>가 주어진다. 각 테스트 케이스마다 첫 번째 줄에 하나의 정수 <em>N</em>이 주어지며, 두 번째 줄에 <em>N</em> 개의 정수 <em>a<sub>i</sub></em>가 공백으로 구분되어 주어진다. 모든 테스트 케이스에서 <em>N</em>의 합은 1,000,000을 넘지 않는다.</p>

### 출력 

 <p>각 테스트 케이스마다 <em>N</em> 개의 줄에 걸쳐 <em>i</em> 번째 줄에는 하나의 문자열을 출력한다. 이환이가 <em>i</em>의 번호가 매겨진 발판에서 시작해 조건에 맞게 점프할 수 있다면 <code>YES</code>, 아니라면 <code>NO</code>이다. 대소문자에 유의하여라.</p>

