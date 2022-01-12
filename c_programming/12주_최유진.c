#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int start=0;
int Game(int (*gss)[2], int glass,char *path, int count){ //징검다리, 다리개수, 경로, 몇번째인지
    int i;
    if(start<glass){//순서 알림
        printf("(l과 r중 입력해주세요.)\n%d부터 시작합니다.\n",start+1);
    }
    for(i=start;i<glass;i++){
        char step[3];
        fgets(step,sizeof(step),stdin);//입력받아
        if(step[0]=='l'){//판단
            if(gss[i][0]==0){
                return 1;
            }
            else{
                path[i]='l';//경로기억
            
            }
        }
        else if(step[0]=='r'){
            if(gss[i][1]==0){//판단
                return 1;
            }
            else{
                path[i]='r';//경로기억
            
            }
        }
        start+=1;//이건 반복횟수를 계산
    }
    return 0;
}

int main(void){//메인함수
    int glass,many;
    printf("징검다리 개수와 참여인원수를 입력해주세요.");//징검다리개수, 참여인원 입력
    scanf("%d %d",&glass, &many);
    FILE *fp=fopen("gss.txt","w");//파일쓰기
    FILE *fr=fopen("gss.txt", "r");//파일읽기
    int glass_stepping_stones[glass][2];//징검다리
    char people[many][20];//선수이름
    int winner[many+1];//성공,실패기록
    int all=0, lose=0;//승리관련변수
    int count=0;//몇번째진행중
    char path[glass+1];//경로
    printf("참여자의 이름을 입력해주세요.:\n");
    for(int i=0;i<many;i++){//참여자 이름 입력
        scanf("%s", people[i]);
        getchar();
    }
    for(int i=0;i<glass;i++){
        if((rand()%2)==1){//랜덤함수 이용한 징검다리 생성
            glass_stepping_stones[i][0]=1;
            glass_stepping_stones[i][1]=0;
        }
        else{
            glass_stepping_stones[i][0]=0;
            glass_stepping_stones[i][1]=1;
        }
    }
    int start=0;
    for(int i=0;i<many;i++){//게임 진행
        printf("%s (이)가 시작합니다.(만약 앞순서가 모두 통과한 경우 자동으로 통과됩니다.", people[i]); 
        printf("\n");
        srand(time(0));
        winner[i]=Game(glass_stepping_stones,glass, path,i);//성공, 실패 받음
    }
    for(int i=0;i<many;i++){//성공 계산
        if(winner[i]==0){
            all+=1;
        }
        if(winner[i]==1){
            lose+=1;
        }
    }
    if(all==many){//모두 통과
        for(int i=0;i<many;i++){
            printf("%s", people[i]);
            if(i!=(many-1)){
                printf(", ");
            }
        }
        printf("(이)가 통과하였습니다. 성공경로는 ");
    }
    if(lose==many){//모두 통과못함
        printf("한 명도 통과하지 못했습니다. 성공한 곳 까지의 경로는 ");
    }
    if(all!=many&&lose!=many){//일부 통과
        for(int i=0;i<many;i++){
            if(winner[i]==0){
                if(count!=0){
                    printf(", ");
                }
                printf("%s", people[i]);
                count+=1;
            }
        }
        printf("(이)가 통과하였습니다. 성공경로는 ");
    }
    
    fwrite(path,strlen(path),1,fp);//경로,파일에 쓰기
    fclose(fp);//파일 닫음
    char ch[strlen(path)];//읽음 받을 변수
    fgets(ch,strlen(path)+1,fr);//읽음
    for(int i=0;i<strlen(path);i++){
        if(i!=0) printf("-");
        printf("%c",ch[i]);
    }
    printf("입니다.");
    fclose(fr);//파일 닫음
    return 0;
}
