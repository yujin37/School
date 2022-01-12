#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Tele{
    char name[20];
    char phone[30];
    struct Tele *next;
}person[5];

int main(void){
    char arr[30];
    int i=0;
    person *p=(person*)malloc(sizeof(person));//구조체를 가르키는 연락망 할당
    person *temp=p;//임시저장도 할당
    //person *p=(person*)malloc(sizeof(person));
    while(1){
        scanf("%s", arr);//종료를 판단하기 위해 이렇게 먼저 arr로받음
        if(!strcmp(arr,"q")){//종료
            //free(temp);
            break;
        }
        else{
            //strcpy(p[i]->name, arr);//이름으로 복사
            //scanf("%s", p[i]->phone);//전화번호저장
            //person *p=(person*)malloc(strlen(p->name));
            //p[i]->next==p[i+1]->name;
            // p->next=(person*)malloc(sizeof(person));//다음순서는 다시 연락망할당
            // p=temp->next;//임시저장에 다음순서를 저장한 뒤 이 순서 종료
            //i++;
            if(temp==NULL){
                temp->next=(person*)malloc(sizeof(person));
                temp=temp->next;
            }
            strcpy(temp->name,arr);
            
        }
    }
    for(int i=0;i<5;i++){
        printf("%s %s %s", p[i]->name, p[i]->phone, (p[i]->next)->name);
    }
    free(p);
    return 0;
}