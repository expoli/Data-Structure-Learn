#include "PV/head/pv.h"

void handlesem(key_t skey);
void main() {
    key_t semkey_A = 0x201;
    key_t semkey_B = 0x221;
    int semid_A, semid_B;
    if ((semid_A = initsem(semkey_A, 1)) < 0) exit(1);
    if ((semid_B = initsem(semkey_B, 0)) < 0) exit(1);
    printf("A   进程A的信号量标识符%d,它的初始值为%d\n",
           semid_A, semctl(semid_A, 0, GETVAL));
    printf("B   进程B的信号量标识符%d,它的初始值为%d\n",
           semid_B, semctl(semid_B, 0, GETVAL));

    if (fork() != 0)//父进程先执行
    {
        int i;
        for (i = 0; i < 10; i++) {
            p(semid_A);
            printf("A   进程A的信号量值为%d\n", semctl(semid_A, 0, GETVAL));
            v(semid_B);
        }
    } else {
        int j;
        for (j = 0; j < 10; j++) {
            p(semid_B);
            printf("B   进程B的信号量值为%d\n", semctl(semid_B, 0, GETVAL));
            v(semid_A);
        }
    }
    if ((semctl(semid_A, 0, IPC_RMID)) < 0)//删除进程Ad的信号量值，IPC_RMID是删除命令
    {
        perror("semctl error");
        exit(1);
    }
    if ((semctl(semid_B, 0, IPC_RMID)) < 0) {
        perror("semctl error");
        exit(1);
    }
}