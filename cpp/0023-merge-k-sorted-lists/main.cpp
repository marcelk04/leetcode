#include <vector>
#include <memory>
#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *mergeKLists(std::vector<ListNode *> &lists)
	{
		ListNode *res{nullptr};
		ListNode *end{nullptr};

		while (!lists.empty())
		{
			int smallest = 0;
			int smallestIdx = -1;

			for (size_t i = 0; i < lists.size(); i++)
			{
				if (lists[i] == nullptr)
					continue;

				if (lists[i]->val < smallest || smallestIdx == -1)
				{
					smallest = lists[i]->val;
					smallestIdx = i;
				}
			}

			if (smallestIdx == -1)
				break;

			if (end == nullptr)
			{
				res = lists[smallestIdx];
				end = lists[smallestIdx];
			}
			else
			{
				end->next = lists[smallestIdx];
				end = end->next;
			}

			if (lists[smallestIdx] == nullptr)
			{
				lists.erase(lists.begin() + smallestIdx);
			}
			else
			{
				lists[smallestIdx] = lists[smallestIdx]->next;
			}
		}

		return res;
	}
};

void print(ListNode *list)
{
	ListNode *ptr = list;

	while (ptr)
	{
		std::cout << ptr->val << ' ';
		ptr = ptr->next;
	}

	std::cout << '\n';
}

int main()
{
	Solution s;

	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(4);
	ListNode *l3 = new ListNode(5);
	ListNode *l4 = new ListNode(1);
	ListNode *l5 = new ListNode(3);
	ListNode *l6 = new ListNode(4);
	ListNode *l7 = new ListNode(2);
	ListNode *l8 = new ListNode(6);

	l1->next = l2;
	l2->next = l3;

	l4->next = l5;
	l5->next = l6;

	l7->next = l8;

	std::vector<ListNode *> list1 = {l1, l4, l7};
	std::vector<ListNode *> list2 = {};
	std::vector<ListNode *> list3 = {nullptr};

	print(s.mergeKLists(list1));
	print(s.mergeKLists(list2));
	print(s.mergeKLists(list3));

	delete (l1);
	delete (l2);
	delete (l3);
	delete (l4);
	delete (l5);
	delete (l6);
	delete (l7);
	delete (l8);
}