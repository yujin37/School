def Stock(n, profit): #주어진 입력
    cnt=0 #최소 횟수 계산 변수
    for index in range(n): #반복문 돌면서
        if sum(profit[:index+1])<0: #index까지의 합이 만약 0보다 작으면
            #index까지의 인덱스 중에 최솟값의 인덱스를 구해
            #profit리스트에서 이 인덱스 값을 0으로 만들어주고
            profit[profit.index(min(profit[:index+1]))]=0 
            cnt+=1 #최소횟수를 올려주고
    return cnt


 
n=5
profit=[-2,3,-5,-1,6]
print(Stock(n,profit)) #출력 2
n=6
profit=[5, -3, -1, -1, -1, -1]
print(Stock(n,profit)) #출력1

