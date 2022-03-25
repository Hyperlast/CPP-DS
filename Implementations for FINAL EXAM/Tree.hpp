#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct NodeTree
{
	int data;
	NodeTree* LeftChild;
	NodeTree* RightChild;
	NodeTree(const int& data = 0, NodeTree* left = nullptr, NodeTree* right = nullptr) : data(data), LeftChild(left), RightChild(right)
	{}
	NodeTree* insertNode(const int& data, NodeTree* current)
	{
		if (current == nullptr)
		{
			return new NodeTree(data);
		}

		if (data > current->data)
		{
			current->RightChild = insertNode(data, current->RightChild);
		}

		else if (data < current->data)
		{
			current->LeftChild = insertNode(data, current->LeftChild);
		}
		return current;
	}
};

NodeTree* ReturnMinNodeTree(NodeTree* Node)
{
	NodeTree* current = Node;
	while (current && current->LeftChild)
	{
		current = current->LeftChild;
	}
	return current;
}

class Tree
{
public:
	NodeTree* root;
	NodeTree* deleteNodeTree(NodeTree* current, int data)
	{
		if (current == NULL)
		{
			return current;
		}

		if (data < current->data)
		{
			current->LeftChild = deleteNodeTree(current->LeftChild, data);
		}
		else if (data > current->data)
		{
			current->RightChild = deleteNodeTree(current->RightChild, data);
		}
		else
		{
			if (current->LeftChild == NULL && current->RightChild == NULL)
			{
				return NULL;
			}

			else if (current->LeftChild == NULL)
			{
				NodeTree* temp = current->RightChild;
				free(current);
				return temp;
			}

			else if (current->RightChild == NULL)
			{
				NodeTree* temp = current->LeftChild;
				free(current);
				return temp;
			}

			NodeTree* minNodeTree = ReturnMinNodeTree(current->RightChild);
			current->data = minNodeTree->data;
			current->RightChild = deleteNodeTree(current->RightChild, minNodeTree->data);
		}
		return current;
	}

	bool findNumber(NodeTree* curr,int num)
	{
		if (curr == NULL)
		{
			return false;
		}
		if (curr->data == num)
		{
			return true;
		}

		if (curr->data > num)
		{
			findNumber(curr->LeftChild, num);
		}

		if (curr->data < num)
		{
			findNumber(curr->RightChild, num);
		}
	}

	void printInorder(NodeTree* current)
	{
		if (current)
		{
			printInorder(current->LeftChild);
			std::cout << current->data<<" ";
			printInorder(current->RightChild);
		}
	}
};