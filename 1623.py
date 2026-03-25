ans = 1000000000000000
def recur(pos, left, right, n, arr):
    global ans
    if (pos == n):
        if abs(left-right) < ans: ans = abs(left-right)
        return

    recur(pos+1, left+arr[pos], right, n, arr)
    recur(pos+1, left, right+arr[pos], n, arr)

n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)

recur(0, 0, 0, n, a)
print(ans)
