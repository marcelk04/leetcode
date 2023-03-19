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
	ListNode *removeElements(ListNode *head, int val)
	{
		ListNode *list = nullptr;
		ListNode *tail = nullptr;

		for (ListNode *node = head; node != nullptr; node = node->next)
		{
			if (node->val == val)
				continue;

			if (list == nullptr)
			{
				list = node;
				tail = node;
			}
			else
			{
				tail->next = node;
				tail = node;
			}
		}

		if (tail)
			tail->next = nullptr;

		return list;
	}
};