#include <vector>
#include <queue>

class Solution
{
public:
	int minScore(int n, std::vector<std::vector<int>> &roads)
	{
		int ans = INT_MAX;

		std::vector<std::vector<std::pair<int, int>>> gr(n + 1);

		for (auto edge : roads)
		{
			gr[edge[0]].push_back({edge[1], edge[2]}); // u-> {v, dis}
			gr[edge[1]].push_back({edge[0], edge[2]}); // v-> {u, dis}
		}

		std::vector<int> vis(n + 1, 0);
		std::queue<int> q;

		q.push(1);
		vis[1] = 1;

		while (!q.empty())
		{
			auto node = q.front();
			q.pop();

			for (auto &[v, dis] : gr[node])
			{
				ans = std::min(ans, dis);
				if (vis[v] == 0)
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}

		return ans;
	}
};