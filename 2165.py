def recur(n, start, mid, end):
    if n == 1: 
        print(start, end)
        return

    recur(n-1, start, end, mid)
    print(start, end)
    recur(n-1, mid, start, end)

n = int(input())

print(2**n-1)
recur(n, 1, 2, 3)