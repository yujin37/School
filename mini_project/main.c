#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "music.h"
void Menu();//�޴�
void Add();//�Է�
void Find();//�˻�
//void Del();//����
//void List();//����Ʈ
int n=0;
int main(){
    Music music[100];
    char sel[2];
    //int num=0;
    printf("���� �����ͺ��̽��� ���� ���� ȯ���մϴ�!\n");
    printf("----------------------------------------\n");
    
    while(1){
        Menu();
        scanf("%s", sel);
        getchar();
        //printf("%d\n",num);
        if(!strcmp(sel,"A")){
            Add(music);
        }
        
        else if(!strcmp(sel,"F")){
            Find(music);
        }
        /*
        else if(!strcmp(sel, 'D')){
            Del();
        }
        else if(!strcmp(sel, 'L')){
            List();
        }*/
        else if(!strcmp(sel, "Q")){
            break;
        }
        
    }
    return 0;
}
void Menu(){
    printf("(A)dd a song[�뷡�� �߰��մϴ�]\n");
    printf("(F)ind a song[�뷡�� �˻��մϴ�]\n");
    printf("(D)elete a song[�뷡�� �����մϴ�]\n");
    printf("(L)ist a song[����� ����մϴ�]\n");
    printf("(Q)uit[�����մϴ�]\n");
    printf("������ �޴��� �Է��Ͻÿ� : ");
    
}

void Add(Music *music[]){
    while(1){
        char titles[50];
        printf("�� ���� �Է��ϼ���.(�ߺ��Ұ�): �Է� ����� q");
        scanf("%s", titles);
        getchar();
        if(!strcmp(titles,"q")){
            break;
        }/*
        for(int i=0;i<n;i++){
            if(!strcmp(title, music[i]->title)){
                printf("������ ����� �ֽ��ϴ�.\n");
                Add(music,n);
            }
        }
        */
        
        strcpy(music[n]->title,titles);
        printf("������ �Է��ϼ���.: ");
        scanf("%s",music[n]->artist);
        getchar();
        printf("�߸� ������ �Է��ϼ���.: ");
        scanf("%d",&music[n]->year);
        getchar();
        n+=1;
        printf("restart\n");
    }
    
}
void Find(Music *music[]){
    char find_music[20];
    if(n!=0){
        printf("������ �˻� �ϰڽ��ϴ�. �뷡������ �Է��ϼ���.\n");
        scanf("%s", find_music);
        for(int i=0;i<n;i++){
            if(!strcmp(find_music, music[i]->title)){
                printf("�뷡����: %s \n������: %s \n�߸ſ���: %d",music[i]->title, music[i]->artist, music[i]->year);
            }
        }
    }
    else{
        printf("�Էµ� å�� ���� ã�� å�� �����ϴ�.\n");
    }
}


