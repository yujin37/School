//입력기능 구현
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
        printf("노래 제목 입력 : ");
        fgets(name,sizeof(name),stdin);
        if(!strcmp(name, "q")){
            printf("입력을 중단합니다.\n");
            break;
        }
        //fread(buffer, sizeof(buffer),1,fp);
        /*
        while(temp!=NULL){
            if(!strcmp(name,)){//중복된 정보가 있을 시 다시 반복
            printf("동일한 노래 제목이 있습니다.");
            continue;
            }
            temp+=1;
        }
        */
        
        music=malloc(sizeof(Music));//메모리를 할당하고
        strcpy(name,music->title);//같은게 없다면 제목을 구조체에 넣어주고
        printf("가수 입력 : ");//가수 입력받고
        fgets(music->artist,sizeof(music->artist),stdin);
        printf("노래 발매 연도 입력");//연도 입력받는다.
        scanf("%d",music->year);

    }
    
}