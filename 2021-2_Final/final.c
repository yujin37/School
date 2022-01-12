#include <stdio.h>
#include <stdlib.h>
#include "final.h"
void Menu();
void History();//메뉴 오류로 중단
int count=0;
Mycal *cal[30];
//struct Mycal *cal[30];
//struct Mycal *cal=malloc(sizeof(struct Mycal)*30);
int main(void){
    //Mycal *cal=(Mycal*)malloc(sizeof(Mycal)*30);
    Menu();
    History();
    return 0;
}

void Menu(){//메뉴 선택 함수
    int ch;//메뉴선택 변수
    //int n1, n2;
    //Mycal *cal=(Mycal*)malloc(sizeof(Mycal)*30);
    for(int i=0;i<30;i++){
        cal[i]=malloc(sizeof(Mycal));
        printf("-----메뉴 선택-----\n");
        printf("1. 더하기\n2. 빼기\n3. 곱하기\n4. 나누기\n5. 출력\n6. 종료\n입력(숫자로): ");
        scanf("%d", &ch);
        //오류는 해결했으나 히스토리에 저장하는 과정을 확인하지 못했습니다.
        
        switch(ch){
            case 1:
            scanf("%d %d", &cal[i]->n1, &cal[i]->n2);
            printf("%d + %d = %d\n",cal[i]->n1, cal[i]->n2, MYADD(cal[i]->n1,cal[i]->n2));
            break;
            case 2:
            scanf("%d %d", &cal[i]->n1, &cal[i]->n2);
            printf("%d - %d = %d\n",cal[i]->n1, cal[i]->n2, MYSUB(cal[i]->n1,cal[i]->n2));
            break;
            case 3:
            scanf("%d %d", &cal[i]->n1, &cal[i]->n2);
            printf("%d * %d = %d\n",cal[i]->n1, cal[i]->n2, MYMUL(cal[i]->n1,cal[i]->n2));
            break;
            case 4:
            scanf("%d %d", &cal[i]->n1, &cal[i]->n2);
            printf("%d / %d = %d\n",cal[i]->n1, cal[i]->n2, MYDIV(cal[i]->n1,cal[i]->n2));
            break;
            case 6:
            return;
        }
        
        count+=1;
        
    }
}
void History(){//최근 히스토리
    for(int i=count-2;i<count;i++){//-2부터 출력해주기
        printf("%d %s %d = ", cal[i]->n1, cal[i]->how, cal[i]->n2);
        if(!strcmp(cal[i]->how,"+"))//더하기일때
            printf("%d\n",MYADD(cal[i]->n1,cal[i]->n2));
            
        else if(!strcmp(cal[i]->how,"-"))//빼기일때
            printf("%d\n",MYADD(cal[i]->n1,cal[i]->n2));
            
        else if(!strcmp(cal[i]->how,"*"))//곱하기일때
            printf("%d\n",MYADD(cal[i]->n1,cal[i]->n2));
            
        else if(!strcmp(cal[i]->how,"/"))//나누기일때
            printf("%d\n",MYADD(cal[i]->n1,cal[i]->n2));
    }
        

}
