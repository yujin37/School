from collections import deque

def solution(c,b):
    c_time=0 #전체 시간 기록
    brown=deque() #브라운의 이동 경로를 기록할 deque
    brown.append((0,b)) #최초 계산을 위한 세팅
    visited =[{} for _ in range(200001)] #방문기록 
    cony=c #코니위치를 cony라고 설정해서 진행

    while cony<=200000: #코니가 200000까지 움직일 수 있는 범위라고 되어있음
        c_time+=1 #먼저 시간을 1초 증가하고
        cony+=c_time #코니는 c_time초 만큼 움직이므로 더해줌

        #아래는 브라운이 이동하는 방법
        for _ in range(0,len(brown)): #브라운의 이동 경로를 모두 계산
            time,loc=brown.popleft() #딕셔너리에 있는 값을 뽑아서 진행
            t_time=time+1 #기존에 기록된 시간에 1을 더해서 
            b_loc=loc #그리고 경로도 계산하기 위해 별도 변수 선언, 초기화 해야 하므로.

            if 0<=b_loc-1 and b_loc<=200000: #b-1만큼 이동할 경우
                visited[b_loc-1][t_time]=True #b_loc에 t_time을 생성해 true라고 기록
                brown.append((t_time,b_loc-1)) #그리고 이후 결과는 다음에 올때 계산 위해 deque 추가
            b_loc=loc #위의 결과를 초기화하고
            if 0<=b_loc+1 and b_loc<=200000: #b+1만큼 이동할 경우
                visited[b_loc+1][t_time]=True #b_loc에 t_time을 생성해 true라고 기록
                brown.append((t_time,b_loc+1)) #그리고 이후 결과는 다음에 올때 계산 위해 deque 추가
            b_loc=loc #위의 결과를 초기화하고
            if 0<=b_loc*2 and b_loc<=200000: #b*2만큼 이동할 경우
                visited[b_loc*2][t_time]=True #b_loc에 t_time을 생성해 true라고 기록
                brown.append((t_time,b_loc*2)) #그리고 이후 결과는 다음에 올때 계산 위해 deque 추가

        if c_time in visited[cony]: #visited에서 cony 위치에 c_time인 키가 있으면
            return c_time #c_time을 리턴.
        #visited에 c_time 이전에 방문할 수 있다고 기록했더라도 브라운이 도착하지 못했기 때문에
        #visited 중 cony 위치의 c_time에 대한 것이 코니를 잡을 수 있는 위치가 된다.
            
c,b=11,2
#c,b=11,1 #라인 코드 설명에서의 반례체크, 6초 도착
#c,b=6,3 #라인 코드 설명에서의 반례 체크, 4초 도착
print(solution(c,b))