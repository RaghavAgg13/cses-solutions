n = int(input())
a = list(range(1, n+1))

final = []

while len(a) > 1:
    b = []
    n_ = len(a)
    
    for i in range(n_):
        if i%2:
            final.append(a[i])
        else:
            b.append(a[i])
    
    if n_%2:
        last_survivor = b.pop()
        b.insert(0, last_survivor)
    
    a = b

if a: final.append(a[0])
print(*final)