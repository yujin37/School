from collections import deque

def how_many_move(board, loc_x, loc_y, mloc_x, mloc_y):
    if loc_x == mloc_x and loc_y == mloc_y: #이동위치와 위치가 같으면 바로 종료
        return 0 #아무것도 하지 않았으므로 0으로 리턴
    dx = [-2,-1,1,2,2,1,-1,-2] #나이트가 이동 가능한 x위치
    dy = [-1,-2,-2,-1,1,2,2,1] #나이트가 이동 가능한 y위치
    chess_board=[[0 for _ in range(board)] for _ in range(board)] #체스 보드 생성
    queue = deque() #해당 위치에서 주변을 봄으로 bfs로 풀기 위해 deque 사용
    queue.append((loc_x,loc_y)) #deque의 초기값을 넣어준다.
    while queue:
        n = queue.popleft() #현재 위치를 뽑아서
        if n[0]==mloc_x and n[1]==mloc_y: #만약 위치가 목표 위치랑 같으면 종료
            break #break로 나가서 return 한다.
        for i in range(8): #갈 수 있는 방향 탐색
            check_dx=n[0]+dx[i] #x위치 기록
            check_dy=n[1]+dy[i] #y위치 기록
            if check_dx<0 or check_dy<0 or check_dx>=board or check_dy>=board: 
                continue #보드 밖에 나가면 진행 x
            if chess_board[check_dx][check_dy] == 0: #아니면 계속 진행
                chess_board[check_dx][check_dy] = chess_board[n[0]][n[1]]+1 #이전 이동에서 +1 해서 기록
                queue.append((check_dx, check_dy)) # 그 주변을 다시 탐색해줘야 하므로 queue에 담는다.
            else: #에러 방지를 위한 else문
                pass
    return chess_board[mloc_x][mloc_y] #결과 리턴
    
#입력
board=8
loc_x,loc_y=0,0
mloc_x,mloc_y=7, 0
print("체스판의 크기:", end=" ")
print(board) #예시 입력 바로 출력
#board=int(input()) #입력용
print("나이트의 위치:", end=" ")
print(loc_x, loc_y) #예시 입력 바로 출력
#loc_x, loc_y=map(int,input().split()) #입력용
print("나이트의 이동 위치:", end=" ")
#mloc_x, mloc_y=map(int,input().split()) #입력용
print(mloc_x, mloc_y) #예시 입력 바로 출력
print('나이트의 최소 이동 횟수:', end=' ')
print(how_many_move(board, loc_x, loc_y, mloc_x, mloc_y))