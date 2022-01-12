#include <stdio.h>
#include <string.h>
struct OneWord{
    char word[20];
    char meaning[100];
};
struct OneWord_dictionary{
    char words[20];
    char meanings[100];
};
struct OneWord o;
struct OneWord_dictionary od[100];

void Game(){
    int cnt=0,i=0;//cnt는 전체 길이, i는 그냥 while문 반복
    int count,stop=1; //이거는 끝까지 없는지 체크해주는 것이다.
    while(i<100&&stop!=2){//100번 이내에서 조건 으로 브레이크 해준다.
        count=0;
        cnt++;
        printf("등록할 단어를 입력하세요\n");
        scanf("%s", o.word);
        for(int j=0;j<cnt;j++){
            if(!strcmp(o.word,od[j].words)){
                printf("%s %s", od[j].words, od[j].meanings);
                stop+=1;
                break;//성립시
            }
            else{
                count++; //이건 체크 해주는 것이고...
            }
        }//여기가 같은지 확인해주는 것이고 이것을 for문으로 구현했다.
        
        if(count==cnt){//만약 위에가 성립 안된다면 아래 것을 시행해야 하는데.....
            Register(&od[cnt-1].words, &o.word);
        }
        i++;//100번반복체크
    }
}
void Register(int *od[cnt-1].words, int *o.word){
    strcpy(od[cnt-1].words, o.word); //이것은 사전 등록하는 과정
    printf("뜻을 입력해주세요\n");
    scanf("%s", od[cnt-1].meanings);
}

int main(void){
    Game();
    return 0;
}
