from math import factorial as fact
a = list(input())
n = len(a)

a.sort()
dict = []
print(fact(n)//fact(len(set(a))))
for i in range(n-1):
    for j in range(1, n):
        a[i], a[j] = a[j], a[i]
        b = "".join(a)
        if b not in a: dict.append(b)

print(*set(dict), sep='\n')
