//
// Created by expoli on 2020/12/29.
//

#ifndef EXAMPLE3_PV_H
#define EXAMPLE3_PV_H

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
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                                (Linux specific) */
} semun;

int initsem(key_t semkey, int nsems);

int p(int semid);

int v(int semid);

#endif//EXAMPLE2_PV_H


#endif //EXAMPLE3_PV_H
