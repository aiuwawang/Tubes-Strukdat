#include "atlet.h"

address createElement(infotype data) {
    address P;
    P = new elmlist;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirst(list &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(list &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfter(list &L, address Q, address P) {
    if (Q != NULL) {
        next(P) = next(Q);
        prev(P) = Q;

        if (next(Q) != NULL) {
            prev(next(Q)) = P;
        } else {
            last(L) = P;
        }
        next(Q) = P;
    }
}

void deleteFirst(list &L) {
    if (first(L) != NULL) {
        address P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        delete P;
    }
}

void deleteLast(list &L) {
    if (first(L) != NULL) {
        address P = last(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        delete P;
    }
}

void deleteAfter(list &L, address Q) {
    if (Q != NULL && next(Q) != NULL) {
        address P = next(Q);

        if (next(P) != NULL) {
            next(Q) = next(P);
            prev(next(P)) = Q;
        } else {
            next(Q) = NULL;
            last(L) = Q;
        }

        next(P) = NULL;
        prev(P) = NULL;
        delete P;
    }
}

address findData(list &L, string liga) {
    address P = first(L);
    while (P != NULL) {
        if (info(P).klub == liga) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteData(list &L, string data) {
    address P = findData(L, data);
    if (P != NULL) {
        if (P == first(L) && first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
            delete P;
        } else if (P == first(L)) {
            deleteFirst(L);
        } else if (P == last(L)) {
            deleteLast(L);
        } else {
            deleteAfter(L, prev(P));
        }
    } else {
        cout << "liga tidak ditemukan!!!" << endl;
    }
}
