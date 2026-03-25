a = input()
n = len(a)

max_cnt = 1
cur_freq = 1
for i in range(1, n):
    if a[i] == a[i-1]:
        cur_freq += 1
    else:
        max_cnt = max(max_cnt, cur_freq)
        cur_freq = 1

max_cnt = max(max_cnt, cur_freq)
print(max_cnt)