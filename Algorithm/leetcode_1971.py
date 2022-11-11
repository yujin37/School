class Solution:
    def validPath(self, n: int, edges: list[list[int]], source: int, destination: int) -> bool:
        p=[0]*(n)

        def make_set(x):
            p[x]=x
            
        def union(x,y):
            p[find_set(y)]=find_set(x)
        
        def find_set(x):
            if x==p[x]:
                return x
            else:
                return find_set(p[x])

        for i in range(n):
            make_set(i)
            
        for i in edges:
            union(i[0], i[1])
        print(edges)
        if find_set(source)==find_set(destination):
            return True
        else:
            return False
            