class Solution:
    def findCircleNum(self, isConnected: list[list[int]]) -> int:
        #일단 기준을 세우고 make set
        #union을 통해 합치게 되면 한개씩 빼준다. union
        #출력? result
        p=[0]*len(isConnected[0])
        
        def make_set(x):
            p[i]=i

        def union(x,y):
            rx=find(x)
            ry=find(y)
            if rx!=ry:
                p[rx]=ry
            
        def find(x):
            if x==p[x]:
                return x
            else:
                return find(p[x])

        for i in range(len(isConnected)):
            make_set(i)
        
        for i in range(len(isConnected)):
            for j in range(len(isConnected[i])):

                if isConnected[i][j]==1 and i!=j:
                    union(i,j)
                    
        cnt=len(isConnected)
        for i in range(len(p)):
            if p[i]!=i:
                cnt-=1
        return cnt
