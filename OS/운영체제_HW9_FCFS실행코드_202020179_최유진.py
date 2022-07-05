f=open("./process_list_5000.txt", 'r')
num=f.readline()
list=[]#프로세스 정보 저장
queue=[]
ps_idx=[]
ps_s=[]#점유시작
ps_r=[]#실제 실행시작
ps_e=[]#종료 시간
t=now_idx=cnt=0
for i in range(int(num)):
    line=f.readline()#줄 별로 읽어들이기
    list.append(line.split())#읽어서 공백으로 구분해서 저장

while True:
    #종료 조건, 리스트가 비면서 idx도 초기화되면 종료
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
            break
    #idx가 0으로 바꿔주고
    #만약 0이라면 큐에서 하나 뽑아준다.
    if now_idx==0:
        if not queue:
            pass
        else:
            now_num=int(queue[0][0])
            now_time=int(queue[0][2])
    #now_idx를 1로 바꿔준다.
            now_idx=1
    #running을 출력
            print("[%d] PID(%s): Running"%( t, queue[0][0]))
            ps_r.append(t)
    #자기 시간 감소하거나 혹은 시작시간에서 자기 시간까지 채워지면
    now_time-=1
    if now_time==0:
        print("[%d] PID(%d): Exit"%( t+1, now_num))
        ps_e.append(t)
        now_idx=0
        queue.pop(0)
        cnt+=1
    #시간을 올려줌
    t+=1

print("\nLog of Process Scheduling")
tt_sum=wt_sum=0
for i in range(int(num)):
    print("PID(%s) Turnaround Time: %5d    Waiting Time: %-5d    Response Time: %d"%(ps_idx[i],(int(ps_e[i])-int(ps_s[i])+1), (int(ps_r[i])-int(ps_s[i])),(int(ps_r[i])-int(ps_s[i])) ))
for i in range(int(num)):
    tt_sum+=(int(ps_e[i])-int(ps_s[i])+1)
    wt_sum+=(int(ps_r[i])-int(ps_s[i]))

print("\nAverage Turnaround Time: %.2f"% (tt_sum/int(num)))
print("Average Waiting Time   : %.2f"%(wt_sum/int(num)))
print("Average Response Time  : %.2f"%(wt_sum/int(num)))
f.close()
