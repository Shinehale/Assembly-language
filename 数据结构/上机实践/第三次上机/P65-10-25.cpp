#include <stdio.h>
#include <stdlib.h>

#define TOTAL 10        

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreatLink(int num);
LinkList LinkInsertSort(LinkList head);
int PrintLink(LinkList head);

LinkList CreatLink(int num)
{
    int i, data;

    LinkList head = NULL, p = NULL, q;

    for (i = 0; i < num; i++)
    {
        scanf("%d", &data);
        q = (LinkList)malloc(sizeof(LNode));
        q->data = data;
        q->next = NULL;
        if (i == 0)
        {
            head = q;
        }
        else
        {
            p->next = q;
        }
        p = q;
    }
    return head;
}

LinkList LinkInsertSort(LinkList head)
{
    LinkList head2, current, p, q;

    if (head == NULL)
        return head;
    head2 = head->next;
    head->next = NULL;

    while (head2)
    {
        current = head2;
        head2 = head2->next;

        for (p = NULL, q = head; q && q->data <= current->data; p = q, q = q->next);

        if (q == head)
        {
            head = current;
        }
        else
        {
            p->next = current;
        }
        current->next = q;
    }
    return head;
}

int PrintLink(LinkList head)
{
    LinkList p;
    for (p = head; p ;p = p->next)
    {
        printf("%-3d ", p->data);
    }
    return 0;
}

int main()
{
    LinkList head;
    printf("input the total number you want to cultivate the link string:\n");
    head = CreatLink(TOTAL);
    head = LinkInsertSort(head);
    printf("after sorted:\n");
    PrintLink(head);
    putchar('\n');
    return 0;
}