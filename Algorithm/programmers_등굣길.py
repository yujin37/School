def solution(m, n, puddles):
    answer = 0
    road=[[0]*m for _ in range(n)]

    road[0][0]=1
    for i in range(len(puddles)):
        puddles[i][0]-=1
        puddles[i][1]-=1
        
    flag=0
    for i in range(1,m):
        if [i, 0] in puddles:
            flag=1
        if flag==0:
            road[0][i]=1
                
    flag=0
    for i in range(1,n):
        if [0, i] in puddles:
            flag=1
        if flag==0:
            road[i][0]=1
                
    for i in range(n):
        for j in range(m):
            if road[i][j]==0:

                if [j,i] in puddles or [i,j]==[0,0]:
                    continue
                else:
                    if (i==0):
                        road[i][j]=road[i][j-1]%1000000007
                    elif (j==0):
                        road[i][j]=road[i-1][j]%1000000007
                    else:
                        road[i][j]=(road[i-1][j]+road[i][j-1])%1000000007
    
   
    answer=road[-1][-1]
    return answer
