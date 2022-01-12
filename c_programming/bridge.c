#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int Game(int (*gss)[2]){ //징검다리 게임
    int i;
    printf("l과 r만 입력하세요.\n");
    for(i=0;i<10;i++){//10번 반복하고
        char step[3];
        fgets(step,sizeof(step),stdin);
        //clear(step);
        if(step[0]=='l'){
            if(gss[i][0]==0){
                return 1;
            }
        }
        else if(step[0]=='r'){
            if(gss[i][1]==0){
                return 1;
            }
        }
    }
    return 0;//통과시 0 불통시 1;
} 
int main(void){
    int glass_stepping_stones[10][2];
    char people[5][20];
    int winner[6];//변수들을 각각 저장
    int all=0, lose=0;
    int count=0;
//    for(int i=0;i<10;i++){
//        srand((unsigned)time(NULL));
//        if((rand()%2)==1){
//            glass_stepping_stones[i][0]=1;
//            glass_stepping_stones[i][1]=0;//랜덤으로 if문 이용해 저장되고 있음
//        }
//        else{
//            glass_stepping_stones[i][0]=0;
//            glass_stepping_stones[i][1]=1;
//        }
//    }//1단계완성
    printf("선수 5명 명단 입력:\n");
    for(int i=0;i<5;i++){
        //people[i]=getchar();
        //fflush(stdin);
        scanf("%s", people[i]); //입력을 받은 후
        getchar();//엔터키 없애준다.
        //fgets(people[i], 20,stdin);//50,51번째가 맞음
        //people[i][strlen(people[i])-1]='\0';
    }//2단계완성
    //for(int i=0;i<5;i++){
    //    for(int j=0;people[i][j] !=0;j++){
    //        if(people[i][j]=='\n'){
    //            people[i][j]=0;
    //            printf("%d", people[i][j]);
    //        }
    //    }
    //}
    //for(int i=0;i<5;i++){
    //    int len=strlen(people[i]);
    //    printf("%d %s\n",len, people[i]);
    //}//수정중

    //int len=strlen(people);
    //people[len-1]==0;
    for(int i=0;i<5;i++){//선수 5명이 차례대로
        printf("%s (이)가 시작합니다.", people[i]); //시작하고
        printf("\n");
        //people[i][strlen(people)]=='\0';
        srand(time(0));//할때마다 다르게 출력하도록 srand를 지정 
        for(int i=0;i<10;i++){//징검다리 생성시작
            if((rand()%2)==1){//1과 0으로만 만들어준다.
                glass_stepping_stones[i][0]=1;
                glass_stepping_stones[i][1]=0;//1과 0으로 만드는중
            }
            else{
                glass_stepping_stones[i][0]=0;
                glass_stepping_stones[i][1]=1;
            }
        }
        for(int i=0;i<10;i++){
          for(int j=0;j<2;j++){
            printf("%d ", glass_stepping_stones[i][j]);
          }
        printf("\n");
        }
        winner[i]=Game(glass_stepping_stones);//이제 return 값을 각 배열에 넣어준다.
    }//여기는 스텝 차례대로 진행해서 배열에 저장
    for(int i=0;i<5;i++){
        if(winner[i]==0){
            all+=1;
        }
        if(winner[i]==1){
            lose+=1;
        }
    }
    printf("%d %d\n", all, lose);
    if(all==5){
        for(int i=0;i<5;i++){
            printf("%s", people[i]);
            count+=1;
                if(count!=0){
                    printf(",");
                }
        }
        printf(" (이)가 통과하였습니다.(1)");
    }
    if(lose==5){
        printf("한명도 통과하지 못했습니다.");
    }//일단 여기는 확인했고......
    if(all!=5&&lose!=5){
        for(int i=0;i<5;i++){
            if(winner[i]==0){
                printf(" %s", people[i]);
                if(count!=0){
                    printf(",");
                }
            }
            
        }
        printf("(이)가 통과하였습니다.(2)");
    }
//    for(int i=0;i<5;i++){
//        printf("%s의 통과여부 %d\n",people[i], winner[i]);
//    }



//아래는 검증 과정    
//    for(int i=0;i<5;i++){
//        printf("%s\n", people[i]);
//    }
//    for(int i=0;i<10;i++){
//        for(int j=0;j<2;j++){
//            printf("%d ", glass_stepping_stones[i][j]);
//        }
//        printf("\n");
//    }
}
