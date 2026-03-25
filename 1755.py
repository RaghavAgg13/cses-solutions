from collections import Counter
a = list(input())

b = Counter(a)

c = ''
odd = ''
got_odd = False
check = False
for item, freq in b.items():
    if not freq%2:
        c += item*((freq)//2)
    elif freq%2:
        if not got_odd:
            got_odd = True
            odd = item
            c += item*((freq)//2)
        else:
            check = True
            break

if check: print('NO SOLUTION')
else: print(c+odd+c[::-1])