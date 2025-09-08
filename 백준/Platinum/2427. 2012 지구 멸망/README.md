# [Platinum I] 2012 지구 멸망 - 2427 

[문제 링크](https://www.acmicpc.net/problem/2427) 

### 성능 요약

메모리: 2084 KB, 시간: 192 ms

### 분류

수학, 그리디 알고리즘, 브루트포스 알고리즘

### 제출 일자

2025년 9월 8일 17:32:36

### 문제 설명

<p>The Society for Saving the World has called their N members to an emergency congress to finally agree on a plan for saving the world. To reach a common decision in any meeting at the congress, the meeting participants proceed as follows:</p>

<ol>
	<li>Each of them has a proposal and takes P minutes to present it to the others.</li>
	<li>After all participants have made their presentations, they vote for the best proposal, which takes V minutes.</li>
</ol>

<p>For example, if each proposal takes one minute (P = 1) and voting also takes one minute (V = 1), a meeting with 100 participants would reach a decision in 101 minutes.</p>

<p>To speed up the overall decision-making process, the participants of the congress have decided to split into groups and work in parallel. Each group selects the best proposal among themselves using the procedure described above. Then the representatives of the groups meet and pick the ﬁnal plan among the proposals voted best in each group.</p>

<p>For example, if the 100 participants would split into two groups of 40 and 60, respectively, the process could work as follows (again, P = V = 1):</p>

<ul>
	<li>the larger group takes 61 minutes to select their best proposal;</li>
	<li>the smaller group takes 41 minutes to do the same and then has to wait for the larger group to finish;</li>
	<li>then the two representatives of the groups meet and spend 2 minutes presenting to each other and 1 minute to vote.</li>
</ul>

<p>The total time spent is thus 61 + 2 + 1 = 64 minutes.</p>

<p>But the groups might further divide themselves into subgroups and sometimes it could be useful to split into more than two groups. As a special case, a subgroup of 1 member can decide in no time, as there is no need to present one’s own proposal to oneself.</p>

<p>Write a program that, given presentation and voting times P and V, computes the minimal time needed for the N participants of the congress to reach a common decision, assuming they organize their meetings and groups optimally.</p>

### 입력 

 <p>The ﬁrst and only line of input contains the three integers N, P, and V: N is the number of participants of the congress, P is the presentation time (in minutes), and V is the voting time (in minutes).</p>

### 출력 

 <p>The ﬁrst and only line of output should contain the integer M, the minimal number of minutes needed for the congress to reach a decision.</p>

