#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "music.h"
void Menu();//메뉴
void Add();//입력
void Find();//검색
void Del();//삭제
void List();//리스트
int n=0;
int main(){
    Music music[100];
    char sel[2];
    //int num=0;
    printf("가요 데이터베이스에 오신 것을 환영합니다!\n");
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
    printf("(A)dd a song[노래를 추가합니다]\n");
    printf("(F)ind a song[노래를 검색합니다]\n");
    printf("(D)elete a song[노래를 삭제합니다]\n");
    printf("(L)ist a song[목록을 출력합니다]\n");
    printf("(Q)uit[종료합니다]\n");
    printf("선택한 메뉴를 입력하시오 : ");
    
}
void Add(Music *music){
    while(1){
        char song[50];
        printf("노래제목 입력, 종료는 q");
        scanf("%s", song);
        if(!strcmp(song, "q")){
            break;
        }
        if(!strcmp(song,music->title)){
            printf("동일한 곡\n");
            continue;
        }
        strcpy(music[n].title,song);
        printf("가수 입력");
        scanf("%s",music[n].artist);
        printf("발매연도 입력");
        scanf("%d",&music[n].year);
        n+=1;
        continue;
    }
}
void Find(Music *music){
    char song[50];
    printf("노래를 검색합니다. 노래제목입력.\n");
    scanf("%s",song);
    for(int i=0;i<n;i++){
        if(!strcmp(song,music[i].title)){
            printf("노래를 찾았습니다.\n");
            printf("노래제목: %s\n가수: %s\n발매연도: %d\n", music[i].title, music[i].artist,music[i].year);
            return;
        }
    }
    printf("노래를 찾지 못했습니다. 노래 찾기를 종료합니다.\n");
}
void List(Music *music){
    char yn[2];
    printf("환영합니다. 노래목록을 출력합니다.\n");
    for(int i=0;i<n;i++){
        printf("노래제목: %s\n가수: %s\n발매연도: %d\n\n", music[i].title, music[i].artist,music[i].year);
    }
    printf("노래를 모두 출력하였습니다.\n-------------------\n");
    printf("이 목록들을 모두 기록할까요?");
    scanf("%s",yn);
    if(!strcmp(yn,"y")){
        printf("기록을 시작합니다.\n");
        FILE *fp=fopen("music.txt","wb");
        /*for(int i=0;i<n;i++){
            fwrite(music[i].title,strlen(music[i].title),1,fp);
            fwrite(music[i].artist,strlen(music[i].artist),1,fp);
            fwrite(music[i].year,sizeof(music[i].year),1,fp);
        }*/
        fwrite(music, sizeof(music),1,fp);
        fclose(fp);
        printf("기록이 완료되었습니다.\n");
    }
    else if(!strcmp(yn,"n")){
        printf("기록을 하지 않습니다.");
    }
}
void Del(Music *music){
    char song[50];
    int i,j,k;

    printf("환영합니다. 노래목록에서 노래를 삭제할 수 있습니다.\n");
    printf("어떤 노래를 삭제할까요?\n");
    for(k=0;k<n;k++){
        printf("노래제목: %s\n가수: %s\n발매연도: %d\n\n", music[k].title, music[k].artist,music[k].year);
    }
    scanf("%s",song);
    //printf("삭제중......\n");
    
    for(i=0;i<n;i++){
        
        if(!strcmp(song,music[i].title)){
            printf("삭제중........\n");
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
            printf("삭제하였습니다.\n");
            for(k=0;k<n;k++){
                printf("노래제목: %s\n가수: %s\n발매연도: %d\n\n", music[k].title, music[k].artist,music[k].year);
            }
            return;
            
        }/*
        else if(strcmp(song,music[i].title)!=0 && (i=(n-1))){
            printf("삭제할 노래를 찾을 수 없습니다. 종료합니다.\n");
            
        }*/
    
    }
    
    printf("삭제할 노래를 찾을 수 없습니다. 종료합니다.\n");
}