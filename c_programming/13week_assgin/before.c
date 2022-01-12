#include <stdio.h>
#include <string.h>
#include "call.h"
#include "before.h"
extern PhoneBook *temp,*prev,*head;
void before(){
    printf("입력받은 특정인 이전 사람 찾기: find sick person\n");
    char sick[10];
    scanf("%s", sick);
    while(1){

        if(!strcmp(sick, temp->name)){
            if(temp==head){
            	 printf("%s는 첫 번째 사람입니다. %s부터 차례로 연락을 시작하면 됩니다.\n", temp->name, temp->next->name);
            }

            else if(temp->next==NULL){
            	printf("%s은 마지막 사람입니다. %s는 아무에게도 연락하지 않아도 됩니다.\n", temp->name, prev->name);
            }

            else{
                printf("%s는 %s에게 연락해야 합니다. %s의 전화번호는 %s입니다.\n", prev->name,(temp->next)->name,(temp->next)->name, (temp->next)->pnum);

            }
            break;
        }
        prev=temp;
        temp=temp->next;
        if(temp==NULL){
        printf("not found\n");
            break;
        }
    }
}