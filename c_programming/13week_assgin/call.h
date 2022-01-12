//비상연락망 구조체 담기, success
#ifndef __CALL_H__
#define __CALL_H__

typedef struct call{
    char name[10];
    char pnum[15];
    struct call *next;
} PhoneBook;

#endif