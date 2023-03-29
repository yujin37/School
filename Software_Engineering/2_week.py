def solution(s, skip, index):
    answer = '' 
    s=list(s) #연산을 위해 문자열을 리스트로 변환환
    for i in range(len(s)):
        chan=ord(s[i]) #아스키 10진으로 변환
        setting=0 #index까지 카운트할 변수
        while True:
            if setting==index: #만약 index까지 연산하면 중지
                chan=chr(chan) #다시 문자열로 변환
                break
            else:
                chan+=1 #아스키코드에서 다음 숫자로 이동
                if chan == 123: #'z'를 벗어난 경우
                    chan=97 #'a'로 다시 설정
                if not chr(chan) in skip: #만약 skip에 해당 문자가 없다면
                    setting+=1 #연산이 성공했으므로 index의 증가
                else: #만약 skip에 해당 문자 존재하면 다시 반복
                    continue
        answer+=chan #특정 인덱스의 최종 결과 저장
    return answer

s="aukks"
skip="wbqd"
index=5
print(solution(s,skip,index))