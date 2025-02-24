a = input()
b = input()
ax = a.count("1")
bx = b.count("1")
if (ax + 1) // 2 >= (bx + 1) // 2:
    print("VICTORY")
else:
    print("DEFEAT")
