/* Introducerea unor elemente in lista mereu ordonate  */

#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int key;
    struct nod *next,*prev;
}tip_nod;

typedef struct
{
    tip_nod *head;
}tip_head;

tip_head* makenull(tip_head *H)
{
    H=(tip_head*)malloc(sizeof(tip_head));
    H->head=(tip_nod*)malloc(sizeof(tip_nod));
    H->head=NULL;
    return H;
}

tip_nod* init_nod(int x)
{
    tip_nod *e;
    e=(tip_nod*)malloc(sizeof(tip_nod));
    e->key=x;
    e->next=e->prev=NULL;
    return e;
}


void insert(tip_head *H,tip_nod *x)
{
    tip_nod *y;
    if(H->head==NULL) H->head=x;
    else if(H->head->key<x->key)
    {
        H->head->prev=x;
        x->next=H->head;
        H->head=x;
    }
    else
    {
        y=H->head;
        while(y->key>x->key && y->next!=NULL)
        {
            y=y->next;
        }
        if(y->next==NULL &&y->key>x->key)
        {
            y->next=x;
            x->prev=y;
        }
        else
        {
            x->next=y;
            x->prev=y->prev;
            y->prev->next=x;
            y->prev=x;
        }

    }
    return;
}
void printeaza_lista(tip_head *H)
{
    tip_nod *n;
    n=H->head;
    printf("elementele listei sunt:");
    while(n!=NULL)
    {
        printf("%d ",n->key);
        n=n->next;
    }
}

void main()
{
    int key,i,n,a[100];
    tip_head *H;
    tip_nod *x;

    H=makenull(H);

    printf("n=");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("introduceti keya : ");
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        x=init_nod(a[i]);
        insert(H,x);
    }
    printeaza_lista(H);

    /*printf("introduceti elemente in lista pana la tastarea cifrei 0:");
    scanf("%d",&k);
    while(k!=0)
    {
        x=init_nod(k);
        insert(H,x);
        scanf("%d",&k);
    }

    printeaza_lista(H);*/
}