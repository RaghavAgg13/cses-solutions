n = int(input())
for i in range(2**n):
    n1 = i ^ (i >> 1)
    print(f"{n1:0{n}b}")