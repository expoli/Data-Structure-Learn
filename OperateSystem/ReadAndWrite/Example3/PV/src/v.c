//
// Created by expoli on 2020/12/29.
//

//
// Created by expoli on 2020/12/29.
//

//v.c  V操作
#include "../head/pv.h"

int v(int semid) {
    //    https://sites.uclouvain.be/SystInfo/usr/include/sys/sem.h.html
    /* Structure used for argument to `semop' to describe operations.  */
    //    struct sembuf
    //    {
    //        unsigned short int sem_num;        /* semaphore number */
    //        short int sem_op;                /* semaphore operation */
    //        short int sem_flg;                /* operation flag */
    //    };
    struct sembuf v_buf;

    v_buf.sem_num = 0;
    v_buf.sem_op = 1;//信号量加1
    v_buf.sem_flg = SEM_UNDO;

    if (semop(semid, &v_buf, 1) == -1) {
        perror("v(semid)failed");
        exit(1);
    }
    return (0);
}