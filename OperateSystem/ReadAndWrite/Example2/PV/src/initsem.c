//
// Created by expoli on 2020/12/29.
//

//initsem.c  对信号量赋初值，初值固定为1
#include "../head/pv.h"

int initsem(key_t semkey, int nsems) {
    int status = 0, semid;                                                  //信号量标识符semid
    if ((semid = semget(semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1) {// 创建信号量失败，第二个参数为此信号集里的信号量数量
        if (errno == EEXIST)                                                //EEXIST：信号量集已经存在，无法创建
            semid = semget(semkey, 1, 0);                                   //创建一个信号量
    } else {                                                                // 成功创建
        semun arg;                                                          // 信号量
        arg.val = nsems;                                                    //信号量的初值
        status = semctl(semid, 0, SETVAL, arg);                             //设置信号量集中的一个单独的信号量的值。
    }
    if (semid == -1 || status == -1) {
        perror("initsem failed");
        return (-1);
    }
    /*all ok*/
    return (semid);
}