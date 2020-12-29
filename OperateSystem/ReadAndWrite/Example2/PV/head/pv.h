//
// Created by expoli on 2020/12/29.
//

#ifndef EXAMPLE2_PV_H
#define EXAMPLE2_PV_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

#define SEMPERM 0600
#define TRUE 1
#define FALSE 0
typedef union _semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
} semun;

int initsem(key_t semkey);
int p(int semid);
int v(int semid);

#endif//EXAMPLE2_PV_H
