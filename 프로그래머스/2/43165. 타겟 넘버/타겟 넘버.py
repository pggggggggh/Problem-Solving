from itertools import product

def solution(numbers, target):
    n = len(numbers)
    p = list(product([-1,1],repeat=n))
    ans = 0
    for ar in p:
        cur = 0
        for i in range(n):
            cur += ar[i]*numbers[i]
        if cur == target:
            ans += 1
    return ans