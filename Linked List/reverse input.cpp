#include<bits/stdc++.h>
using namespace std;

struct st
{
    int val;
    struct st * next;
};

typedef struct st node;

node *head;

void insertt()
{
    node *tmp;
    tmp = (node*) malloc(sizeof(node));

    tmp->val = 0;
    tmp->next = NULL;
    head = tmp;

    for(int i = 1; i <10; i++)
    {
        node *now;
        now = (node*)malloc(sizeof(node));

        now->val = i;
        now->next = NULL;
        tmp->next = now;
        tmp = now;

    }
}
int main()
{
    insertt();
    node *pp, *ppp;
    pp = head;
    ppp = pp;
    pp = pp->next;
    printf("%d\n",pp->val);
    while(pp!= NULL)
    {

        pp = pp->next;
        node *yo;
        yo = (node*)malloc(sizeof(yo));
        yo = pp;
        yo->next = head;
        head = yo;
//        ppp = pp;
//        ppp->next = head;
//        head = ppp;1

//        pp = pp->next;
    }
    ppp->next = NULL;
    while(head!= NULL)
    {
        printf("%d\n",head->val);
        head = head->next;
    }
}
