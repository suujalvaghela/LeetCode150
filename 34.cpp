#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode *random;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->random = nullptr;
    }
};

ListNode *duplic(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode *curr = head;

    while (curr)
    {
        ListNode *newNode = new ListNode(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    curr = head;
    while (curr)
    {
        if (curr->random)
        {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    ListNode *newHead = head->next;
    ListNode *newCurr = newHead;
    curr = head;

    while (curr)
    {
        curr->next = newCurr->next;
        curr = curr->next;
        if (curr)
        {
            newCurr->next = curr->next;
            newCurr = newCurr->next;
        }
    }
    return newHead;
}

int main()
{

    ListNode *n1 = new ListNode(7);
    ListNode *n2 = new ListNode(13);
    ListNode *n3 = new ListNode(11);
    ListNode *n4 = new ListNode(10);
    ListNode *n5 = new ListNode(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    ListNode *head = duplic(n1);
    ListNode *curr = head;

    while (curr)
    {
        cout << curr->data;
        if (curr->next)
        {
            cout << "->";
        }
        curr = curr->next;
    }
    cout << endl;
    return 0;
}