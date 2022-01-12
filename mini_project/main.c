#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "music.h"
void Menu();//메뉴
void Add();//입력
void Find();//검색
//void Del();//삭제
//void List();//리스트
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
    printf("(A)dd a song[노래를 추가합니다]\n");
    printf("(F)ind a song[노래를 검색합니다]\n");
    printf("(D)elete a song[노래를 삭제합니다]\n");
    printf("(L)ist a song[목록을 출력합니다]\n");
    printf("(Q)uit[종료합니다]\n");
    printf("선택한 메뉴를 입력하시오 : ");
    
}

void Add(Music *music[]){
    while(1){
        char titles[50];
        printf("곡 명을 입력하세요.(중복불가): 입력 종료는 q");
        scanf("%s", titles);
        getchar();
        if(!strcmp(titles,"q")){
            break;
        }/*
        for(int i=0;i<n;i++){
            if(!strcmp(title, music[i]->title)){
                printf("동일한 곡명이 있습니다.\n");
                Add(music,n);
            }
        }
        */
        
        strcpy(music[n]->title,titles);
        printf("가수를 입력하세요.: ");
        scanf("%s",music[n]->artist);
        getchar();
        printf("발매 연도를 입력하세요.: ");
        scanf("%d",&music[n]->year);
        getchar();
        n+=1;
        printf("restart\n");
    }
    
}
void Find(Music *music[]){
    char find_music[20];
    if(n!=0){
        printf("음악을 검색 하겠습니다. 노래제목을 입력하세요.\n");
        scanf("%s", find_music);
        for(int i=0;i<n;i++){
            if(!strcmp(find_music, music[i]->title)){
                printf("노래제목: %s \n가수명: %s \n발매연도: %d",music[i]->title, music[i]->artist, music[i]->year);
            }
        }
    }
    else{
        printf("입력된 책이 없어 찾을 책이 없습니다.\n");
    }
}


