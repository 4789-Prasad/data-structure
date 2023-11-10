#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
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
        printf("\n * 2.Add atthe beginning*");
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
            printf("\n Enter a valid choice ");
        }
    }
}

void create(int data)
{
    struct node *q, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
        tmp->prev = q;
    }
}

void addbg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = start;
    tmp->prev = NULL;
    if (start != NULL)
        start->prev = tmp;
    start = tmp;
}

void addafter(int data, int position)
{
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0; i < position - 1; i++)
    {
        q = q->next;
    }
    if (q == NULL)
    {
        printf("There are less than %d elements ", position);
        return;
    }
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = q->next;
    tmp->prev = q;
    if (q->next != NULL)
        q->next->prev = tmp;
    q->next = tmp;
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
    printf("Linked list (forward):\n ");
    while (q != NULL)
    {
        printf("%d -> ", q->info);
        q = q->next;
    }
    printf("NULL\n");

    // Display the list in reverse order
    printf("Linked list (backward):\n ");
    q = start;
    while (q->next != NULL)
        q = q->next;
    while (q != NULL)
    {
        printf("%d -> ", q->info);
        q = q->prev;
    }
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
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(tmp);
        return;
    }
    tmp = start;
    while (tmp != NULL && tmp->info != data)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }
    prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = prev;
    free(tmp);
}
