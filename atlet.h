#ifndef ATLET_H_INCLUDED
#define ATLET_H_INCLUDED

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#include <iostream>
using namespace std;
#include <string>

struct atlet {
    int noPunggung;
    string nama;
    string klub;

};

typedef atlet infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

void createList(list &L);
address createElement(infotype data);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address Q, address P);
void deleteFirst(list &L);
void deleteLast(list &L);
void deleteAfter(list &L, address Q);

address findData(list &L, string liga);
void deleteData(list &L, string data);



#endif // ATLET_H_INCLUDED
