import sys
sys.setrecursionlimit(1000005)

memo = {}

def recur(n):
    if n == 0: return 0
    if n in memo: return memo[n]

    s = float('inf')
    for i in list(str(n)):
        digit = int(i)
        if digit: s = min(s, recur(n-digit)+1)
    
    memo[n] = s
    return s


n = int(input())
print(recur(n))