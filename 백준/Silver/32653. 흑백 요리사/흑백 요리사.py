import random
import math

def main():
    n = int(input())
    a = list(map(int, input().split()))
    lcm=1
    for i in a:
        lcm=math.lcm(lcm,i)
    for i in a:
        if (lcm/i)%2==1:
            print(lcm+lcm)
            return
    print(lcm)


if __name__ == "__main__":
    main()
