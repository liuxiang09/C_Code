#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}*LinkList;

// 倒数第n个结点
ListNode* findNthFromEnd(ListNode* head, int& n) {
    if(!head) return nullptr;
    ListNode* res = findNthFromEnd(head->next, n);
    n--;
    if(n == 0){
        return head;
    }
    return res;
}

int main(){
    LinkList head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // 倒数第n个结点
    int n=1;
    ListNode* res = findNthFromEnd(head, n);
    cout<<res->val<<endl;
    return 0;
}