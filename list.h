#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

struct DataPertandingan {
    string namaTim;
    int skor;
    string tanggal;
};

typedef DataPertandingan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void Create_List(List &L);
address New_Element(infotype data);
void Insert_First(List &L, address P);
void Insert_Last(List &L, address P);
void Insert_After(List &L, address prec, address P);
void Delete_First(List &L, address &P);
void Delete_Last(List &L, address &P);
void Delete_After(List &L, address prec, address &P);
void Show(List L);
void SortBySkor(List &L);
address SearchByNamaTim(List L, string data);


#endif // LIST_H_INCLUDED
