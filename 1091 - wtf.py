n,m = list(map(int, input().split()))
h = list(map(int, input().split()))
t = list(map(int, input().split()))

h.sort()

parent = list(range(n))

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

for i in t:
    ans = -1
    left, right = 0, len(h)-1
    while left <= right:
        middle = (right+left)//2

        if h[middle] <= i:
            ans = middle
            left = middle+1
        else:
            right = middle-1

    if ans == -1:
        print(-1)
    else:
        idx = find(ans)
        if idx == -1 or h[idx] > i:
            print(-1)
        else:
            print(h[idx])
            parent[idx] = find(idx - 1) 
