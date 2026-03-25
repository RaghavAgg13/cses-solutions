n = int(input())

if not n%4 or not (n+1)%4:
    print('YES')
    if not n%4:
        print(n//2)
        for i in range(1, n//4+1): print(i, n-i+1, end=' ')
        print()
        print(n//2)
        for i in range(n//4+1, n//2+1): print(i, n-i+1, end=' ')

    else:
        a = [1,2]
        b = [3]

        for i in range(4 , n+1):
            if not i%4 or i%4 == 3:
                a.append(i)
            else: b.append(i)

        print(len(a))
        print(*a)
        print(len(b))
        print(*b)

else:
    print('NO')