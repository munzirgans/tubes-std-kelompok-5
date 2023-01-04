#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>

using namespace std;

#define info(p) p->info
#define next(p) p->next
#define Operator(p) p->Operator
#define first(L) L.first
#define nil NULL

struct infotype_user{
    string nik, nama, nomorHP;
};
typedef struct elmUser *adr_user;
typedef struct elmOperator *adr_operator;
struct elmUser{
    infotype_user info;
    adr_user next;
    adr_operator Operator;
};

struct ListUser{
    adr_user first;
};

struct ListOperator{
    adr_operator first;
};

typedef string infotype_operator;
struct elmOperator{
    infotype_operator info;
    adr_operator next;
};

void createListUser(ListUser &L);
void createListOperator(ListOperator &L);
adr_user createElmUser(infotype_user x);
adr_operator createElmOperator(infotype_operator x);
adr_user searchUser(ListUser L, string nik);
adr_operator searchOperator(ListOperator L, string namaOP);
void insertUser(ListUser &L, adr_user p);
void insertOperator(ListOperator &L, adr_operator q);
void addOperator(ListUser L, ListOperator L2, string nik, string namaOP);
void delOperatorUser(ListUser L, ListOperator L2, string nik, string namaOP);
void delUser(ListUser &L, adr_user p);
void delOperator(ListOperator &L, ListUser &L2, string namaOP);
void showAllOperator(ListOperator L);
void showAllUserWithOperator(ListUser L);
#endif // TUBES_H_INCLUDED
