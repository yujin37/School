#include <stdio.h>
#include <String.h>

int main(void){
    char str1[20], str2[20];//입력받음
    char str1_1[20], str2_1[20];//이름 저장
    char str1_2[20], str2_2[20];//나이 저정
    int i,k;//i는 첫번째 이름길이 k는 두번째 이름길이
    int j, l;//j는 첫번째 나이, l은 두번째 나이
    puts("두 사람의 이름과 나이 입력");
    puts("첫번째 사람 입력(이름, 나이): ");
    fgets(str1,sizeof(str1), stdin);
    str1[sizeof(str1)-1]='\0';
    puts("두번째 사람 입력(이름, 나이): ");
    fgets(str2, sizeof(str2), stdin);
    str2[sizeof(str2)-1]='\0';

    for(i=0;str1[i]!=' ';i++){
        str1_1[i]=str1[i];
        
    }//첫번째 문자열 이름 잘라주기
    str1_1[i]='\0';
    i++;
    for(j=i;j<(strlen(str1));j++){
        str1_2[j-i]=str1[j];
        
    }//첫번째 문자열 나이 잘라주기
    for(k=0;str2[k]!=' ';k++){
        str2_1[k]=str2[k];
        
    }//두번째 문자열 이름 잘라주기
    str1_1[k]='\0';
    k++;
    for(l=k;l<(strlen(str2));l++){
        str2_2[l-k]=str2[l];
        
    }//두번째 문자열 나이 잘라주기

    if(!strcmp(str1_1, str2_1)){
        puts("두사람의 이름은 같습니다.");
        printf("%s %s", str1_1, str2_1);
    }
    else{
        puts("두사람의 이름은 다릅니다.");
        printf("%s %s", str1_1, str2_1);
    }
    
    if(!strcmp(str1_2,str2_2)){
        puts("두사람의 나이는 같습니다");
        printf("%s %s", str1_2, str2_2);
    }
    else{
        puts("두사람의 나이는 다릅니다.");
        printf("%s %s", str1_2, str2_2);
    }
}
