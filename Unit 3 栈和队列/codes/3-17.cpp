#include <stdio.h>
#include <stdlib.h>
#define stack_init_size 100
#define stack_increment 10
typedef struct
{
        char *base;
        int top, stacksize;
} sqstack;

int init_stack(sqstack &s)
{
        s.base = (char*)malloc(stack_init_size * sizeof(char));
        if (!s.base)
        {
                exit(-1);
        }
        s.top = 0;
        s.stacksize = stack_init_size;
        return 1;

}

int destorystack(sqstack &s)
{
        free(s.base);
        s.base = NULL;
        s.stacksize = 0;
        s.top = NULL;
        return 1;
}

int push(sqstack &s, char e)
{
        char *newbase;
        if (s.top == s.stacksize)
        {
                newbase = (char*)realloc(s.base, (s.stacksize + stack_increment) * sizeof(char));
                if (!newbase)
                {
                        exit(-1);
                }
                s.base = newbase;
                s.stacksize += stack_increment;
        }
        s.base[s.top++] = e;
        return 1;

}

int pop(sqstack &s, char &e)
{
        if (!s.top)
        {
                return 0;
        }
        e = s.base[--s.top];
        return 1;

}

/*3.17*/
int shiqi(char a[])
{
        int i = 0;
        sqstack s;
        char x;
        init_stack(s);
        while (a[i] != '&' && a[i])
        {

                push(s, a[i]);
                i++;

        }
        if (!a[i])/*这里要特别留意&后面为空的情况*/
        {
                return 0;
        }
        i++;
        while (a[i] != '@' && a[i])
        {
                pop(s, x);

                if (x != a[i])
                {
                        destorystack(s);

                        return 0;
                }
                i++;

        }
        return 1;
}

int main()
{
        char a[100];
        int k;
        gets(a);
        k = shiqi(a);
        if(k==1)printf("YES\n");
        else
            printf("NO\n");
        return 0;
}