//
// Created by expoli on 2020/9/7.
//

#include "LinkQueue.h"
#include "iostream"


namespace linkqueue {
    void InitQueue(LiQueue *&queue) {
        queue = (LiQueue *) malloc(sizeof(LiQueue));
        queue->front = queue->rear = nullptr;
    }

    void DestroyQueue_1(LiQueue *&queue) {
        LinkNode *p = queue->front, *r;
        while (p != nullptr) {
            r = p->next;
            std::cout << "free" << p->data << std::endl;
            free(p);
            p = r;
        }
        free(queue);
    }

    void DestroyQueue_2(LiQueue *&queue) {
        LinkNode *p = queue->front, *r;
        if (p != nullptr) {
            r = p->next;
            while (r != nullptr) {
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
        return (queue->front == nullptr);
    }

    void EnQueue(LiQueue *&queue, ElemType e) {
        LinkNode *p, *s;
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = nullptr;
        if (queue->rear == nullptr) {
            queue->front = s;
            queue->rear = s;
        } else {
            queue->rear->next = s;
            queue->rear = s;
        }
    }

    bool DeQueue(LiQueue *&queue, ElemType &x) {
        LinkNode *p = queue->front;
        if (p == nullptr)
            return false;
        if (queue->front == queue->rear)
            queue->front = queue->rear = nullptr;
        else
            queue->front = p->next;
        x = p->data;
        free(p);
        return true;
    }
}// namespace linkqueue