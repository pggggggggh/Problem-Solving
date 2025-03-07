def solution(arr):
    dp = [[-10**18 for _ in range(305)] for _ in range(305)]
    # dp[i][j] : i까지 봤고, 마이너스 괄호 j개 남았을 때 최대
    arr = [0]+arr
    dp[0][0] = int(arr[1])
    for i in range(2,len(arr),2):
        operand = arr[i]
        num = int(arr[i+1])
        for j in range(300):
            if operand == '-':
                if j%2==0:
                    dp[i][j] = max(dp[i][j],dp[i-2][j]-num)
                    dp[i][j+1] = max(dp[i][j+1],dp[i-2][j]-num)
                    if j>0:
                        dp[i][j-1] = max(dp[i][j-1],dp[i-2][j]-num)
                else:
                    dp[i][j] = max(dp[i][j],dp[i-2][j]+num)
                    dp[i][j+1] = max(dp[i][j+1],dp[i-2][j]+num)
                    if j>0:
                        dp[i][j-1] = max(dp[i][j-1],dp[i-2][j]+num)
            else:
                if j%2==0:
                    dp[i][j] = max(dp[i][j],dp[i-2][j]+num)
                    if j>0:
                        dp[i][j-1] = max(dp[i][j-1],dp[i-2][j]+num)
                else:
                    dp[i][j] = max(dp[i][j],dp[i-2][j]-num)
                    if j>0:
                        dp[i][j-1] = max(dp[i][j-1],dp[i-2][j]-num)
    
    # for i in range(2,len(arr),2):
    #     print(max(dp[i]))
            
    return max(dp[len(arr)-2])