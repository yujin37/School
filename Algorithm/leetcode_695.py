class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        area={}
        grid_x=len(grid[0])
        grid_y=len(grid)
  
        p={}
        def make_set(x):
            p[x]=x
        
        def union(x,y):
            rx=find(x)
            ry=find(y)
            if rx and ry and rx!=ry:
                p[rx]=ry
                area[ry] += area[rx]
        def find(x):
            if not x in p:
                return None
            if p[x]!=x:
                p[x]=find(p[x])
            return p[x]
        
        for i in range(grid_y):
            for j in range(grid_x):
                make_set((i,j))
        for i in range(grid_y):
            for j in range(grid_x):
                if grid[i][j]==1:
                    area[(i,j)]=1
                    #if i-1<0 or j-1<0 :
                        #continue
                    if grid[i-1][j]==1:
                        union((i-1,j),(i,j))
                    if grid[i][j-1]==1:
                        union((i,j-1), (i,j))
                else:
                    area[(i,j)]=0
                

        print(area)
        return max(area.values())
     
