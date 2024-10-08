#include <iostream>
#include "list.h"

using namespace std;


void Create_List(List &L)
{
    first(L) = NULL;
}
address New_Element(infotype data)
{
    address p = new elmlist;
    info(p) = data;
    next(p) = NULL;

    return p;
}
void Insert_First(List &L, address P)
{
    if (first(L) != NULL)
    {
        next(P) = first(L);
        first(L) = P;
    }
    else
    {
        first(L) = P;
    }
}
void Insert_Last(List &L, address P)
{
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}
void Insert_After(List &L, address prec, address P) {
    if (prec != NULL) {
        next(P) = next(prec);
        next(prec) = P;
    }
}
void Delete_First(List &L, address &P) {
    if (first(L) != NULL) {
        P = first(L);
        first(L) = next(first(L));
        next(P) = NULL;
    } else {
        P = NULL;
    }
}
void Delete_Last(List &L, address &P) {
    if (first(L) == NULL) {
        P = NULL;
    } else if (next(first(L)) == NULL) {
        Delete_First(L, P);
    } else {
        address Q = first(L);
        while (next(next(Q)) != NULL) {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
}
void Delete_After(List &L, address prec, address &P) {
    if (prec != NULL && next(prec) != NULL) {
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
    }
}
void Show(List L) {
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else {
        address p = first(L);
        while (p != NULL) {
            cout << "Nama Tim: " << info(p).namaTim << ", Skor: " << info(p).skor << ", Tanggal: " << info(p).tanggal << endl;
            p = next(p);
        }
    }
}
void SortBySkor(List &L) {
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else {
        List sortedList;
        Create_List(sortedList);
        address current = first(L), nextElemen;

        while (current != NULL) {
            nextElemen = next(current);
            if (first(sortedList) == NULL || info(first(sortedList)).skor > info(current).skor) {
                next(current) = first(sortedList);
                first(sortedList) = current;
            } else {
                address temp = first(sortedList);
                while (next(temp) != NULL && info(next(temp)).skor <= info(current).skor) {
                    temp = next(temp);
                }
                next(current) = next(temp);
                next(temp) = current;
            }
            current = nextElemen;
        }
        first(L) = first(sortedList);
    }
}
address SearchByNamaTim(List L, string data) {
    address p = first(L);
    while (p != NULL) {
        if (info(p).namaTim == data) {
            return p;
        }
        p = next(p);
    }
    return NULL;
}
