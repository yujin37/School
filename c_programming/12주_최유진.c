#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int start=0;
int Game(int (*gss)[2], int glass,char *path, int count){ //¡�˴ٸ�, �ٸ�����, ���, ���°����
    int i;
    if(start<glass){//���� �˸�
        printf("(l�� r�� �Է����ּ���.)\n%d���� �����մϴ�.\n",start+1);
    }
    for(i=start;i<glass;i++){
        char step[3];
        fgets(step,sizeof(step),stdin);//�Է¹޾�
        if(step[0]=='l'){//�Ǵ�
            if(gss[i][0]==0){
                return 1;
            }
            else{
                path[i]='l';//��α��
            
            }
        }
        else if(step[0]=='r'){
            if(gss[i][1]==0){//�Ǵ�
                return 1;
            }
            else{
                path[i]='r';//��α��
            
            }
        }
        start+=1;//�̰� �ݺ�Ƚ���� ���
    }
    return 0;
}

int main(void){//�����Լ�
    int glass,many;
    printf("¡�˴ٸ� ������ �����ο����� �Է����ּ���.");//¡�˴ٸ�����, �����ο� �Է�
    scanf("%d %d",&glass, &many);
    FILE *fp=fopen("gss.txt","w");//���Ͼ���
    FILE *fr=fopen("gss.txt", "r");//�����б�
    int glass_stepping_stones[glass][2];//¡�˴ٸ�
    char people[many][20];//�����̸�
    int winner[many+1];//����,���б��
    int all=0, lose=0;//�¸����ú���
    int count=0;//���°������
    char path[glass+1];//���
    printf("�������� �̸��� �Է����ּ���.:\n");
    for(int i=0;i<many;i++){//������ �̸� �Է�
        scanf("%s", people[i]);
        getchar();
    }
    for(int i=0;i<glass;i++){
        if((rand()%2)==1){//�����Լ� �̿��� ¡�˴ٸ� ����
            glass_stepping_stones[i][0]=1;
            glass_stepping_stones[i][1]=0;
        }
        else{
            glass_stepping_stones[i][0]=0;
            glass_stepping_stones[i][1]=1;
        }
    }
    int start=0;
    for(int i=0;i<many;i++){//���� ����
        printf("%s (��)�� �����մϴ�.(���� �ռ����� ��� ����� ��� �ڵ����� ����˴ϴ�.", people[i]); 
        printf("\n");
        srand(time(0));
        winner[i]=Game(glass_stepping_stones,glass, path,i);//����, ���� ����
    }
    for(int i=0;i<many;i++){//���� ���
        if(winner[i]==0){
            all+=1;
        }
        if(winner[i]==1){
            lose+=1;
        }
    }
    if(all==many){//��� ���
        for(int i=0;i<many;i++){
            printf("%s", people[i]);
            if(i!=(many-1)){
                printf(", ");
            }
        }
        printf("(��)�� ����Ͽ����ϴ�. ������δ� ");
    }
    if(lose==many){//��� �������
        printf("�� �� ������� ���߽��ϴ�. ������ �� ������ ��δ� ");
    }
    if(all!=many&&lose!=many){//�Ϻ� ���
        for(int i=0;i<many;i++){
            if(winner[i]==0){
                if(count!=0){
                    printf(", ");
                }
                printf("%s", people[i]);
                count+=1;
            }
        }
        printf("(��)�� ����Ͽ����ϴ�. ������δ� ");
    }
    
    fwrite(path,strlen(path),1,fp);//���,���Ͽ� ����
    fclose(fp);//���� ����
    char ch[strlen(path)];//���� ���� ����
    fgets(ch,strlen(path)+1,fr);//����
    for(int i=0;i<strlen(path);i++){
        if(i!=0) printf("-");
        printf("%c",ch[i]);
    }
    printf("�Դϴ�.");
    fclose(fr);//���� ����
    return 0;
}
