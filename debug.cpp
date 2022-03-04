/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>
#include <regex>

#include "LeetCode_Helper_Func.h"

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
    ListNode *reverseList(ListNode *head) {
        ListNode *left = nullptr;
        while (head != nullptr) {
            ListNode *next = head->next;
            head->next = left;
            left = head;
            head = next;
        }
        return left;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *prev = dummyNode;
        bool flag = true;
        while (flag) {
            ListNode *ptr = prev;
            for (int i = 0; i < k; ++i) {
                if (ptr->next == nullptr) {
                    flag = false;
                    break;
                }
                ptr = ptr->next;
            }
            if (flag) {
                ListNode *next = ptr->next;
                ptr->next = nullptr;
                prev->next = reverseList(prev->next);
                while(prev->next != nullptr) {
                    prev = prev->next;
                }
                prev->next = next;
            }
        }
        return dummyNode->next;
    }
};

int main()
{
    // string input = "input.txt";
    // ifstream fin(input);
    // vector<vector<int>> vec = to_vvi(fin);
    Solution solution;
    ListNode one(1);
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    ListNode five(5);
    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = nullptr;
    ListNode *ans = solution.reverseKGroup(&one, 3);
    return 0;
}
