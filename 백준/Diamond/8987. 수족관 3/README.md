# [Diamond IV] 수족관 3 - 8987 

[문제 링크](https://www.acmicpc.net/problem/8987) 

### 성능 요약

메모리: 119788 KB, 시간: 676 ms

### 분류

자료 구조, 그리디 알고리즘, 트리, 세그먼트 트리, 분할 정복, 느리게 갱신되는 세그먼트 트리

### 제출 일자

2025년 5월 31일 18:35:46

### 문제 설명

<p>아래 그림 1은 수족관을 앞에서 본 모양이다. 이 수족관에는 물이 가득 차 있다. 만약 수족관 밑바닥(수평선분)에 구멍을 하나 뚫으면, 구멍을 통해 수족관 안의 물이 빠지게 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4c0f1045-5150-455d-8a8e-f9f2c9fe9557/-/preview/" style="width: 264px; height: 210px;"></p>

<p style="text-align: center;">그림 1. 수족관과 구멍.</p>

<p>그림 1에서 보는 것처럼, X-축은 왼쪽에서 오른쪽으로 증가하고, Y-축은 위쪽에서 아래쪽으로 증가한다. 바닥을 나타내는 수평선분에 구멍이 있다면, 그 수평선분의 y-좌표와 같거나 작은 위치에 있으면서, 중력에 따라 구멍으로 흘러 들어갈 수 있는 위치에 있는 물은 모두 그 구멍을 통해 외부로 배출된다. 따라서 그림 1의 수족관의 물은 남김없이 모두 빠진다.</p>

<p>수족관에 담긴 물의 양은 물이 차지하는 면적과 일치하는 양이다. 물의 양의 단위는 L(리터)이다. 따라서 그림 1에서 수족관에 물을 가득 채우면 물의 양은 물이 차지하는 면적과 동일한 40L이다.</p>

<p>그림 2처럼 수족관의 바닥이 복잡할 수도 있다. </p>

<p>수족관 바닥은 수평선분과 수직선분이 번갈아 나타나는 형태이다. 또한 그림 2처럼 수족관 위에서 수직방향으로 수족관 바닥을 보았을 때, 수족관의 바닥이 모두 보이는 (즉, 모든 수평선분이 보이는) 형태이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/55d1b6ae-0068-4d23-aee7-051fe344e6a4/-/preview/" style="width: 264px; height: 201px;"></p>

<p style="text-align: center;">그림 2. 수족관의 처음 상태. 물의 양은 26L이고 구멍은 2개.</p>

<p>구멍은 항상 수평선분에만 존재하며, 수평선분의 한 가운데에 위치한다. 그리고 하나의 수평선분에는 최대 하나의 구멍만 존재할 수 있다. </p>

<p>이제 2개의 구멍을 수평선분 2개에 배치해 보자. 이때, 배출되는 물의 양이 최대가 되도록 배치해야 한다. 만약, 그림 3처럼 2개의 구멍을 배치하면, 원래 물의 양인 26L 중에서 19L만 빠져나가고 7L는 남게 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e0e15021-56ab-4923-af94-5f7e0799d77b/-/preview/" style="width: 270px; height: 189px;"></p>

<p style="text-align: center;">그림 3. 19L가 빠져나가고 7L만 남음.</p>

<p>그러나 그림 4처럼 2개의 구멍을 배치하면, 1L만 남고 25L가 빠져나간다. 결국, 구멍을 2개 배치하는 경우에는 최대 25L의 물을 뺄 수 있는 구멍의 배치가 존재하게 된다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6b94b4cd-f176-4297-a212-ed3281891def/-/preview/" style="width: 262px; height: 183px;"></p>

<p style="text-align: center;">그림 4. 25L가 빠져나가고 1L만 남음.</p>

<p>최대한 많은 양의 물이 배출되도록 K개의 구멍을 배치한다고 할 때, 배출되는 최대 물의 양을 출력하는 프로그램을 작성하시오. </p>

### 입력 

 <p>입력의 첫 줄은 수족관의 경계에 있는 꼭짓점의 개수 N(4 ≤ N ≤ 300,000)이 주어진다. N은 짝수이다. 수족관의 경계는 항상 꼭짓점 (0, 0)부터 시작한다. 그리고 마지막 꼭짓점은 (A, 0)의 형태로 끝난다. 즉, 시작 꼭짓점과 마지막 꼭짓점의 Y-좌표는 항상 0이다. 모든 꼭짓점의 좌표 값은 0 이상 1,000,000,000 이하의 정수이다. 수족관의 경계를 이루는 변은 꼭짓점 (0, 0)부터 시작하는 데, 수직선분으로 시작하여 수평선분과 수직선분이 번갈아가며 반복되다 수직선분으로 끝난다. 따라서 수직선분이 수평선분보다 항상 하나 더 많다. 두 번째 줄부터 N개의 줄에는 수족관 경계에 있는 N개의 꼭짓점의 x-좌표와 y-좌표 값이 빈칸을 사이에 두고 각 줄에 하나씩, 첫 꼭짓점 (0, 0)부터 시계반대방향을 따라 차례로 주어진다. 다음 줄에는 뚫어야 할 구멍의 개수 K (1 ≤ K ≤ N/2)가 자연수로 주어진다. </p>

### 출력 

 <p>출력은 단 한 줄이다. 최대한 많은 양의 물을 배출하도록 K개의 구멍을 배치한다고 할 때, 배출되는 최대 물의 양을 0 이상의 정수로 출력한다. </p>

