s = input()
sum = 0
cnt = 0
for i in range(len(s)):
    if s[i] == "0":
        sum += i
        cnt += 1
for i in range(cnt):
    sum -= i
if sum % 3 == 0:
    print("Bob")
else:
    print("Alice")
