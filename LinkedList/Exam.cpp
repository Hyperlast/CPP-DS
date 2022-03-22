#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
// 1 2 3 4 5 6 
struct Node
{
    long long data;
    Node* next;
    Node* previous;
    Node(long long data, Node* ptr = nullptr, Node* ptr2 = nullptr)
    {
        this->data = data;
        this->next = ptr;
        this->previous = ptr2;
    }
};

class List
{
protected:
    int size = 0;
    Node* head;
    Node* tail;
    Node* middle = nullptr;
public:

    List()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addNode(long long data)
    {
        Node* temp = new Node(data);
        if (head == tail && head == nullptr)
        {
            head = temp;
            tail = head;
            tail->previous = nullptr;
            middle = head;
        }
        else
        {

            tail->next = temp;
            temp->previous = tail;
            tail = tail->next;
        }
        if ((size / 2) != (size + 1) / 2 && size!=1)
        {
            middle = middle->next;
        }
        this->size++;
    }

    void deleteNode()
    {
        Node* temp;
        if (this->head == this->tail)
        {
            this->head = nullptr;
            this->tail = nullptr;
            this->middle = nullptr;
            this->size--;
            return;
        }
        temp = tail;
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
        
        if ((size / 2) != (size - 1) / 2)
        {
            middle = middle->previous;
        }
        this->size--;
    }

       void CutAndSwap()
    {
        // 1 2m 3 4 5 
        tail->next = head;
        // 1 2m 3 4 5 -> 1 2m 3 4 5 ->...
        head->previous = tail;
        // 1 2m 3 4 5 <-> 1 2m 3 4 5 <->...
        head = middle->next;
        // 3 4 5 1 2m <-> 3 4 5 1 2m<->...
        head->previous = nullptr;
        // 3 4 5 1 2m <-> 3 4 5 1 2m<->...
        Node* temp = middle;
        if (size % 2 != 0 && size != 1)
        {
            middle = tail->previous;
        }
        else
        {
            middle = tail;
        }
        // 3 4m 5 1 2 <-> 3 4m 5 1 2<->...
        tail = temp;
        tail->next = nullptr;
    }

    void printList()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }

    int getListSize()
    {
        return this->size;
    }
};

int main() {

    List list;
    int Number;
    std::cin >> Number;
    std::string Command;
    while (Number > 0)
    {
        std::cin >> Command;
        if (Command == "add")
        {
            long long number;
            std::cin >> number;
            list.addNode(number);
        }
        else
        {
            if (Command == "gun")
            {
                list.deleteNode();
            }
            else
            {
                if (Command == "milen")
                {
                    list.CutAndSwap();   
                }
            }
        }


        --Number;
    }
    std::cout << list.getListSize() << '\n';
    list.printList();
    return 0;
}

