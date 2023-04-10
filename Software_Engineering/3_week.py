def solution(n,c,nums):
    order=dict() #딕녀너리로 빈도수 체크
    result=[]#최종 결과 리턴을 위한 리스트
    for item in nums: #빈도수 카운트
        if item in order:
            order[item]+=1
        else:
            order[item]=1

    sorted_items = sorted(order.items(), key=lambda x: (-x[1], nums.index(x[0])))
    #빈도수 높은 것을 정렬하되 같은 빈도수라면 처음 리스트에 등장하는 인덱스 기준
    for item, freq in sorted_items: #최종 결과 리스트 생성
        for _ in range(freq): #빈도수만큼 반복
            result.append(item) #해당 키 부분 출력
        
    return result #결과 리턴

n,c=11,6
nums=[6,2,1,1,1,2,2,3,3,3,3]

print(solution(n,c,nums))
