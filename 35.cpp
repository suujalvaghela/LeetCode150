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

ListNode *rotateK(ListNode *head, int k)
{
    ListNode *curr = head;
    int ctr = 0;
    while (ctr < k)
    {
        if (curr == nullptr)
        {
            return head;
        }
        curr = curr->next;
        ctr++;
    }
    ListNode *newHead = rotateK(curr, k);

    curr = head;
    ctr = 0;

    while (ctr < k)
    {
        ListNode *nextN = curr->next;
        curr->next = newHead;
        newHead = curr;
        curr = nextN;
        ctr++;
    }
    return newHead;
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

    int k = 2;

    ListNode *head = rotateK(n1, k);
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