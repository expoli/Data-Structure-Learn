//
// Created by expoli on 2020/9/7.
//

#include "LinkQueue.h"
#include "iostream"


namespace linkqueue {
    void InitQueue(LiQueue *&queue) {
        queue = (LiQueue *) malloc(sizeof(LiQueue));
        queue->front = queue->rear = NULL;
    }

    void DestroyQueue_1(LiQueue *&queue) {
        QNode *p = queue->front, *r;
        while (p != NULL) {
            r = p->next;
            std::cout << "free" << p->data << std::endl;
            free(p);
            p = r;
        }
        free(queue);
    }

    void DestroyQueue_2(LiQueue *&queue) {
        QNode *p = queue->front, *r;
        if (p != NULL) {
            r = p->next;
            while (r != NULL) {
                std::cout << "free" << p->data << std::endl;
                free(p);
                p = r;
                r = p->next;
            }
        }
        free(p);
        free(queue);
    }

    bool QueueEmpty(LiQueue *queue) {
        return (queue->front == NULL);
    }

    void EnQueue(LiQueue *&queue, ElemType e) {
        QNode *p, *s;
        s = (QNode *) malloc(sizeof(QNode));
        s->data = e;
        s->next = NULL;
        if (queue->rear == NULL) {
            queue->front = s;
            queue->rear = s;
        } else {
            queue->rear->next = s;
            queue->rear = s;
        }
    }

    bool DeQueue(LiQueue *&queue, ElemType &x) {
        QNode *p = queue->front;
        if (p == NULL)
            return false;
        if (queue->front == queue->rear)
            queue->front = queue->rear = NULL;
        else
            queue->front = p->next;
        x = p->data;
        free(p);
        return true;
    }
}