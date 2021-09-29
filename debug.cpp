/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <limits.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummyNode = new ListNode();
        ListNode* ptr = dummyNode;
        while(head1 && head2){
            if(head1->val <= head2->val){
                ptr->next = head1;
                head1 = head1->next;
            }else{
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        if(head1 != nullptr){
            ptr->next = head1;
        }else if(head2 != nullptr){
            ptr->next = head2;
        }
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head)
    {
        if(head == nullptr){
            return nullptr;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* last = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(last);
        return merge(left, right);
    }
};

int main()
{
    ListNode* a = new ListNode(4);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    ListNode* d = new ListNode(3);
    a->next = b; b->next = c; c->next = d; d->next = nullptr;
    Solution solution;
    ListNode* ret = solution.sortList(a);
    return 0;
}