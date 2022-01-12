//메인함수 담기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "call.h"
#include "find.h"
#include "before.h"
#include "out.h"
//extern void find(void);
//extern void find();
PhoneBook* head, * temp, *prev;
int main(void) {
    char name[10];
    int cnt = 0;
    printf("### 비상연락망 ###\n");
    temp = head =prev = NULL;
    while (1) {
        printf("\n[%d]번째 사람(종료:q)\n", cnt + 1);
        printf("이름: ");
        scanf("%s", name);
        if (strcmp(name, "q") == 0)
            break;
        else if (cnt != 0) { // 제일 마지막 사람은 next가 없음
            temp->next = malloc(sizeof(PhoneBook));
            temp = temp->next;
        }
        else {
            head = malloc(sizeof(PhoneBook));
            temp = head;
        }
        strcpy(temp->name, name);
        printf("전화번호: ");
        scanf("%s", temp->pnum);
        temp->next = NULL;
        cnt++;
    }
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) {
            printf("%s이 연락을 받았습니다. 모든 구성원들에게 연락을 했습니다.\n", temp->name);
            break;
        }
        else {
            printf("%s는 %s에게 연락을 해야합니다.  %s의 전화번호는 %s입니다.\n", temp->name, (temp->next)->name, (temp->next)->name, (temp->next)->pnum);
            temp = temp->next;
        }
    }
    temp=head;
    find();
    prev=temp=head;
    before();
    temp=head;
    out();
    free(temp);
    free(head);
    return 0;
}