#ifndef __FINAL_H__
#define __FINAL_H__
#define MYADD(n1, n2) ((n1)+(n2))//더하기
#define MYSUB(n1, n2) ((n1)-(n2))//빼기
#define MYMUL(n1, n2) ((n1)*(n2))//곱하기
#define MYDIV(n1, n2) ((n1)/(n2))//나누기

typedef struct{
    int n1;//첫번째 정수
    int n2;//두번째 정수
    char how[3];//연산자 저장
}Mycal;
#endif