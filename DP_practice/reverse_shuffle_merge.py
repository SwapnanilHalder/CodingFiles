from os import system
system('clear')

# yy[x]z[y][z]yxxx   [x][y][z]yx    [x][y][z]y(x)
# # s = 'cbcabaababcbcb' # bcbcbabaabacbc
target = 'agfedcb'
s = 'abcdefgabcdefg'
soja = s[::-1]
print("rev array : ", soja)
target = '' # ababcbc # aabbbcc
dicto = {}
bestArr =''
ansArr = ''

def makeDict(a):
    dicto ={}
    for i in range(len(a)):
        if(a[i] not in dicto.keys()):
            dicto[a[i]] = [i]
        else:
            dicto[a[i]].append(i)
    print(dicto)
    return dicto

def bestArray(dicto) :
    t =''
    global bestArr
    for x in dicto:
        t += int(len(dicto[x])/2) * x
    bestArr = ''.join(sorted(t))
    print("best array : ", bestArr)
    return bestArr

bestArray(makeDict(soja))

def countDict(dicto):
    temp = {}
    for x in dicto:
        temp[x] = len(dicto[x])
    return temp


def greedy(mainDict, ansArr, bestArr):
    lenDict = countDict(mainDict)
    temp = ''
    reqDict = makeDict(bestArr)
    lenReqDict = countDict(reqDict)
    print(lenDict)
    print(lenReqDict)
    


greedy(makeDict(s), ansArr, bestArr)





























# 

# def recursion(substr, dict, bestsub):
#     recursion(substr + best[1], dict, best)
#     recursion(best[1] + substr, dict, best)

# recursion(dict, best[0], best)

# print('best : ', contains(dict, best))
# print('target : ', contains(dict, target))
# # print("bagggg : ", contains(dict, 'bagggg'))
# # print("ddgc : ", contains(dict, 'ddgc'))
# # best : ccbbbaa




# # print("The Dictionary : \n", dict)
# print("Best Solution : " , bestArray(dict))
# print("Soja dict : \t" , dict)

#def contains(dict, str):
    #     found = 0
#     store = []
#     for x in str:
#         store.append(dict[x])
#     # print(store)
#     mini = min(store[0])
#     # print("primary mini : ", mini)
#     for i in range(1, len(store)):
#         found = 0
#         for j in range(len(store[i])): 
#             # # print(i, " ", j, " : ", store[i][j])
#             try:
#                 if(j == 0 and store[i][j] > mini):
#                     # print("entered if")
#                     mini = store[i][j]
#                     found = 1
#                     # print("mini ", mini)
#                     break
#                 elif(store[i][j] <= mini and store[i][j+1]> mini):
#                     # print('entered elif')
#                     mini = store[i][j+1]
#                     # print("mini : ", mini)
#                     found = 1
#                     break
#                 elif(j == len(store[i]) - 1):
#                     # print("I dunno what to do")
#                     # print("break")
#                     return 0
#             except:
#                 # print("break")
#                 return 0
#                 found = 0
#     if(found == 1):
#         return 1