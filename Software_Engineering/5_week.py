def seperate(p): #왼쪽 오른쪽 분리하기
    left=0
    right=0
    for i in range(len(p)):
        if p[i]=='(': #왼쪽
            left+=1
        else: #오른쪽 갯수
            right+=1
        if left==right: #만약  균형이 잡히면 u로, 나머진 v로
            u=p[:i+1]
            v=p[i+1:]
            return u,v
def check(p): #올바른 괄호 문자열인지 체크
    cnt=0
    for i in range(len(p)):
        if p[i] == '(': #(가 나오면 갯수 올리고
            cnt+=1
        else: #)가 나오면 갯수 내린다.
            cnt-=1
        if cnt<0: #만약 )가 (보다 먼저 나오게 되면 음수 발생
            return False #그런 경우 false 반환
    return True #균형 잡히면 true반환
    

def solution(p):
    answer=''
    if check(p)==True: #완벽한 괄호라면 바로 반환
        return p
    else: #아니면 아래 계산 진행
        u,v=seperate(p) #1차로 분리하고
        if check(u): #올바른 괄호 문자열이면
            return u+solution(v) #u는 처리되었으므로 v에 대해 처리한다.
        else: #올바른 괄호 문자열이 아니라면
            u=u[1:-1] #u의 앞뒤 문자 제거
            u=list(u) #아래 for문을 이용해 뒤집기 위해 임시 리스트변환
            for i in range(len(u)): #나머지 문자 괄호 방향 뒤집기
                if u[i]=='(':
                    u[i]=')'
                else:
                    u[i]='('
            u=''.join(u) #리스트 변환한 것을 다시 문자열로
            answer+='(' #설명에 따르면 괄호 넣고
            answer+=solution(v) #v에 대해서도 균형 체크해서 
            answer+=')'#뒤에도 괄호 넣으라고 되어있음.
            answer+=u #그리고 마지막에 u를 다시 붙인다.
        return answer
        

#p='(()())()'
#p=')('
#p='()))((()'
p=')))((('
print(solution(p))