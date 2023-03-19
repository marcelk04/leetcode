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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (list1 && list2) {
            ListNode* next = nullptr;

            if (list1->val < list2->val) {
                next = list1;
                list1 = list1->next;
            } else {
                next = list2;
                list2 = list2->next;
            }

            if (head == nullptr) {
                head = next;
                tail = next;
            } else {
                tail->next = next;
                tail = next;
            }
        }

        while (list1) {
            if (head == nullptr) {
                head = list1;
                tail = list1;
            } else {
                tail->next = list1;
                tail = list1;
            }

            list1 = list1->next;
        }

        while (list2) {
            if (head == nullptr) {
                head = list2;
                tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }

            list2 = list2->next;
        }

        return head;
    }
};