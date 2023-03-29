t=int(input())
for i in range(t):
    n=int(input()) #정수 입력
    find=[0,1,2,4]#0~3까지의 방법 수 설정
    for j in range(4,n+1):#4부터는 dp로 풀 수 있기에 반복문으로 진행
        result=find[j-1]+find[j-2]+find[j-3] #n-1,n-2,n-3의 합을 구해 변수에 넣어줌
        find.append(result) #구한 합을 리스트에 추가
    print(find[n]) #결과 출력