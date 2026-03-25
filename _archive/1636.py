def recur(sum, x, c, idx):
    if sum == x: return 1
    if sum > x: return 0

    s = 0
    for i in range(idx, n):
        s += recur(sum+c[i],x,c,i)
    return s

n,x = list(map(int, input().split()))
c = list(map(int, input().split()))

a = recur(0, x, c, 0)
print(a)