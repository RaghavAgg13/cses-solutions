n = int(input())
a = list(map(int, input().split()))

# print(1+a.count(1)+a.count(2)*2+a.count(3)*3+a.count(4)*4 and go on infinitum)

a.sort()

sum = a.count(1)
if 1 in a and 2 in a: cur = 3
elif 1 not in a: cur = 1
elif 2 not in a: cur = 2
else: cur = 0

if 1 in a: sum += a.count(2)*2
if 1 in a: 
    while 2 in a: a.remove(2)
while 1 in a: a.remove(1)

for i in a:
    if i == cur:
        sum += i
        cur += 1
    elif cur != 1:
        if i == cur + 1:
            cur += 2
            sum += i
        elif i <= sum+1:
            sum += i
            cur = i

print(sum+1)