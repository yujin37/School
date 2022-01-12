//연락해야 하는 사람 찾아주기
//extern main;
#include <stdio.h>
#include <string.h>
#include "call.h"
#include "find.h"
extern PhoneBook *temp;
void find(){
    printf("find person\n");
    char pname[10];
    //PhoneBook *head1, *temp1;
    scanf("%s", pname);
    getchar();
    while(1){
        if(!strcmp(pname, temp->name)){
            if(temp->next!=NULL){
                printf("%s는 %s에게 연락해야 합니다. %s의 전화번호는 %s입니다.\n", temp->name, (temp->next)->name, (temp->next)->name, (temp->next)->pnum);
                break;
            }
            else{
                printf("%s는 마지막 사람입니다.\n", temp->name);
                break;
            }
        }
        else{
            if(temp->next==NULL){
                printf("그런사람 없습니다.\n");
                break;
            }
            temp=temp->next;
        }
    }
}