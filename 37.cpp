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

ListNode *removeD(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *preC = dummy;
    ListNode *curr = head;

    while (curr)
    {
        if (curr->next && curr->data == curr->next->data)
        { 
            while (curr->next && curr->data == curr->next->data)
            {
                curr = curr->next;
                preC->next = curr->next;
            }
        }
        else
        {
            preC = preC->next;
        }
        curr = curr->next;
    }
    return dummy->next;
}

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(2);
    ListNode *n5 = new ListNode(2);
    ListNode *n6 = new ListNode(3);
    ListNode *n7 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    ListNode *head = removeD(n1);
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