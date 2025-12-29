#회의실 배정

N = int(input())

arr = []

for i in range(N):
    arr.append(list(map(int, input().split())))

arr = sorted(arr, key = lambda x : (x[1], x[0]))

start = arr[0]
count = 1
for j in range(1, len(arr)):
    if arr[j][0] >= start[1]:
        count +=1
        start = arr[j]

print(count)
