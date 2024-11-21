def interpolation_idx(arr, low, high, key):
    if low <= high:
        pos = low + ((key - arr[low]) * (high - low)) // (arr[high] - arr[low])
        if arr[pos] == key:
            return pos
        elif arr[pos] < key:
            return interpolation_idx(arr, pos + 1, high, key)
        else:
            return interpolation_idx(arr, low, pos - 1, key)
    return -1

def interpolation_sort(arr):
    n = len(arr)
    for i in range(n):
        key = arr[i]
        index = interpolation_idx(arr, i + 1, n - 1, key)
        if index != -1 and arr[index] != key:
            arr[i], arr[index] = arr[index], arr[i]

t = int(input())
for _ in range(t):
    n = int(input("Enter number of elements: "))
    arr = list(map(int, input("Enter elements: ").split()))

    interpolation_sort(arr)

    print("Sorted Array:", arr)
