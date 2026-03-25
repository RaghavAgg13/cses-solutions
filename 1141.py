from sys import stdin
input = stdin.readline

n = int(input())
a = list(map(int, input().split()))
 
seen = set()
cnt = 0
l = 0
for i in range(n):
    if a[i] not in seen: 
        seen.add(a[i])
        if len(seen) > cnt: cnt = len(seen)
    else:
        while a[i] in seen:
            seen.remove(a[l])
            l += 1

        seen.add(a[i])
        if len(seen) > cnt: cnt = len(seen)
    
print(cnt)