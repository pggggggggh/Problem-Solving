def solution(participant, completion):
    d = {}
    
    # participant의 모든 원소들을 돌면서 d에 값을 추가하는 코드
    for x in participant:
        if x not in d:
            d[x] = 0
        d[x] += 1
        
    # completion의 모든 원소들을 돌면서 d에 값을 1씩 빼는 코드
    for x in completion:
        # 여기는 participant에 없는 키가 들어올 리가 없으므로, if문 체크 안 해도 됨
        d[x] -= 1
    
    for key in d.keys():
        if d[key] != 0:
            return key
        