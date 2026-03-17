#include "Queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// 初始化队列
void QueueInit(Queue* pq)
{
    assert(pq);

    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

// 销毁队列
void QueueDestroy(Queue* pq)
{
    assert(pq);

    QNode* cur = pq->phead;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    pq->phead = NULL;
    pq->ptail = NULL;
    pq->size = 0;
}

// 入队列，队尾
void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);

    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }

    newnode->val = x;
    newnode->next = NULL;

    // 如果队列为空
    if (pq->phead == NULL)
    {
        pq->phead = newnode;
        pq->ptail = newnode;
    }
    else
    {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }

    pq->size++;
}

// 出队列，队头
void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->phead);

    QNode* next = pq->phead->next;
    free(pq->phead);
    pq->phead = next;

    // 如果删除后队列为空，要把 ptail 也置空
    if (pq->phead == NULL)
    {
        pq->ptail = NULL;
    }

    pq->size--;
}

// 取队头数据
QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->phead);

    return pq->phead->val;
}

// 取队尾数据
QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->ptail);

    return pq->ptail->val;
}

// 队列判空
bool QueueEmpty(Queue* pq)
{
    assert(pq);

    return pq->size == 0;
}

// 队列有效元素个数
int QueueSize(Queue* pq)
{
    assert(pq);

    return pq->size;
}
