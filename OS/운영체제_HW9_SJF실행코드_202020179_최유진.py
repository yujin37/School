f=open("./process_list_5000.txt", 'r')
num=f.readline()
list=[]
queue=[]
ps_idx=[]
ps_s=[]
ps_r=[]
ps_e=[]
cnt=now_idx=t=0
for i in range(int(num)):
    line=f.readline()#줄 별로 읽어들이기
    list.append(line.split())#읽어서 공백으로 구분해서 저장
for i in range(len(list)):
    for j in range(len(list[0])):
        list[i][j]=int(list[i][j])
#sjf 시작!
min_num=min_arr=0
#now_time=0
cnt=0
while True:
    if cnt==int(num):
        break
    #한바퀴를 돌리면서 확인
    for i in range(len(list)):
    #만약 시간과 같은 값이 보이면
        if int(list[i][1])==t:
            queue.append(list[i])
            #not running 신호를 보낸다.-> 출력
            print("[%s] PID(%s): Not Running"% (list[i][1],list[i][0]))
            ps_idx.append(list[i][0])
            ps_s.append(t)
            
            break#는 거니까 상관 없음.
    #print(queue)
    
    #min_time=queue[0][2]
    #queue.sort(key=lambda x:(x[2],x[1]))
    #print(queue)
    
    if now_idx==0:
        #print(queue)
        if not queue:
            pass
        else:
            #now_time=min(queue[2] for s in queue)
            #now_num=queue.index(min(queue[2] for s in queue))
            #queue.sort(key=lambda x:[x[2],x[1],x[0]])#정렬을 하고, 실행시간, 먼저온 순, 그리고 나머지 번호
            #queue = sorted(queue,key = lambda x : (x[2],x[1],x[0]), reverse = False)
            queue.sort(key=lambda x: (x[2], x[1]))
            
            now_num=int(queue[0][0])#그리고 가장먼저 현재 번호를 기록하고
            now_time=int(queue[0][2])#그리고 타임을 정해서
            #여기 now_idx=1 적힌 거 지구고
    
            #running을 출력
            print("[%d] PID(%d): Running"%( t, now_num))#실행정보알려주고
            now_idx=1#잠군다.
            ps_r.append(t)#그리고 현재 시간 정보를 기록한다.
            #if now_num>=920:#이건 오류 확인 용
                #print(queue)
    #자기 시간 감소하거나 혹은 시작시간에서 자기 시간까지 채워지면
    now_time-=1#시간은 감소시킨다.
    if now_time==0:#만약에 그 시간이 0이 되버린다면
        print("[%d] PID(%d): Exit"%( t+1, now_num))#탈출 정보를 제공하고
        ps_e.append(t)#그 시간을 기록한다.
        #해당 번호 찾아서 없애기
        queue.pop(0)#큐의 첫번째것을 뽑아준다.
        #del queue[0]
        now_idx=0#그리고 풀어주고
        cnt+=1#완료한 것들의 개수를 올려준다.
        queue.sort(key=lambda x: (x[2], x[1]))
        
    #시간을 올려줌
    
    t+=1 #마지막으로 시간을 카운트해준다.


print("\nLog of Process Scheduling")

tt_sum=wt_sum=0
for i in range(int(num)):
    print("PID(%s) service Time: %-5s Arrival: %-5d Exit: %-5d Turnaround Time: %5d    Waiting Time: %-5d    Response Time: %d"%(ps_idx[i],list[i][2],int(ps_s[i]),int(ps_e[i])+1,(int(ps_e[i])-int(ps_s[i])+1), (int(ps_r[i])-int(ps_s[i])),(int(ps_r[i])-int(ps_s[i])) ))
for i in range(int(num)):
    tt_sum+=(int(ps_e[i])-int(ps_s[i])+1)
    wt_sum+=(int(ps_r[i])-int(ps_s[i]))
print("\nAverage Turnaround Time: %.2f"% (tt_sum/int(num)))
print("Average Waiting Time   : %.2f"%(wt_sum/int(num)))
print("Average Response Time  : %.2f"%(wt_sum/int(num)))

f.close()
