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
	int getDecimalValue(ListNode *head)
	{
		int res = 0;

		for (ListNode *node = head; node != nullptr; node = node->next)
		{
			res = res * 2 + node->val;
		}

		return res;
	}
};