#include <unordered_set>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;

        ListNode* next = head;

        while (next != nullptr) {
            if (visited.count(next) > 0) return true;

            visited.insert(next);

            next = next->next;
        }

        return false;
    }
};