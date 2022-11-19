class Solution:
                
            
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        cnt=0
        times_s=collections.defaultdict(list)
        inf=1e9
        distance=[0]*101
        visited=[0]*101
        #def smallest(num):
            
        def dijkstra(n,k):
            q=[(0,k)]
            dist = collections.defaultdict(int)
            while q:
                time, node = heapq.heappop(q)
                if node not in dist:
                    dist[node]=time
                    for v,w in times_s[node]:
                        alt=time+w
                        heapq.heappush(q, (alt, v))
            dist=dict(dist)
            #print(dist)
            if len(dist)==n:
                return max(dist.values())
            return -1  
        for i in range(len(times)):
            if times[i][0] in times_s:
                times_s[times[i][0]].append((times[i][1], times[i][2]))
            else:
                times_s[times[i][0]]=[(times[i][1], times[i][2])]

        #print(times_s)
        
        return dijkstra(n,k)
        