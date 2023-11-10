#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
} *start;

void create(int data);
void addbg(int data);
void addafter(int data, int position);
void display();
void del(int data);

int main()
{
    int n, m, i, choice, position;
    start = NULL;
    while (1)
    {
        printf("\n ********* MENU *********");
        printf("\n * 1.Insert element     *");
        printf("\n * 2.Add beginning      *");
        printf("\n * 3.Add after position *");
        printf("\n * 4.Display            *");
        printf("\n * 5.Delete             *");
        printf("\n * 6.Exit               *");
        printf("\n ************************");
        printf("\n enter choice:  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n How many nodes do you want: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\n enter %d element : ", i + 1);
                scanf("%d", &m);
                create(m);
            }
            break;
        case 2:
            printf("\n enter element ");
            scanf("%d", &m);
            addbg(m);
            break;
        case 3:
            printf("\n enter element ");
            scanf("%d", &m);
            printf("\n enter element position ");
            scanf("%d", &position);
            addafter(m, position);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n enter element ");
            scanf("%d", &m);
            del(m);
            break;
        case 6:
            printf("\n \t \t THANK YOU");
            exit(0);
        default:
            printf("\n Enter valid choice ");
        }
    }
}

void create(int data)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    if (start == NULL)
    {
        start = tmp;
        start->link = start; // Make it circular
    }
    else
    {
        q = start;
        while (q->link != start)
            q = q->link;
        q->link = tmp;
        tmp->link = start; // Make it circular
    }
}

void addbg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = start;
    start = tmp;
}

void addafter(int data, int position)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < position - 1; i++)
    {
        q = q->link;
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        printf("\n List is empty \n ");
        return;
    }
    q = start;
    printf("Linked list:\n ");
    do
    {
        printf("%d -> ", q->info);
        q = q->link;
    } while (q != start);
    printf("NULL\n");
}

void del(int data)
{
    struct node *tmp, *prev;
    if (start == NULL)
    {
        printf("\n List is empty \n");
        return;
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return;
    }
    tmp = start;
    prev = NULL;
    while (tmp != start && tmp->info != data)
    {
        prev = tmp;
        tmp = tmp->link;
    }
    if (tmp == start)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }
    prev->link = tmp->link;
    free(tmp);
}
