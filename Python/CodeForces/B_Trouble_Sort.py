def insertionSort(arr, b): 
  
    # Traverse through 1 to len(arr) 
    for i in range(1, len(arr)): 
  
        key = arr[i] 
  
        # Move elements of arr[0..i-1], that are 
        # greater than key, to one position ahead 
        # of their current position 
        j = i-1
        while j >=0 and key < arr[j] and b[i] != b[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key 
t = int(input())
for i in range(t):
    n = int(input())
    inp = input()
    a = list(map(int, inp.split()))
    inp = input()
    b = list(map(int, inp.split()))
# =============================================================================
#     for i in range(0, n-1):
#         for j in range(i+1, n):
#             if((a[i] > a[j]) and (b[i] != b[j])):
#                 a[i], a[j] = a[j], a[i]
#                 b[i], b[j] = b[j], b[i]
# =============================================================================
# =============================================================================
#     for i in range(len(a)): 
#           
#         # Find the minimum element in remaining  
#         # unsorted array 
#         min_idx = i 
#         for j in range(i+1, len(a)): 
#             if (a[min_idx] > a[j]) and (b[min_idx] != b[j]): 
#                 min_idx = j 
#                   
#         # Swap the found minimum element with  
#         # the first element         
#         a[i], a[min_idx] = a[min_idx], a[i] 
#         b[i], b[min_idx] = b[min_idx], b[i] 
# =============================================================================
    insertionSort(a,b)
    flag = 0
    for i in range(1, n):
        if (a[i-1] > a[i]):
            flag = 1
    if(not flag) :
        print("Yes")
    else:
        print("No")