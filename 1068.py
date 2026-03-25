n = int(input())

print(n, end=' ')
while n != 1:
    if not n%2: n //= 2
    else: n = n*3 +1

    print(n, end=' ')