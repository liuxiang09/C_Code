#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} *LinkList;

// 反转链表
LinkList reverseList(LinkList head) {
    // 如果链表为空或者只有一个节点，直接返回
    if (!head || !head->next) return head;
    LinkList res = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
}

int main() {
    LinkList head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // 反转链表
    LinkList res = reverseList(head);
    // 输出反转后的链表
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}