//
//  Circular_LinkedList.h
//  Circular_LinkedList
//
//  Created by Han Sol Lee on 9/21/16.
//  Copyright © 2016 Solly. All rights reserved.
//
#include "Employee/Employee.h"

#ifndef Circular_LinkedList_h
#define Circular_LinkedList_h

#define TRUE 1
#define FALSE 0

// typedef int Data;
typedef Employee *Data;

typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _circularLinkedList {
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);  // add node to tail

void LInsertFront(List *plist, Data data);  // add node to head


int LFirst(List *plist, Data *pdata);
int LNext(List *plist, Data *pdata);        // circular next
Data LRemove(List *plist);
int LCount(List *plist);
#endif /* Circular_LinkedList_h */
