#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *veryhead = new ListNode(0);
    veryhead->next = head;
    ListNode *start = veryhead;
    while(m>1)
    {
        start=start->next;
        m--;
    }    
    ListNode *end = veryhead;
    while(n>0)
    {
        end=end->next;
        n--;
    }
    while(start->next!=end)
    {
        ListNode *temp=start->next;
        start->next=start->next->next;
        temp->next=end->next;
        end->next=temp;
    }
    return veryhead->next;
}
ListNode *reverseKGroup(ListNode *head, int k) {
    if(head==NULL) return NULL;
    ListNode *end=head;
    int length=1;
    while(end->next!=NULL)
    {
        length++;
        end=end->next;
    }
    int nk=length/k;
    int s=1;
    while(nk>0)
    {
        head=reverseBetween(head,s,s+k-1);
        s+=k;
        nk--;
    }
    return head;        
}
ListNode *swapPairs(ListNode *head) {
    return reverseKGroup(head,2);
}
main()
{
    ListNode *start = new ListNode(1);
    ListNode *t = start;
    for(int i=2;i<3;i++)
    {
        ListNode *temp = new ListNode(i);
        t->next = temp;
        t = t->next;
    }
    start = reverseKGroup(start,2);
    while(start!=NULL)
    {
        cout<<start->val<<endl;
        start = start->next;
    }
    system("pause");    
        
}    
