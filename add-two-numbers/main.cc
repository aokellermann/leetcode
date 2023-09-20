#include <vector>
#include <unordered_map>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        int carry = 0;
        while (true) {
            if (!l1 && !l2) break;
            int sum = carry;
            carry = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry += sum / 10;
            sum %= 10;
            auto t = new ListNode(sum);
            if (!head && !cur) {
                head = t;
                cur = t;
            } else {
                cur->next = t;
                cur = t;
            }
        }
        if (carry) {
            cur->next = new ListNode(carry);
        }
        if (!head) {
            head = new ListNode(0);
        }
        return head;
    }
};