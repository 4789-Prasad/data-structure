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
    {
        start = tmp;
        start->next = start;
        start->prev = start;
    }
    else
    {
        q = start->prev;
        q->next = tmp;
        tmp->next = start;
        start->prev = tmp;
        tmp->prev = q;
    }
}

void addbg(int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = start;
    tmp->prev = start->prev;
    start->prev->next = tmp;
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
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->next = q->next;
    tmp->prev = q;
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
    do
    {
        printf("%d -> ", q->info);
        q = q->next;
    } while (q != start);
    printf("NULL\n");

    // Display the list in reverse order
    printf("Linked list (backward):\n ");
    q = start->prev;
    do
    {
        printf("%d -> ", q->info);
        q = q->prev;
    } while (q != start->prev);
    printf("NULL\n");
}

void del(int data)
{
    struct node *tmp, *prev, *next;
    if (start == NULL)
    {
        printf("\n List is empty \n");
        return;
    }

    tmp = start;
    do
    {
        if (tmp->info == data)
        {
            prev = tmp->prev;
            next = tmp->next;
            prev->next = next;
            next->prev = prev;

            if (tmp == start)
            {
                start = next;
            }

            free(tmp);
            printf("Node with data %d deleted successfully.\n", data);
            return;
        }

        tmp = tmp->next;
    } while (tmp != start);

    printf("Node with data %d not found.\n", data);
}
