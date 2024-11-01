import random

def main():
    n = int(input())
    a = list(map(int, input().split()))
    a=sorted(a)

    tc = 1000
    for _ in range(tc):
        ar = random.sample(a, n)
        if sum(ar) % n == 0:
            for x in ar:
                print(x, end=' ')
            return

    cur = sum(a[:n])
    if cur%n == 0:
        if cur%n == 0:
            for x in a[:n]:
                print(x, end=' ')
            return
    for i in range(n,2*n-1):
        cur += a[i]
        cur -= a[i-n]
        if cur%n == 0:
            for x in a[i+1-n:i+1]:
                print(x,end=' ')
            return




if __name__ == "__main__":
    main()
