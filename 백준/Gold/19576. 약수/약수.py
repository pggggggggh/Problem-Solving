n = int(input())
a = list(map(int, input().split()))
a.sort()  # 오름차순 정렬

dp = [1] * n  # dp[i]는 i번째 원소를 마지막으로 하는 최대 약수-배수 관계의 길이

for i in range(n):
    for j in range(i):
        if a[i] % a[j] == 0:  # a[i]가 a[j]의 배수인 경우
            dp[i] = max(dp[i], dp[j] + 1)

print(n - max(dp))  # 전체 길이에서 가장 긴 약수-배수 관계의 길이를 뺀 값
