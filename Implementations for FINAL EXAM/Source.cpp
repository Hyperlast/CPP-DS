#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include "LList.hpp"
#include "Tree.hpp"
//#include "Binary.hpp"
#include <unordered_map>

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	//BINARY_SEARCH
	std::vector<int> beg;
	beg.push_back(1);
	beg.push_back(3);
	beg.push_back(4);
	beg.push_back(10);
	beg.push_back(15);

	//std::cout<<binary_searchIT(beg, 3);

	auto it = std::lower_bound(beg.begin(), beg.end(), 3);
	int Index = it - beg.begin();
	std::cout << "\n" << Index;

	//LIST
	List list;
	list.push_back(1);
	list.push_back(33);
	list.push_back(4);
	list.push_back(10);
	list.pop_front();
	list.pop_back();
	List list2;
	list2.push_front(1);
	list2.push_front(2);
	list2.push_front(3);
	list2.insert(7, 1);
	list.push_back(10);
	list.pop_at(2);
	list + list2;
	list.printF();


	//Tree
	Tree tree;
	tree.root = new NodeTree(5);
	tree.root->insertNode(3,tree.root);
	tree.root->insertNode(1, tree.root);
	tree.root->insertNode(9, tree.root);
	tree.root->insertNode(13, tree.root);
	tree.root->insertNode(7, tree.root);
	tree.printInorder(tree.root);
	tree.deleteNodeTree(tree.root, 5);
	std::cout << '\n';
	tree.printInorder(tree.root);

	int temp;
	std::cin >> temp;
	std::unordered_map<long long, long long> map;
	map[temp]++;
	std::cin >> temp;
	map[temp]++;
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->second;
	}
	return 0;
}

