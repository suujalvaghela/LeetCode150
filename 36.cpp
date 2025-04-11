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

ListNode *removeEl(ListNode *head, int k)
{
    int count = 0;
    ListNode *curr = head;

    while (curr)
    {
        count++;
        curr = curr->next;
    }
    int position = count - k;

    if (position == 0)
    {
        return head->next;
    }
    curr = head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
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

    ListNode *head = removeEl(n1, k);
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