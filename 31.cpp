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

// void addLists(ListNode *node1, ListNode *a1)
// {
//     ListNode *n1 = node1;
//     ListNode *n2 = a1;
//     string s1 = "";
//     string s2 = "";

//     while (n1)
//     {
//         s1 += to_string(n1->data);
//         n1 = n1->next;
//     }
//     // reverse(s1.begin() , s1.end());
//     while (n2)
//     {
//         s2 += to_string(n2->data);
//         n2 = n2->next;
//     }
//     // reverse(s2.begin() , s2.end());

//     int num = stoi(s1) + stoi(s2);
//     string strNum = to_string(num);

//     ListNode *head = new ListNode(strNum[0] - '0');
//     ListNode *curr = head;

//     for (int i = 1; i < strNum.size(); i++)
//     {
//         curr->next = new ListNode(strNum[i] - '0');
//         curr = curr->next;
//     }

//     curr = head;
//     while (curr)
//     {
//         cout << curr->data;
//         if (curr->next)
//         {
//             cout << "->";
//         }
//         curr = curr->next;
//     }
//     cout << endl;
// }

ListNode* addLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = carry;

        if (l1)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->data;
            l2 = l2->next;  
        }

        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);
        curr = curr->next;
    }
    return head->next;
}

int main()
{
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;

    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(1);

    a1->next = a2;
    a2->next = a3;

    ListNode *newLL = addLists(node1, a1);

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