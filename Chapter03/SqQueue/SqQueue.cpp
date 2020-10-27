//
// Created by expoli on 2020/9/7.
//

#include "SqQueue.h"
#include "iostream"

namespace sqqueue {
    void InitQueue(SqQueue *&q) {
        q = (SqQueue *) malloc(sizeof(SqQueue));
        q->front = q->rear = -1;
    }

    void DestoryQueue(SqQueue *&q) {
        free(q);
    }

    bool QueueEmpty(SqQueue *q) {
        return (q->rear == q->front);
    }

    bool enQueue(SqQueue *&q, ElemType e) {
        if (q->rear == MAXSIZE - 1)
            return false;
        q->rear++;
        q->data[q->rear] = e;
        return true;
    }

    bool deQueue(SqQueue *&q, ElemType &e) {
        if (q->front == q->rear)
            return false;
        q->front++;
        e = q->data[q->front];
        return true;
    }
}// namespace sqqueue


/*
 * 如果知道队头指针和队列中元素个数，则可以计算出队尾指针。也就是说，可以用队列中元素个数代替队尾指针。
该环形队列的4要素：
队空条件：count＝0
队满条件：count＝MaxSize
进队e操作：rear=(rear+1)%MaxSize; 将e放在rear处
出队操作：front=(front+1)%MaxSize; 取出front处元素e;
 */
namespace cirqueue {
    void InitQueue(CirQueue *&queue) {
        queue = (CirQueue *) malloc(sizeof(CirQueue));
        queue->front = 0;
        queue->count = 0;
    }

    void DestoryQueue(CirQueue *&queue) {
        free(queue);
    }

    bool QueueEmpty(CirQueue *queue) {
        return (queue->count == 0);
    }

    bool EnQueue(CirQueue *&queue, ElemType e) {
        int rear;// 临时队尾指针
        if (queue->count == MAXSIZE)
            return false;
        else {
            rear = (queue->front + queue->count) % MAXSIZE;
            rear = (rear + 1) % MAXSIZE;// rear++
            queue->data[rear] = e;
            queue->count++;
            return true;
        }
    }

    bool DeQueue(CirQueue *&queue, ElemType &e) {
        if (queue->count == 0)
            return false;
        else {
            queue->front = (queue->front + 1) % MAXSIZE;
            e = queue->data[queue->front];
            queue->count--;
            return true;
        }
    }
}// namespace cirqueue