#include <stdio.h>
#include <string.h>
#include "call.h"
#include "out.h"
extern PhoneBook *temp, *head, *prev;
void out(){
  prev = temp = head;
  printf("탈퇴한 사람 이름: ");
  char name[10];
  scanf("%s", name);
while(temp!=NULL) {
if (strcmp(temp->name, name) == 0) {
if(temp==head) {
        printf("%s가 탈퇴했습니다. %s부터 차례로 연락을 시작하면 됩니다.\n", temp->name, temp->next->name);
        head = temp->next;
      }
else if (temp->next==NULL) {
        printf("%s가 탈퇴했습니다. %s는 아무에게도 연락하지 않아도 됩니다.\n", temp->name, prev->name);
        prev->next = NULL;
      } else {
        //prev->next = temp->next;
        printf("%s가 탈퇴했습니다. 앞으로는 %s가 %s에게 연락해야 합니다.\n", temp->name, prev->name,
        temp->next->name);
        //printf("%s", temp->next->name);
        prev->next = temp->next;
      }
      break;
    }
    prev = temp;
    temp = temp->next;
if (temp==NULL) {
      printf("그런 사람 없습니다.\n");
break;
    }
  }
}