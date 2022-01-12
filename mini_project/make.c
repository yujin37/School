#include <stdio.h>
#include <string.h>
typedef struct {
    char name[10];
    int age;
}person;

int main(void){
    person p[10]; 
    int count;
    char temp[10];
    int temp1;
    FILE *fp=fopen("person.txt", "at");
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%s %d",p[i].name, &p[i].age);
        //fprintf(fp,"%s %d",p[i].name,p[i].age);
        //fputc('\n',fp);
    }
    for(int i=0;i<count;i++){
        for(int j=0;j<count-1;j++){
            if(strcmp(p[i].name,p[i+1].name)>0){
                strcpy(temp,p[i].name);
                //printf("%s", temp);
                strcpy(p[i].name,p[i+1].name);
                strcpy(p[i+1].name,temp);
                //printf("%s %s",p[i].name, p[i+1].name);
                temp1=p[i].age;
                p[i].age=p[i+1].age;
                p[i+1].age=temp1;
            }
        }
    }
    for(int i=0;i<count;i++){
        fprintf(fp,"%s %d",p[i].name,p[i].age);
        fputc('\n',fp);
    }
    
    return 0;
}