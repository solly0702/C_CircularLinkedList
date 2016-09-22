//
//  main.c
//  Circular_LinkedList
//
//  Created by Han Sol Lee on 9/20/16.
//  Copyright © 2016 Solly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Employee/Employee.h"
#include "Circular_LinkedList.h"

Employee *WhoIsNightDuty(List *plist, char *name, int dat);
void ShowEmployeeInfo(Employee *emp);

int main(int argc, const char * argv[]) {
    int i;
    Employee *pemp;
    
    // init list;
    List list;
    ListInit(&list);
    
    // store data
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empId = 11111;
    strcpy(pemp->name, "Terry");
    LInsert(&list, pemp);
    
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empId = 2222;
    strcpy(pemp->name, "John");
    LInsert(&list, pemp);
    
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empId = 333;
    strcpy(pemp->name, "Lindey");
    LInsert(&list, pemp);
    
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empId = 44;
    strcpy(pemp->name, "Sol");
    LInsert(&list, pemp);
    
    pemp = (Employee*)malloc(sizeof(Employee));
    pemp->empId = 5;
    strcpy(pemp->name, "Rick");
    LInsert(&list, pemp);
    
    // who is working at night after 3 days from Terry?
    pemp = WhoIsNightDuty(&list, "Terry", 2);
    ShowEmployeeInfo(pemp);
    
    // who is working at night after 15 dats from Sol?
    pemp = WhoIsNightDuty(&list, "Sol", 15);
    ShowEmployeeInfo(pemp);
    
    // delete list
    if(LFirst(&list, &pemp)) {
        free(pemp);
        
        for(i=0; i<LCount(&list)-1; i++) {
            if(LNext(&list, &pemp))
                free(pemp);
        }
    }
    
    return 0;
    
}

Employee *WhoIsNightDuty(List *plist, char *name, int day) {
    int i, num;
    Employee *ret;
    
    num = LCount(plist);
    
    // find name
    LFirst(plist, &ret);
    if(strcmp(ret->name, name) != 0) {
        for(i=0; i<num-1; i++) {
            LNext(plist, &ret);
            
            if(strcmp(ret->name, name) == 0)
                break;
        }
        if(i >= num-1)  // no name in the list
            return NULL;
    }
    
    // days after
    for(i=0; i<day; i++)
        LNext(plist, &ret);
        
    return ret;
    
}

void ShowEmployeeInfo(Employee *emp) {
    printf("Employee Name: %s \n", emp->name);
    printf("Employee ID: %d \n", emp->empId);
}

