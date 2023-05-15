def solution(money):
    type=50000 #시작점
    flag=0 #100원 될때 까지 flag로 진행
    money_return=list() #각 개수를 기록하는 곳
    for i in range(8):
        temp = money//type #갯수 임시 저장
        money_return.append(temp) #갯수를 기록
        money=money%type #남은 돈 계산을 위해 값을 바꿔줌
        if i<=4: #100원 되는 순간까지(type가 50000~500일 때) 5와 2로 바꿈
            if flag==0:
                flag=1 
                type//=5
            else:
                flag=0
                type//=2
            
        elif i<=6:#백원->십원, 십원->일원은 10으로 나누면 됨. 별도 처리
            type//=10
        else: #마지막은 아무 계산 없음.
            pass        
    return money_return #각 갯수가 들어있는 리스트를 리턴

def result_sentense(money, result): #계좌 금액과 갯수 기록한 리스트 받음.
    sen='' #문장 기록
    sen+=format(money,',d')+'원은'
    for i in range(8):
        if i<=3 and result[i]>0: #지폐관련 처리, 숫자 있을 때만 진입
            if i==0:
                sen+=' 5만 원권 '
            elif i==1:
                sen+=' 만 원권 '
            elif i==2:
                sen+=' 오천 원권 '
            elif i==3:
                sen+=' 천 원권 '
            sen+=str(result[i])+ '매,'
        elif i>=4 and result[i]>0: #동전 관련 처리, 숫자 있을 때만 진입
            if i==4:
                sen+=' 500원 동전 '
            elif i==5:
                sen+=' 100원 동전 '
            elif i==6:
                sen+=' 10원 동전 '
            elif i==7:
                sen+=' 1원 동전 '
            sen+=str(result[i])+'개,'
        else: #그외 예외처리
            pass

    sen=list(sen)#아래 if문, 문자열 대체 위해 처리

    if sen[-1]==',': #맨 끝은 ,를 빼주고 '로'로 대체
        sen[-1]='로'
    sen=''.join(s for s in sen)
    sen+=' 만들 수 있습니다.'

    return sen #문장 리턴

#정수 입력
bank_money=50237
#,로 처음부터 입력 받을 경우
#bank_money="50,237" 
#bank_money=int(bank_money.replace(',',''))

#결과 출력
bank_result=solution(bank_money) #갯수계산 함수 호출
print(result_sentense(bank_money,bank_result)) #문장 생성 함수 호출