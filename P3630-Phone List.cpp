//trie tree

#include <iostream>
using namespace std;
int t,n;
int nodenum;

struct trie_node
{
	bool term;
	trie_node *son[10];
}node[100000];

class Trie
{
private:
	trie_node root;
public:
	Trie()
	{ 
		root = node[0]; 
	}

	bool insert(char *phone)
	{
		int len = strlen(phone);
		trie_node* loc = &root;
		int i;
		for(i = 0; i < len; ++i)
		{
			if(i == len - 1 && loc->son[phone[i] - '0'] != NULL)
				return false;

			if(loc->son[phone[i] - '0'] == NULL)
			{
				loc->son[phone[i] - '0'] = &node[nodenum];
				node[nodenum].term = false;
				memset(node[nodenum].son, NULL, sizeof(node[nodenum].son));
				nodenum++;
			}

			if(loc->son[phone[i] - '0']->term )  //the leaf node's next node'term is true
				return false;

			loc = loc->son[phone[i] - '0'];
		}
		loc->term = true;
		return true;
	}
};

int main(int argc, _TCHAR* argv[])
{
	cin >>t;
	while(t--)
	{
		cin >>n;
		bool flag = true;
		char temp[11];
		Trie trie;
		nodenum = 1;
		for(int i = 0; i < n; ++i)
		{
			cin >>temp;
			if(flag && !trie.insert(temp))   //failed to insert
				flag = false;
		}

		if(flag)
			cout <<"YES" <<endl;
		else
			cout <<"NO" <<endl;
	}
	return 0;
}

