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

ListNode *reverseLL(ListNode *head, int left, int right)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head;
    ListNode *preP = dummy;

    for (int i = 0; i < left - 1; i++)
    {
        curr = curr->next;
        preP = preP->next;
    }
    ListNode *extCurr = curr;
    ListNode *preNode = nullptr;
    for (int i = 0; i <= right - left; i++)
    {
        ListNode *nextN = curr->next;
        curr->next = preNode;
        preNode = curr;
        curr = nextN;
    }
    preP->next = preNode;
    extCurr->next = curr;

    return dummy->next;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    int left = 2, right = 4;

    ListNode *curr = reverseLL(n1, left, right);

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