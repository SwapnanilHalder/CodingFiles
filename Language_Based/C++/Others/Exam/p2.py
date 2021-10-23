

def calCount(arr):
    dp = {}
    dp[len(arr)-1] = [True,"a"]
    for i in range(len(arr) - 2,-1,-1):
        if arr[i] > arr[i+1]:
            t = "d"
            if dp[i+1][1] == "a" or dp[i+1][1] == "i":
                dp[i] = [True and dp[i+1][0], "d"]
            else:
                dp[i] = [False, "d"]
        else:
            t = "i"
            if dp[i+1][1] == "a" or dp[i+1][1] == "d":
                dp[i] = [True and dp[i+1][0], "i"]
            else:
                dp[i] = [False, "i"]
    print(dp)
    dp_end = {}
    dp_end[0] = [True,"a"]
    for i in range(1, len(arr)):
        if arr[i] < arr[i-1]:
            t = "d"
            if dp_end[i-1][1] == "a" or dp_end[i-1][1] == "i":
                dp_end[i] = [True and dp_end[i-1][0], "d"]
            else:
                dp_end[i] = [False, "d"]
        else:
            t = "i"
            if dp_end[i-1][1] == "a" or dp_end[i-1][1] == "d":
                dp_end[i] = [True and dp_end[i-1][0], "i"]
            else:
                dp_end[i] = [False, "i"]
                
    print(dp_end)            
    if dp[0] == True:
        return 0

    count = -1

    if dp[1][0] == True:
        print("true 1")
        count = count+1
    if dp_end[len(arr)-2][0] == True:
        print("true 2")
        count = count+1
    print("count : ", count)    
    for i in range(1,len(arr)-1):
        print("i : ", i)
        t = "n"
        if arr[i-1] > arr[i+1]:
            t = "d"
        elif arr[i-1] < arr[i+1]:
            t = "i"
        print("t : ", t)
        if t != dp[i+1][1] and dp[i+1][0] == True and dp_end[i-1][0] == True :
            count = count +1
        print("count : ", count)
#     print(count)
    
    if count == 0:
        return -1
    return count+1
def main():
    s = input()
    arr = list(map(int,s.split()))
    print(arr)
    print(calCount(arr))
main()