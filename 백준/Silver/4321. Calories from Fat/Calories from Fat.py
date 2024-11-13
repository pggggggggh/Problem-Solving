flag = 1
cals = [0 for _ in range(5)]
prop = [9, 4, 4, 4, 7]
while True:
    inp = input()
    if inp == "-":
        if flag:
            break
        print(str(round(cals[0] * 100 / sum(cals))) + "%")
        cals = [0 for _ in range(5)]
        flag = 1
        continue
    s = list(inp.split())
    perc = 0
    tot = 0
    for i in range(5):
        if s[i][-1] == "%":
            perc += int(s[i][:-1])
        elif s[i][-1] == "g":
            tot += int(s[i][:-1]) * prop[i]
            cals[i] += int(s[i][:-1]) * prop[i]
        else:
            tot += int(s[i][:-1])
            cals[i] += int(s[i][:-1])
    realtot = 100 / (100 - perc) * tot
    for i in range(5):
        if s[i][-1] == "%":
            cals[i] += int(s[i][:-1]) / 100 * realtot
    flag = 0
