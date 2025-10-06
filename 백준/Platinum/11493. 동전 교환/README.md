# [Platinum I] 동전 교환 - 11493 

[문제 링크](https://www.acmicpc.net/problem/11493) 

### 성능 요약

메모리: 66144 KB, 시간: 1100 ms

### 분류

그래프 이론, 최대 유량, 최소 비용 최대 유량

### 제출 일자

2025년 10월 7일 01:49:40

### 문제 설명

<p>A graph G = (V, E) has a set V of vertices and a set E of edges, and it is connected, that is, there is a path between every pair of vertices in G. Each vertex in G has a color which is either black or white. A coin is placed on each vertex in G and each coin also has a black or white color. A pair of adjacent vertices can swap their current coins, which is called a swap operation.</p>

<p>A swap operation is carried out in such a way that one edge in G is selected and the end vertices of the edge exchange their coins. Through these swap operations, black coins and white ones should be placed on black vertices and white ones, respectively, which is the goal of the problem. It is assumed that the number of black (and white) coins lying on the vertices is equal to the number of the black (and white, resp.,) vertices. That is, we can always achieve the goal of the problem.</p>

<p>Given a graph G, colors of the vertices of G, and colors of coins initially placed on the vertices, your program is to find the minimum number of the swap operations achieving the goal.</p>

<p>For example, in Figure 1, the colors of vertices 1 and 2 are black and the others are white. The coins placed on the vertices are drawn as rectangles with their colors. Then after three swap operations as shown in Figure 1, the colors of coins and vertices agree at each vertex.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11493/1.png" style="height:170px; width:630px"></p>

<p style="text-align:center">Figure 1. An example of swap operations.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing two integers n and m (1 ≤ n ≤ 500, n-1 ≤ m ≤ n(n-1)/2 ), where n and m represent the number of vertices and edges, respectively, of a connected graph G. The vertices are numbered from 1 to n. In each of the following m lines, there are two integers x and y(1 ≤ x < y ≤ n), which means there is an edge (x,y) connecting the vertices x and y in G. In the next line, there are n integers c<sub>i</sub> (c<sub>i</sub> = 0 or 1, i = 1, … , n), separated by a single space, where c<sub>i</sub> is the color of the vertex i. In the next line, there are n integers d<sub>i</sub> (d<sub>i</sub> = 0 or 1, i = 1, … ,n), separated by a single space, where d<sub>i</sub> is the color of a coin initially placed on the vertex i. If c<sub>i</sub> = 0 or d<sub>i</sub> = 0, it means black, and if c<sub>i</sub> = 1 or d<sub>i</sub> = 1, it means white.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the minimum number of the swap operations such that every vertex shall get a coin of the same color.</p>

