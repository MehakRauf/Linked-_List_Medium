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

void swk(int k)
{
    struct List *curr1 = start;
    int length = 0;
    while (curr1 != NULL)
    {
        length++;
        curr1 = curr1->next;
    }
    List *temp1, *temp2;
    curr1 = start;
    int count = 1;
    while (curr1 != NULL)
    {
        if (count == k)
        {
            temp1 = curr1;
        }
        if (count == (length - k + 1))
        {
            temp2 = curr1;
        }
        curr1 = curr1->next;
        count++;
    }
    swap(temp1->data, temp2->data);
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    insert(2);
    insert(14);
    insert(5);
    insert(9);
    insert(2);
    insert(6);
    insert(2);
    insert(9);
    print();
    swk(2);
    print();
}