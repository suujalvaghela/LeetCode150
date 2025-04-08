#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode *mergeLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return head->next;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(7);
    ListNode *l3 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;

    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(6);

    a1->next = a2;
    a2->next = a3;

    ListNode *newLL = mergeLists(l1, a1);

    while (newLL)
    {
        cout << newLL->data;
        if (newLL->next)
        {
            cout << "->";
        }
        newLL = newLL->next;
    }

    cout << endl;
    return 0;
}