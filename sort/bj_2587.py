def mean(arr):
    total = 0
    for i in range(len(arr)):
        total += arr[i]
    
    return total // len(arr)

def sorting(arr):
    for i in range(len(arr)):
        minimum = i
        for j in range(i+1, len(arr)):
            if arr[minimum] > arr[j]:
                minimum = j
        arr[i], arr[minimum] = arr[minimum], arr[i]
    
    return arr[2]

# arr =[int(input()) for _ in range(5)]
arr = []
for i in range(5):
    a = int(input())
    arr.append(a)

print(mean(arr))
print(sorting(arr))
