n, m = input().split(' ')
n = int(n)
m = int(m)

for i in range(m):
    k = int(input())
    l = -1
    r = n
    count = 0
    while l + 1 < r:
        count += 1
        mid = int((l + r) / 2)
        if mid < k:
            l = mid
        elif mid > k:
            r = mid
        else:
            print(count)
            break


