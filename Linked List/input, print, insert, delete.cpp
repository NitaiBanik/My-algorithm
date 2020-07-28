#include<stdio.h>
#include<stdlib.h>

struct link
{
    int val;
    struct link *next;
};

typedef struct link node;
node *head, *rev;

void mylistt()
{
    node *yo;
    yo = (node*) malloc(sizeof(node));

    yo->val = 0;
    yo->next = NULL;
    head = yo;

    for(int i = 1; i <= 5; i++)
    {
        node *tmp;

        tmp = (node*) malloc(sizeof(node));
        tmp->val = i;
        tmp->next = NULL;
        yo->next = tmp;
        yo = tmp;
    }

}

void revv(node *yoo)
{
    if(yoo == NULL) return;

    revv(yoo->next);
    printf("haha = %d\n", yoo->val);

}
int main()
{
    mylistt();

    node *now;
    now = head;
    ///reverse print
    revv(now);
    int pos = 3;
    int cn = 0;
    ///inserting in 4th position

    while(now != NULL)
    {
        cn++;
        if(cn == pos)
        {

            node *tp, *in;
            ///storing the current address in tp
            tp = now->next;
            in = (node*) malloc(sizeof(node));
            in->val = 9;
            ///connecting after node
            in->next = tp;
            ///connecting new node
            now->next = in;

            break;

        }
        now = now->next;
    }

    now = head;
    while(now != NULL)
    {
        printf("%d\n",now->val);
        now = now->next;
    }

    ///deleting 4th value
    cn = 0;
    now = head;

    while(now != NULL)
    {
        cn++;
        if(cn == 3)
        {
            node *tpp;
            ///skipping the node
            now->next = now->next->next;

            break;
        }
        now = now->next;
    }
    now = head;
    while(now != NULL)
    {
        printf("%d\n",now->val);
        now = now->next;
    }
}
