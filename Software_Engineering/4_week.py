def generator():
    #아이디어: 기존 숫자와 숫자를 각자리 숫자로 리스트 만들어 계산해 기존에 만들어놓은
    #리스트에서 빼주어야 겠다고 생각
    check = [i for i in range(1,5000)] #5000까지 리스트를 만든다.
    for i in range(1,5000): #1부터 5000까지 반복하면서 체크한다.
        num=i #num은 i 숫자 d(n)의 값을 담는다.
        num_list=list(map(int,str(i))) #숫자를 문자로 나누어 리스트로 넣는다. 123 이라면 [1,2,3] 이렇게
        num+=sum(num_list) #그리고 d(n)의 값에 각 자릿수 숫자의 합을 더해준다.
        if num in check: #그리고 구한 d(n)이 체크할 리스트에 존재하는지 확인해 있다면
            check.remove(num) #check리스트에서 제거
    result=sum(check) #확인 완료한 리스트에 있는 모든 숫자를 더해
    return result #리턴해준다.
print(generator())