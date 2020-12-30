#include "PV/head/pv.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N_WRITER 3 //写者数目
#define N_READER 5 //读者数目
#define W_SLEEP  1 //控制写频率
#define R_SLEEP  1 //控制读频率

pthread_t wid[N_WRITER], rid[N_READER];

int data = 0;
int readerCnt = 0;
const int MAX_RAND = 1000;//产生的最大随机数


extern int semid_Writer, semid_accessReaderCnt;
key_t semkey_Writer = 0x200;
key_t semkey_accessReaderCnt = 0x220;

void handlesem(key_t skey);

// 读者方法
void Write() {
    int rd = rand() % MAX_RAND;
    printf("write %d\n", rd);
    data = rd;
}

// 写者方法
void Read() {
    printf("read %d\n", data);
}

// 写者线程
_Noreturn void *writer(void *in) {
    while (1) {
        // 尝试取得写锁
        p(semid_Writer);
        Write();
        // 解除读写锁
        v(semid_Writer);
        sleep(W_SLEEP);
    }
    pthread_exit((void *) 0);
}

_Noreturn void *reader(void *in) {
    while (1) {
        // 读者互斥、修改读者数量
        p(semid_accessReaderCnt);
        readerCnt++;
        // 初始情况、没有读者申请读写锁
        if (readerCnt == 1) {
            p(semid_Writer);
        }
        v(semid_accessReaderCnt);

        Read();
        // 读者已完成
        p(semid_accessReaderCnt);
        readerCnt--;
        // 读者全部完成
        if (readerCnt == 0) {
            v(semid_accessReaderCnt);
        }
        v(semid_accessReaderCnt);
        sleep(R_SLEEP);
    }
    pthread_exit((void *) 0);
}

int main() {

    key_t semkey_Writer = 0x200;
    key_t semkey_accessReaderCnt = 0x220;

    if ((semid_Writer = initsem(semkey_Writer, 0)) < 0) exit(1);
    if ((semid_accessReaderCnt = initsem(semkey_accessReaderCnt, 0)) < 0) exit(1);
    printf("读者   的信号量标识符%d,它的初始值为%d\n",
           semid_Writer, semctl(semid_Writer, 0, GETVAL));
    printf("写者   的信号量标识符%d,它的初始值为%d\n",
           semid_accessReaderCnt, semctl(semid_accessReaderCnt, 0, GETVAL));

    int i = 0;
    // 读者
    for (i = 0; i < N_READER; i++) {
        pthread_create(&wid[i], NULL, reader, NULL);
    }
    // 写者
    for (i = 0; i < N_WRITER; i++) {
        pthread_create(&rid[i], NULL, writer, NULL);
    }
    while (1) {
        sleep(10);
    }

//    fork() returns -1 if it fails, and if it succeeds,
//    it returns the forked child's pid in the parent,
//    and 0 in the child. So if (fork() != 0) tests whether it's the parent process.
//    if (fork() != 0)//父进程先执行
//    {
//        int i;
//        for (i = 0; i < 10; i++) {
//            p(semid_A);
//            printf("A   进程A的信号量值为%d\n", semctl(semid_A, 0, GETVAL));
//            v(semid_B);
//        }
//    } else {
//        int j;
//        for (j = 0; j < 10; j++) {
//            p(semid_B);
//            printf("B   进程B的信号量值为%d\n", semctl(semid_B, 0, GETVAL));
//            v(semid_A);
//        }
//    }
    if ((semctl(semid_Writer, 0, IPC_RMID)) < 0)//删除进程Ad的信号量值，IPC_RMID是删除命令
    {
        perror("semctl error");
        exit(1);
    }
    if ((semctl(semid_accessReaderCnt, 0, IPC_RMID)) < 0) {
        perror("semctl error");
        exit(1);
    }

    return 0;
}