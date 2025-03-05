# [Gold IV] 마법의 체스판 - 10589 

[문제 링크](https://www.acmicpc.net/problem/10589) 

### 성능 요약

메모리: 108384 KB, 시간: 92 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 3월 5일 14:32:05

### 문제 설명

<p>Little Dima gave his little brother Petya interactive chess board of size n × m as a present. There are many awesome features of this board but one is Petya’s favorite. He can choose any rectangle formed by board squares and perform an inversion. Every white cell in the inverted rectangle becomes black and every black one becomes white.</p>

<p>In the initial state the board is colored in chess style, namely every cell is either black or white and every two cells that share a side have different colors. Little Petya wants to perform several inversions described above to turn all cells into the same color. He is impatient, so he asks you to provide him with instructions to do it with the minimal number of inversions.</p>

### 입력 

 <p>The input file contains two integers, n and m (1 ≤ n, m ≤ 50) — the number of rows and columns on the board, respectively</p>

### 출력 

 <p>The first line of the output file must contain k — the number of inversions required to transform the board.</p>

<p>The following k lines must describe inversions, one per line. Each line must contains 4 integers — row and column of one of the corners of the corresponding rectangle and row and column of the opposite corner. Any two opposite corners can be used to specify a rectangle.</p>

<p>Rows of the board are numbered from 1 to n. Columns of the board are numbered from 1 to m.</p>

