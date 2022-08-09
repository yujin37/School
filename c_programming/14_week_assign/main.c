//메인함수 담기
#include "mix.h"
#include "call.h"
//#include "find.h"
//extern void find();
//extern void find(PhoneBook *head, PhoneBook *temp);
//extern void find();
int main(void){
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
    while(temp!=NULL){
        if(temp->next==NULL){
            printf("%s이 연락을 받았습니다. 모든 구성원들에게 연락을 했습니다.\n",temp->name);
            break;
        }
        else{
            printf("%s는 %s에게 연락을 해야합니다.  %s의 전화번호는 %s입니다.\n",temp->name, (temp->next)->name, (temp->next)->name,(temp->next)->pnum);
            temp=temp->next;
        }
    }
    //find(&temp, &head);
    #include "find.h"
    free(temp);
    free(head);
    return 0;
}
