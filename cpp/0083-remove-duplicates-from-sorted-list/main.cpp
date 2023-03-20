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
class Solution
{
public:
	void deleteDuplicatesR(ListNode *node)
	{
		if (node == nullptr || node->next == nullptr)
			return;

		if (node->val == node->next->val)
		{
			node->next = node->next->next;
			deleteDuplicatesR(node);
		}
		else
		{
			deleteDuplicatesR(node->next);
		}
	}

	ListNode *deleteDuplicates(ListNode *head)
	{
		deleteDuplicatesR(head);
		return head;
	}
};