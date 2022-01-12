#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct call{
char name[10];
char pnum[15];
struct call* next;
struct call* prev;
} PhoneBook;

void printPhoneBook(PhoneBook *head) {
  PhoneBook *member;
  member = head;

  printf("\n\n비상연락망 출력\n");
while(member!=NULL) {
    printf("이름:%s, 전화번호:%s\n", member->name, member->pnum);
    member = member->next;
  }
return;
}
void printRevPhoneBook(PhoneBook *head){
    PhoneBook *member;
    member=head;
    printf("역순출력\n");
    printf("문제 10\n");
    if(member==NULL){
      printf("아무도 없습니다.");
    }
    while(member->next!=NULL){
        member=member->next;
    }
    while(temp!=NULL){
      printf("%s %s\n", member->name, member->pnum);
      temp=temp->prev;
    }
}
int main(void) {
  PhoneBook *head, *temp;
char name[10];
int cnt=0;

  printf("### 문제 5 ###\n");
  temp = head = NULL;

while (1) {
    printf("\n[%d]번째 사람(종료:q)\n", cnt + 1);
    printf("이름: ");
    scanf("%s", name);


if (strcmp(name, "q") == 0) 
break;

else if(cnt!=0) { // 제일 마지막 사람은 next가 없음 
      temp->next = malloc(sizeof(PhoneBook));
      temp->next->prev=temp;
      temp->next->next=NULL;

      temp = temp->next;
    } else {
      head = malloc(sizeof(PhoneBook));
      head->prev=NULL;
      head->next = NULL;

      temp=head;
    }
    strcpy(temp->name, name);

    printf("전화번호: ");
    scanf("%s", temp->pnum);
    cnt++;
  }

//  temp = head;
//   printf("\n\n비상연락망 출력\n");
// while(temp!=NULL) {
//     printf("이름:%s, 전화번호:%s\n", temp->name, temp->pnum);
//     temp = temp->next;
//   }
  //printRevPhoneBook(head);
  printPhoneBook(head);
/*
  printf("\n\n### 문제 6 ###\n");
  temp = head;
while(temp!=NULL) {
if(temp->next!=NULL) {
      printf("%s는 %s에게 연락해야 합니다. \
      %s의 전화번호는 %s입니다.\n", temp->name, \
      temp->next->name, temp->next->name, \
      temp->next->pnum);
      temp = temp->next;
    } else {
      printf("%s이 연락을 받았습니다 모든 구성원들에게 연락을 했습니다.\n", temp->name);
break;
    }
  }

  printf("\n\n### 문제 7 ###\n");
  temp = head;
  printf("찾을 사람 이름: ");
  scanf("%s", name);

while(temp!=NULL) {
if (strcmp(temp->name, name) == 0) {
if (temp->next!=NULL) {
        printf("%s는 %s에게 연락해야 합니다. \
        %s의 전화번호는 %s입니다.\n", temp->name, \
        temp->next->name, temp->next->name, \
        temp->next->pnum);
      } else  {
        printf("%s은 마지막 사람입니다.\n", temp->name);
      }
break;
    }

    temp = temp->next;
if (temp==NULL) {
      printf("그런 사람 없습니다.\n");
break;
    }
  }

  printf("\n\n### 문제 8 ###\n");
  PhoneBook *prev;
  prev = temp = head;
  printf("아픈 사람 이름: ");
  scanf("%s", name);

while(temp!=NULL) {
if (strcmp(temp->name, name) == 0) {
if(temp==head) {
        printf("%s는 첫 번째 사람입니다. %s부터 차례로 연락을 시작하면 됩니다.\n", temp->name, temp->next->name);
      }
else if (temp->next==NULL) {
        printf("%s은 마지막 사람입니다. %s는 아무에게도 연락하지 않아도 됩니다.\n", temp->name, prev->name);
      } else {
        printf("%s는 %s에게 연락해야 합니다. \
        %s의 전화번호는 %s입니다.\n", prev->name, \
        temp->next->name, temp->next->name, \
        temp->next->pnum);
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
*/

  
  printf("\n\n### 문제 9 ###\n");
  PhoneBook *prev;
  prev = temp = head;
  printf("탈퇴한 사람 이름: ");
  scanf("%s", name);

while(temp!=NULL) {
if (strcmp(temp->name, name) == 0) {
if(temp==head) {
        printf("%s는 첫 번째 사람입니다. %s부터 차례로 연락을 시작하면 됩니다.\n", temp->name, temp->next->name);

        head = temp->next;
        free(temp);
      }
else if (temp->next==NULL) {
        printf("%s은 마지막 사람입니다. %s는 아무에게도 연락하지 않아도 됩니다.\n", temp->name, prev->name);

        prev->next = NULL;
        free(temp);

      } else {
        printf("%s는 %s에게 연락해야 합니다. \
        %s의 전화번호는 %s입니다.\n", prev->name, \
        temp->next->name, temp->next->name, \
        temp->next->pnum);

        prev->next = temp->next;
        free(temp);
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
  //printRevPhoneBook(head);
  printPhoneBook(head);
  printRevPhoneBook(head);
return 0;
}
