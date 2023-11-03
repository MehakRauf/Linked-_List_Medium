#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void sum(int value)
{
    struct List *curr1 = start;
    while (curr1 != NULL)
    {
        struct List *curr2 = start;
        while (curr2 != NULL)
        {
            if (curr1->data + curr2->data == value)
            {
                cout<< curr1->data <<" "<<curr2->data<<endl;
            }
            curr2=curr2->next;
        }
        curr1=curr1->next;
    }
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    insert(4);
    insert(14);
    insert(5);
    insert(7);
    insert(2);
    insert(9);
    insert(0);
    insert(8);
    sum(9);
    print();
}