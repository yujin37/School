class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        area={}
        grid_x=len(grid[0])
        grid_y=len(grid)
        cnt=0
        p=[[0]*grid_x for _ in range(grid_y)]
        
        def make_set(y,x):#이건 자기자신을 가르키도록
            p[y][x]=(y,x)
        
        def union(x,y):#합치는게 문제인데
            r1=find_set(x)
            r2=find_set(y)
            t1,t2=x[0],x[1]
            r11,r12=r1[0],r1[1]
            #print(r1, r2)
  
            if r1!=r2 and ((r11+1,r12)==r2 or (r11,r12+1)==r2):
                p[t1][t2]=r2
                area[r2] += area[r1]
                
        def find_set(x):#parent 와 비교
            t1,t2=x[0],x[1]
            if x==p[t1][t2]: #이건 자기자신 가르킬 때하는거고.
                return x
            else:
                return find_set(p[t1][t2])#아니면 이걸로 리턴해준다?
 
        for i in range(grid_y):#이건 부모노드 자기자신
            for j in range(grid_x):
                make_set(i,j)
        for i in range(grid_y):
            for j in range(grid_x):#그게 아니라 어떻게 연결된걸 찾으면서 개수를 세냐고.
                if grid[i][j]==1:
                    area[(i,j)]=1
                else:
                    area[(i,j)]=0
                    continue
                if i-1<0 and j-1<0:
                    continue
                if i-1<0:
                    union((i,j-1), (i,j))
                if j-1<0:
                    union((i-1,j),(i,j))
                else:
                    union((i-1,j),(i,j))
                    union((i,j-1), (i,j))
                    
                print(p)
                
                    
                    
        #test=area.values() 
        #print(area)
        return max(area.values())
     