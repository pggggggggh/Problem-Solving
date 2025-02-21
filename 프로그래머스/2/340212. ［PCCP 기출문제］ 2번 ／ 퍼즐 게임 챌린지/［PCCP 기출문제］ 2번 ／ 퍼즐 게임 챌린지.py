def solution(diffs, times, limit):
    lo=0
    hi=10**18
    
    while lo+1<hi:
        mid = lo+hi>>1
        
        cur = 0
        for i in range(len(diffs)):
            if diffs[i] <= mid:
                cur += times[i]
            else:
                cur += (diffs[i]-mid)*(times[i]+times[i-1])+times[i]
        
        if cur <= limit:
            hi = mid
        else:
            lo = mid
    return hi