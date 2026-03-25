for i in range(int(input())):
    a,b = list(map(int, input().split()))

    if not (a+b)%3 and max(a,b) <= 2 * min(a,b):
        print('YES')
    else:
        print('NO')