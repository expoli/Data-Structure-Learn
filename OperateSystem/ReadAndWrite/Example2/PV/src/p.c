//
// Created by expoli on 2020/12/29.
//

//p.c  P操作
#include "../head/pv.h"

int p(int semid) {
//    https://sites.uclouvain.be/SystInfo/usr/include/sys/sem.h.html
/* Structure used for argument to `semop' to describe operations.  */
//    struct sembuf
//    {
//        unsigned short int sem_num;        /* semaphore number */
//        short int sem_op;                /* semaphore operation */
//        short int sem_flg;                /* operation flag */
//    };


    struct sembuf p_buf;// 用于“ semop”参数以描述操作的结构。

    p_buf.sem_num = 0;
    p_buf.sem_op = -1;//信号量减1，注意这一行的1前面有个负号
    p_buf.sem_flg = SEM_UNDO;

    //p_buf = {0,-1,SEM_UNDO};
    if (semop(semid, &p_buf, 1) == -1) {
        perror("p(semid)failed");
        exit(1);
    }
    return (0);
}