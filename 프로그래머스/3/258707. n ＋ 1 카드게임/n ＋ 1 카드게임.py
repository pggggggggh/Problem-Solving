from collections import deque
import itertools

def solution(coin, cards):
    n = len(cards)
    having = {}
    for i in range(n//3):
        having[cards[i]] = having.get(cards[i],0)+1
    able = {}
    
    round = 1
    for i in range(n//3,n,2):
        able[cards[i]] = able.get(cards[i],0)+1
        able[cards[i+1]] = able.get(cards[i+1],0)+1
        
        flag = 0
        for k,v in having.items():
            if having.get(n+1-k,0) > 0:
                flag=1
                having[k] -= 1
                having[n+1-k] -= 1
                break
        if flag:
            round += 1
            continue
        
        for k,v in able.items():
            if having.get(n+1-k,0) > 0 and coin >= 1:
                flag = 1
                able[k] -= 1
                having[n+1-k] -= 1
                coin -= 1
                break
        
        if flag:
            round += 1
            continue
        
        for k,v in able.items():
            if able.get(n+1-k,0) > 0 and coin >= 2:
                flag = 1
                able[k] -= 1
                able[n+1-k] -= 1
                coin -= 2
                break
                
        if flag:
            round += 1
            continue
        
        break
        
        
    return round