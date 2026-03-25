n = int(input())
a = list(map(int, input().split()))

# count = 0
# last = 0
# while last != n:
#     count += 1
#     for i in range(n):
#         if a[i] == last+1:
#             last += 1

# print(count)

positions = [0]*(n+1)
for i in range(n):
    positions[a[i]] = i

count = 1
for i in range(2, n+1):
    if positions[i] < positions[i-1]: count += 1

print(count)