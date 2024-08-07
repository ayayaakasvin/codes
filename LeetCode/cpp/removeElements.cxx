/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = head;
        ListNode* current = result;

        for (; result != nullptr && result->val == val;) {
            result = result->next;
        }

        for (; current != nullptr && current->next != nullptr;)
        {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
            
        }
        
        return result;
    }
};