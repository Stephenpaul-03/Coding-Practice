def bubble(arr):
    n = len(arr)
    for i in range(n):
        flag = False
        for j in range(0,n-i-1):
            if arr[j+1]<arr[j]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
                flag = True
        if flag == False:
            break
    return arr

t = int(input())
for _ in range(t):
    arr = list(map(int,input().split()))
    Sort = bubble(arr)
    for i in range(len(Sort)):
        print(Sort[i], end =" ") 
