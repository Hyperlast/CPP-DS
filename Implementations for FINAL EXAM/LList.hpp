#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Node
{
	int data;
	Node* next;
	Node(int data = 0, Node* next = nullptr) :data(data), next(next)	{}
};

class List
{
private:
	Node* head;
	Node* tail;
public:
	List()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void push_back(const int& data)
	{
		if (head == nullptr)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
		}
	}

	void push_front(const int& data)
	{
		Node* tempNode = new Node(data, head);
		head = tempNode;
		if (tail == nullptr)
		{
			tail = head;
		}
	}

	void printF()const
	{
		Node* it = head;
		while (it)
		{
			std::cout << it->data<<" ";
			it = it->next;
		}
		std::cout << '\n';
	}

	void insert(const int& number, const int& position)
	{
		if (position == 0)
		{
			push_front(number);
			return;
		}
		else if (head == nullptr)
		{
			throw std::out_of_range("List is empty try pushfront");
		}

		Node* current = head;
		Node* previous = nullptr;
		for (int i = 0; i < position; ++i)
		{
			if (current != nullptr)
			{
				previous = current;
				current = current->next;
			}
			else
			{
				throw std::out_of_range("Position invalid: List size too small");
			}
		}

		if (previous != nullptr)
		{
			previous->next = new Node(number, current);

			if (tail == previous)
			{
				tail = previous->next;
			}
		}
	}

	void pop_front()
	{
		Node* temp;
		temp = head;
		if (head != nullptr)
		{
			if (head == tail)
			{
				tail = nullptr;
			}

			head = head->next;
			delete temp;
		}
		else
		{
			throw std::out_of_range("List empty or integrity damaged");
		}
	}

	void pop_back()
	{
		Node* temp;
		temp = tail;
		Node* current = head;
		if (head == nullptr)
		{
			throw std::out_of_range("List empty or integrity damaged");
		}
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
			delete temp;
			delete current;
			return;
		}
		
		while (current->next != temp)
		{
			current = current->next;
		}
		
		tail = current;
		current->next = nullptr;
		delete temp;
	}
	
	void pop_at(const int& position)
	{
		if (position == 0)
		{
			pop_front();
			return;
		}
		else if (head == nullptr)
		{
			throw std::out_of_range("List empty or integrity damaged");
		}

		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; i < position; ++i)
		{
			if (current->next != nullptr)
			{
				previous = current;
				current = current->next;
			}
			else
			{
				throw std::out_of_range("Position invalid List is too short");
			}
		}

		if (previous != nullptr)
		{
			previous->next = current->next;
			if (current == tail)
			{
				tail = previous;
			}
			delete current;
		}
	}

	bool search(const int& x)const
	{
		Node* iter = head;
		while (iter)
		{
			if (iter->data == x)
			{
				return true;
			}
			iter = iter->next;
		}

		return false;
	}


	List operator+(List& rhs)
	{
		this->tail->next = rhs.head;
		this->tail = rhs.tail;
		return *this;
	}

};