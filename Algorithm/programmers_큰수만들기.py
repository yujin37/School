#테스트케이스 8,10 시간초과
def solution(number, k):
    answer=list(number)

    i=0
    cnt=len(answer)-1
    while i<cnt:
        if answer[i]<answer[i+1]:
            answer.pop(i)
            k-=1
            i=0
            if k==0:
                break
        else:
            i+=1

    if k!=0:
        answer=answer[:-k]
    return ''.join(answer)
    
print(solution('4177252841', 4))
#print(solution('1924',2))
#print(solution('1231234',3))
#print(solution('54321', 2))
#print(solution("1234567" , 3 ))