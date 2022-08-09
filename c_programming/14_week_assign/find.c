//연락해야 하는 사람 찾아주기
//extern main;
#include "mix.h"
#include "call.h"
//#include "find.h"
//extern char name;
void find(PhoneBook *head, PhoneBook *temp){
    //extern *head;
    //extern *temp;
    char pname[10];
    temp=head;
    scanf("%s", &pname);
    while(1){
        if(!strcmp(pname, temp->name)){
            if(temp->next!=NULL){
                printf("%s는 %s에게 연락해야 합니다. %s의 전화번호는 %s입니다.", temp->name, (temp->next)->name, (temp->next)->name, (temp->next)->pnum);
                break;
            }
            else{
                printf("%s는 마지막 사람입니다.", temp->name);
                break;
            }
        }
        else{
            if(temp->next==NULL){
                printf("그런사람 없습니다.");
            }
            temp=temp->next;
        }
    }
}
