//�Է±�� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "music.h"
#include "add.h"
void Add(){
    char name[20];
    FILE *fp=fopen("hello.txt", "r+");
    Music *music,*temp;
    while(1){
        printf("�뷡 ���� �Է� : ");
        fgets(name,sizeof(name),stdin);
        if(!strcmp(name, "q")){
            printf("�Է��� �ߴ��մϴ�.\n");
            break;
        }
        //fread(buffer, sizeof(buffer),1,fp);
        /*
        while(temp!=NULL){
            if(!strcmp(name,)){//�ߺ��� ������ ���� �� �ٽ� �ݺ�
            printf("������ �뷡 ������ �ֽ��ϴ�.");
            continue;
            }
            temp+=1;
        }
        */
        
        music=malloc(sizeof(Music));//�޸𸮸� �Ҵ��ϰ�
        strcpy(name,music->title);//������ ���ٸ� ������ ����ü�� �־��ְ�
        printf("���� �Է� : ");//���� �Է¹ް�
        fgets(music->artist,sizeof(music->artist),stdin);
        printf("�뷡 �߸� ���� �Է�");//���� �Է¹޴´�.
        scanf("%d",music->year);

    }
    
}