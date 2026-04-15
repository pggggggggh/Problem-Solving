def solution(num_list):
    answer = 0
    for num in num_list:
        x = num
        
        while x!=1:
            if x%2==0:
                x//=2
            else:
                x=(x-1)//2
            answer+=1
        
    return answer