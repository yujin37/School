#ifndef __FINAL_H__
#define __FINAL_H__
#define MYADD(n1, n2) ((n1)+(n2))//���ϱ�
#define MYSUB(n1, n2) ((n1)-(n2))//����
#define MYMUL(n1, n2) ((n1)*(n2))//���ϱ�
#define MYDIV(n1, n2) ((n1)/(n2))//������

typedef struct{
    int n1;//ù��° ����
    int n2;//�ι�° ����
    char how[3];//������ ����
}Mycal;
#endif