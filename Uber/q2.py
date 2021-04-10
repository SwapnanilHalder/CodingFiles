def getPowerCouple2021(friends_nodes, friends_edges, friends_from, friends_to, friends_weight):
    D = {}
    itr = -1
    for i in friends_weight:
        itr += 1
        if i not in D:
            D[i] = [friends_from[itr], friends_to[itr]]
        else:
            D[i].append(friends_from[itr])
            D[i].append(friends_to[itr])
    
    for i in D:
        D[i] = set(D[i])
    
    pair = {}
    for idx in D:
        temp = list(D[idx])
        for i in range(len(temp)):
            for j in range(i+1, len(temp)):
                a = temp[i]
                b = temp[j]
                p = (a,b)
                if p not in pair:
                    pair[p] = 1
                else:
                    pair[p] += 1
    
    result = sorted(pair.items(), reverse = True, key = lambda x: (x[1],x[0][0]*x[0][1]))
    ans = result[0][0][0] * result[0][0][1]    
    return ans


# if __name__ == "__main__":
#     friends_nodes = int(input())
#     friends_edges = int(input())
#     friends_from = [int(i) for i in input().split()]
#     friends_to = [int(i) for i in input().split()]
#     friends_weight = [int(i) for i in input().split()]
#     print(getPowerCouple2021(friends_nodes, friends_edges, friends_from, friends_to, friends_weight))        