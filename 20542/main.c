def editDistance(str1, str2):
    dist = [[0 for j in range(len(str1)+1)] for i in range(len(str2)+1)]
    
    for i in range(1, len(str2)+1):
        dist[i][0] = i
    
    for i in range(1, len(str1)+1):
        dist[0][i] = i
    
    for i in range(1, len(str2)+1):
        for j in range(1, len(str1)+1):

            if str1[j-1] == "i" and (str2[i-1] == 'j' or str2[i-1] == 'l'):
                str1 = str1.replace('i', str2[i-1])

            if str1[j-1] == "v" and str2[i-1] == "w":
                str1 = str1.replace("v", str2[i-1])

            if str2[i-1] == str1[j-1]:
                dist[i][j] = dist[i-1][j-1]
            else:
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1])+1
    return dist[len(str2)][len(str1)]

n, m = input().split()
n = int(n)
m = int(m)
str1 = input() # 승연
str2 = input() # 정답(기준)

print(editDistance(str1, str2))
