n = int(input())

for i in range(n):
    y,x = list(map(int, input().split()))
    
    num = x**2-x+1

    if x > y:
        if x%2:
            num = (x)**2-y+1
        else:
            num = (x-1)**2+y
    elif y > x:
        if y%2:
            num = x+(y-1)**2
        else:
            num = -x+1+(y)**2

    print(num)