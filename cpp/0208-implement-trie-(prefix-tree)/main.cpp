#include <string>
#include <iostream>
#include <vector>
#include <memory>

class TrieNode
{
public:
	TrieNode() : children(26, nullptr), isTerminal(false)
	{
	}

	std::shared_ptr<TrieNode> &nodeAtChar(char c)
	{
		return children[c - 'a'];
	}

public:
	std::vector<std::shared_ptr<TrieNode>> children;
	bool isTerminal;
};

class Trie
{
public:
	Trie()
	{
		root = std::make_shared<TrieNode>();
	}

	void insert(std::string word)
	{
		insert(word, root);
	}

	bool search(std::string word)
	{
		return search(word, root);
	}

	bool startsWith(std::string prefix)
	{
		return startsWith(prefix, root);
	}

private:
	void insert(const std::string &word, std::shared_ptr<TrieNode> &node)
	{
		char c = word[0];
		auto &nextNode = node->nodeAtChar(c);

		if (nextNode == nullptr)
		{
			nextNode = std::make_shared<TrieNode>();
		}

		if (word.length() == 1)
		{
			nextNode->isTerminal = true;
		}
		else
		{
			insert(word.substr(1), nextNode);
		}
	}

	bool search(const std::string &word, std::shared_ptr<TrieNode> &node)
	{
		char c = word[0];
		auto &nextNode = node->nodeAtChar(c);

		if (nextNode == nullptr)
			return false;

		if (word.length() == 1)
		{
			return nextNode->isTerminal;
		}
		else
		{
			return search(word.substr(1), nextNode);
		}
	}

	bool startsWith(const std::string &word, std::shared_ptr<TrieNode> &node)
	{
		char c = word[0];
		auto &nextNode = node->nodeAtChar(c);

		if (nextNode == nullptr)
			return false;

		if (word.length() == 1)
		{
			return true;
		}
		else
		{
			return startsWith(word.substr(1), nextNode);
		}
	}

private:
	std::shared_ptr<TrieNode> root;
};

int main()
{
	Trie trie;

	trie.insert("apple");
	std::cout << trie.search("apple") << '\n';	 // return True
	std::cout << trie.search("app") << '\n';	 // return False
	std::cout << trie.startsWith("app") << '\n'; // return True
	trie.insert("app");
	std::cout << trie.search("app") << '\n'; // return True
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */