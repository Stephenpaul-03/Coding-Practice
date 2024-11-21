def merge(arr, left, mid1, mid2, right):
    temp = []
    i, j, k = left, mid1 + 1, mid2 + 1

    while i <= mid1 and j <= mid2 and k <= right:
        if arr[i] <= arr[j] and arr[i] <= arr[k]:
            temp.append(arr[i])
            i += 1
        elif arr[j] <= arr[i] and arr[j] <= arr[k]:
            temp.append(arr[j])
            j += 1
        else:
            temp.append(arr[k])
            k += 1

    while i <= mid1 and j <= mid2:
        temp.append(arr[i] if arr[i] <= arr[j] else arr[j])
        i += 1 if arr[i] <= arr[j] else 0
        j += 1 if arr[j] < arr[i] else 0

    while j <= mid2 and k <= right:
        temp.append(arr[j] if arr[j] <= arr[k] else arr[k])
        j += 1 if arr[j] <= arr[k] else 0
        k += 1 if arr[k] < arr[j] else 0

    while i <= mid1 and k <= right:
        temp.append(arr[i] if arr[i] <= arr[k] else arr[k])
        i += 1 if arr[i] <= arr[k] else 0
        k += 1 if arr[k] < arr[i] else 0

    while i <= mid1:
        temp.append(arr[i])
        i += 1
    while j <= mid2:
        temp.append(arr[j])
        j += 1
    while k <= right:
        temp.append(arr[k])
        k += 1

    for idx, val in enumerate(temp):
        arr[left + idx] = val

def ternary_sort(arr, left, right):
    if left >= right:
        return

    third = (right - left) // 3
    mid1 = left + third
    mid2 = right - third

    ternary_sort(arr, left, mid1)
    ternary_sort(arr, mid1 + 1, mid2)
    ternary_sort(arr, mid2 + 1, right)

    merge(arr, left, mid1, mid2, right)




t = int(input("Enter Test Case Count: "))
for _ in range(t):
    arr = list(map(int, input("Enter array elements: ").split()))
    ternary_sort(arr, 0, len(arr) - 1)
    print("Sorted array:", *arr)

