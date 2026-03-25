n = int(input())
a = list(map(int, input().split()))

a.sort()

s = sum(a)
if s - a[-1] > a[-1]:
    buffer = s - a[-1]
else:
    buffer = a[-1]

print(buffer+a[-1])