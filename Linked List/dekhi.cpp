#include<bits/stdc++.h>
using namespace std;

struct st
{
    int val;
    struct st *next;
};
typedef  st yo;
yo *head, *rev;
void p(yo *yoyo)
{
    if(yoyo == NULL)
        return;
        cout<<yoyo->val<<endl;

    p(yoyo->next);
}
int main()
{
    head = (yo*)malloc(sizeof(yo));


    yo *tmp = (yo*) malloc(sizeof(yo));
    head->val = 10;
    head->next = NULL;
    tmp = head;
    for(int i = 1; i<=5; i++)
    {
        yo *now = (yo*) malloc(sizeof(yo));
        now->val = i;
        now->next = NULL;
        tmp->next = now;
        tmp = now;

    }
    yo *tempo = head;
    int cn = -1, tr = 1;

    rev = (yo*)malloc(sizeof(yo));

    tempo = tempo->next;
    head->next = NULL;
     yo *now = (yo*) malloc(sizeof(yo));
    while(tempo!=NULL)
    {

        now = tempo;
        now->next = head;
       head = now;
        tempo = tempo->next;
    }
    p(now);
}
