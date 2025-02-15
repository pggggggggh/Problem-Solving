def base_repr(x,base):
    if x==0:
        return "0"
    result=""
    while x>0:
        result = str(x%base)+result
        x//=base
    return result

def solution(expressions):
    answer = []
    candi = [set() for i in range(len(expressions))]
    good = set()
    for jinbub in range(2,10):
        flag = 1
        for (i,expression) in enumerate(expressions):
            [sa,op,sb,foo,sc] = expression.split()
            try:
                a = int(sa,jinbub)
                b = int(sb,jinbub)
                if sc == 'X':
                    continue
                c = int(sc,jinbub)
                if op == '+' and a+b != c:
                    flag = 0
                    break
                if op == '-' and a-b!= c:
                    flag = 0
                    break
            except Exception as e:
                flag = 0
                break
        if flag: good.add(jinbub)
    
    for jinbub in good:
        for (i,expression) in enumerate(expressions):
            [sa,op,sb,foo,sc] = expression.split()
            a = int(sa,jinbub)
            b = int(sb,jinbub)
            if sc != 'X':
                continue
            if op == '+':
                candi[i].add(base_repr(a+b,jinbub))
            if op == '-':
                candi[i].add(base_repr(a-b,jinbub))
    res = []
    for (i,expression) in enumerate(expressions):
        [sa,op,sb,foo,sc] = expression.split()
        
        if sc == 'X':
            if len(candi[i]) != 1:
                res.append(expression.replace('X','?'))
                continue
            res.append(expression.replace('X',max(candi[i])))
    return res