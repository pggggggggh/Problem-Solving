def solution(money):
    n = len(money)
    money = [0]+money
    dp1 = [[0,0] for _ in range(n+1)]
    dp2 = [[0,0] for _ in range(n+1)]
    for i in range(1,n+1):
        dp1[i][0] = max(dp1[i-1][0],dp1[i-1][1])
        if i != n:
            dp1[i][1] = dp1[i-1][0]+money[i]
    for i in range(2,n+1):
        if i==n:
            dp2[i][1] = dp2[i-1][0]+money[i]
            break
        dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1])
        if i!=n-1 and i!=1:
            dp2[i][1] = dp2[i-1][0]+money[i]
            
    return max(max(dp1[n]),max(dp2[n]))