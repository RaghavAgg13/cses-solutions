n,x = list(map(int, input().split()))
a = list(map(int, input().split()))

a.sort()
count = 0

if n == 1:
    print(1)
elif x >= a[-1]+a[-2]:
    count = n//2+n%2
else:
    left, right = 0, n-1
    while left <= right:
        if left == right:
            count += 1
            break

        if a[left]+a[right] <= x:
            left += 1
            right -= 1
        else:
            right -= 1
        
        count += 1

print(count)