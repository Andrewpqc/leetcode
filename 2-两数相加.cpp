#include <iostream>
#include <cmath>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

// 下面这种解法不够优雅，效率低而且容易产生溢出
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int64_t sum1 = sumList(l1);
        int64_t sum2 = sumList(l2);
        int64_t sum = sum1 + sum2;
        vector<int> result = splitNum(sum);
        if (result.size() == 0) {
            return new ListNode(0);
        }

        ListNode *header = new ListNode(result.at(0));
        ListNode *temp_header = header;
        for (int i = 1; i < result.size(); ++i) {
            ListNode *tmp = new ListNode(result.at(i));
            temp_header->next = tmp;
            temp_header = temp_header->next;
        }
        return header;
    }

    int sumList(ListNode *l) {
        int64_t result = 0;
        int flag = 0;
        while (l) {
            result += int64_t((l->val) * pow(10, flag));
            ++flag;
            l = l->next;
        }
        return result;
    }

    vector<int> splitNum(int64_t num) {
        vector<int> result;
        while (num) {
            result.push_back(num % 10);
            num = num / 10;
        }
        return result;
    }
};


class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *tmp = nullptr;
        ListNode *header, *header2 = new ListNode(0);
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                int sum = l1->val + l2->val+carry;
                tmp = new ListNode(sum % 10);
                carry = sum / 10;
            } else if (l1 != nullptr) {
                int sum = l1->val+carry;
                tmp = new ListNode(sum%10);
                 carry = sum /10;

            } else if(l2 != nullptr){
                int sum = l2->val+carry;
                tmp = new ListNode(sum%10);
                carry = sum /10;
            }

            header->next = tmp;
            header = header->next;
        }

        return header2->next;
    }
};

