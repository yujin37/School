#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "music.h"
void Menu();//�޴�
void Add();//�Է�
void Find();//�˻�
void Del();//����
void List();//����Ʈ
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
        
        else if(!strcmp(sel, "D")){
            Del();
        }
        
        else if(!strcmp(sel, "L")){
            List();
        }
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
void Add(Music *music){
    while(1){
        char song[50];
        printf("�뷡���� �Է�, ����� q");
        scanf("%s", song);
        if(!strcmp(song, "q")){
            break;
        }
        if(!strcmp(song,music->title)){
            printf("������ ��\n");
            continue;
        }
        strcpy(music[n].title,song);
        printf("���� �Է�");
        scanf("%s",music[n].artist);
        printf("�߸ſ��� �Է�");
        scanf("%d",&music[n].year);
        n+=1;
        continue;
    }
}
void Find(Music *music){
    char song[50];
    printf("�뷡�� �˻��մϴ�. �뷡�����Է�.\n");
    scanf("%s",song);
    for(int i=0;i<n;i++){
        if(!strcmp(song,music[i].title)){
            printf("�뷡�� ã�ҽ��ϴ�.\n");
            printf("�뷡����: %s\n����: %s\n�߸ſ���: %d\n", music[i].title, music[i].artist,music[i].year);
            return;
        }
    }
    printf("�뷡�� ã�� ���߽��ϴ�. �뷡 ã�⸦ �����մϴ�.\n");
}
void List(Music *music){
    char yn[2];
    printf("ȯ���մϴ�. �뷡����� ����մϴ�.\n");
    for(int i=0;i<n;i++){
        printf("�뷡����: %s\n����: %s\n�߸ſ���: %d\n\n", music[i].title, music[i].artist,music[i].year);
    }
    printf("�뷡�� ��� ����Ͽ����ϴ�.\n-------------------\n");
    printf("�� ��ϵ��� ��� ����ұ��?");
    scanf("%s",yn);
    if(!strcmp(yn,"y")){
        printf("����� �����մϴ�.\n");
        FILE *fp=fopen("music.txt","wb");
        /*for(int i=0;i<n;i++){
            fwrite(music[i].title,strlen(music[i].title),1,fp);
            fwrite(music[i].artist,strlen(music[i].artist),1,fp);
            fwrite(music[i].year,sizeof(music[i].year),1,fp);
        }*/
        fwrite(music, sizeof(music),1,fp);
        fclose(fp);
        printf("����� �Ϸ�Ǿ����ϴ�.\n");
    }
    else if(!strcmp(yn,"n")){
        printf("����� ���� �ʽ��ϴ�.");
    }
}
void Del(Music *music){
    char song[50];
    int i,j,k;

    printf("ȯ���մϴ�. �뷡��Ͽ��� �뷡�� ������ �� �ֽ��ϴ�.\n");
    printf("� �뷡�� �����ұ��?\n");
    for(k=0;k<n;k++){
        printf("�뷡����: %s\n����: %s\n�߸ſ���: %d\n\n", music[k].title, music[k].artist,music[k].year);
    }
    scanf("%s",song);
    //printf("������......\n");
    
    for(i=0;i<n;i++){
        
        if(!strcmp(song,music[i].title)){
            printf("������........\n");
            for(j=i;j<n;j++){
                /*if(j=n-2){
                    music[j+1].title='\0';
                    music[j+1].artist='\0';
                    music[j+1].year='\0';
                    break;
                }*/
                strcpy(music[j].title,music[j+1].title);
                strcpy(music[j].artist,music[j+1].artist);
                music[j].year=music[j+1].year;
                
            }
            n-=1;
            printf("�����Ͽ����ϴ�.\n");
            for(k=0;k<n;k++){
                printf("�뷡����: %s\n����: %s\n�߸ſ���: %d\n\n", music[k].title, music[k].artist,music[k].year);
            }
            return;
            
        }/*
        else if(strcmp(song,music[i].title)!=0 && (i=(n-1))){
            printf("������ �뷡�� ã�� �� �����ϴ�. �����մϴ�.\n");
            
        }*/
    
    }
    
    printf("������ �뷡�� ã�� �� �����ϴ�. �����մϴ�.\n");
}