# [Platinum V] Vera And LCS - 15440 

[문제 링크](https://www.acmicpc.net/problem/15440) 

### 성능 요약

메모리: 110736 KB, 시간: 96 ms

### 분류

문자열, 애드 혹, 해 구성하기

### 제출 일자

2025년 5월 31일 19:44:04

### 문제 설명

<p>Vera is learning about the longest common subsequence problem.</p>

<p>A string is a (possibly empty) sequence of lowercase letters. A subsequence of a string S is a string obtained by deleting some letters of S (possibly none or all). For example “vra”, “a”, “”, and “vera” are all subsequences of “vera”. The longest common subsequence (LCS) of two strings, A and B, is a string that is a subsequence of both A and B that has the maximum length among all strings that are a subsequence of both A and B. There could be multiple LCS for two given strings. For example a LCS of “vera” and “eats” is “ea”.</p>

<p>For homework she was given two strings A and B, both of length N and she had to determine the length of the LCS of A and B. She determined the answer to be K but lost B. Given A and K, help her find a possible value of B. It is possible that Vera may have made a mistake and no such B exists, in that case output “WRONGANSWER"(without quotes).</p>

### 입력 

 <p>The input will be in the format:</p>

<pre>N K
A</pre>

<p>Constraints:</p>

<ul>
	<li>1 ≤ N ≤ 2000</li>
	<li>0 ≤ K ≤ 2000</li>
	<li>N, K are integers</li>
	<li>A consists of N lowercase letters</li>
</ul>

### 출력 

 <p>Output one line consisting of the string B of N lowercase letters, or “W RONGANSW ER” if no B is valid. If there are multiple correct B output any of them.</p>

