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

ListNode *partitionN(ListNode *head, int val)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *dummyLeftHead = new ListNode(0);
    ListNode *dummyRightHead = new ListNode(0);
    ListNode *dummyRight = dummyRightHead;
    ListNode *dummyLeft = dummyLeftHead;

    ListNode *curr = head;

    while (curr)
    {
        if (curr->data < val)
        {
            dummyLeft->next = curr;
            dummyLeft = dummyLeft->next;
        }
        else
        {
            dummyRight->next = curr;
            dummyRight = dummyRight->next;
        }
        curr = curr->next;
    }
    dummyLeft->next = dummyRightHead->next;
    dummyRight->next = nullptr;

    return dummyLeftHead->next;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    // ListNode *n3 = new ListNode(3);
    // ListNode *n4 = new ListNode(2);
    // ListNode *n5 = new ListNode(5);
    // ListNode *n6 = new ListNode(2);

    n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;

    int val = 2;

    ListNode *head = partitionN(n1, val);
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