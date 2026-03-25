from collections import defaultdict
n = int(input())
a = list(input().split())

freq = defaultdict(int)
for i in a: 
    freq[i] += 1

count = 0
for item in freq:
    count += 1
print(count)