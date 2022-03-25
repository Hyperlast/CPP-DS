#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr && tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }


    void reverse(int from, int to) {
        std::vector<int> arr;
        Node* temp = head;
        for (int i = 0; i < from-1; ++i)
        {
            if (temp)
            {
                temp = temp->next;
            }
        }
        Node* Second = temp;
        int boot = abs(to - from);
        for (int i = 0; i <= boot; ++i)
        {
            if (temp)
            {
                arr.push_back(temp->data);
                temp = temp->next;
            }
        }

        for (int i = 0; i <= boot; ++i)
        {
            if (Second)
            {
                Second->data = arr[arr.size()-1-i];
                Second = Second->next;
            }
        }

        // TODO: Reverse the elements of the sublist starting 
        //       at postiton from and ending at posion to.
    }

    void print() {
        Node* temp = head;

        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << std::endl;
    }

    ~List() {
        Node* curr = head;

        while (curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }

        delete curr;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    List testList;

    int queries;
    std::cin >> queries;

    for (int t = 0; t < queries; t++) {

        std::string op;
        std::cin >> op;

        if (op == "add") {
            int num;
            std::cin >> num;
            testList.add(num);
        }

        if (op == "print") {
            testList.print();
        }

        if (op == "reverse") {
            int from, to;
            std::cin >> from >> to;
            testList.reverse(from, to);
        }
    }

    return 0;
}