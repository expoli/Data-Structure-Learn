#include "PV/head/pv.h"

void handlesem(key_t skey);
void main() {
    key_t semkey = 0x200;
    int i;
    for (i = 0; i < 3; i++) {
        if (fork() == 0)      //父进程负责产生3个子进程
            handlesem(semkey);//子进程中才执行handlesem，做完后就exit。
    }
}

void handlesem(key_t skey) {
    int semid;
    pid_t pid = getpid();

    if ((semid = initsem(skey)) < 0)
        exit(1);
    printf("进程 %d 在临界资源区之前 \n", pid);
    p(semid);//进程进入临界资源区，信号量减少1
    printf("进程 %d 在使用临界资源时，停止1s \n", pid);

    /*in real life do something interesting */
    sleep(1);
    printf("进程 %d 退出临界区后 \n", pid);

    v(semid);//进程退出临界资源区，信号量加1

    printf("进程 %d 完全退出\n", pid);
    exit(0);
}