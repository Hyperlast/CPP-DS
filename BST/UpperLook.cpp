#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

/*

       11
       0- 1 2
       1- 3 4
       2- 5 6
       3- -1 7
       4- -1 -1
       5- -1 -1
       6- -1 -1
       7- 8 -1
       8- 9 -1
       9- 10 -1
       10- -1 -1

       5
       0 1 2
       1 -1 3
       2 -1 -1
       3 -1 4
       4 -1 -1

 */


struct Node
{
    int data;
    Node* left;
    Node* right;
    int first;
    int second;
    Node(int data,int Coord1,int Coord2, Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
        this->first = Coord1;
        this->second = Coord2;
    }

};

class tree
{
    Node* root;
    int left;
    int right;
    std::vector<Node*> resultvec;
    
public:
    tree()
    {
        root = new Node(0,0,0, nullptr, nullptr);
        resultvec.push_back(root);
        this->left = 0;
        this->right = 0;
    }

    void insertEls()
    {
        std::queue<Node*> q;
        q.push(root);
        int Loop;
        std::cin >> Loop;
        int leftMax;
        int rightMax;
        while (Loop > 0)
        {
           
            std::cin >> leftMax;
            std::cin >> rightMax;
           
            if (leftMax != -1)
            {
                Node* leftNode = new Node(leftMax, q.front()->first - 1, q.front()->second - 1, nullptr, nullptr);
                q.front()->left = leftNode;
                q.push(leftNode);
            }
            
            if (rightMax != -1)
            {
                Node* rightNode = new Node(rightMax, q.front()->first - 1, q.front()->second + 1, nullptr, nullptr);
                q.front()->right = rightNode;
                q.push(rightNode);
            }

            q.pop();
            Loop--;
        }
    }

    void LevelTree()
    {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            if (this->left > q.front()->second)
            {
               // std::cout << q.front()->data << " ";
                this->left = q.front()->second;
                resultvec.push_back(q.front());
            }
            if (this->right < q.front()->second)
            {
               // std::cout << q.front()->data << " ";
                this->right = q.front()->second;
                resultvec.push_back(q.front());
            }
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
       
       
    }

    Node* getRoot()const
    {
        return this->root;
    }

    std::vector<Node*> getResult()const
    {
        return this->resultvec;
    }

};

bool Comparator(Node* lhs, Node* rhs)
{
    if (lhs->second > rhs->second)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main() {

    tree tree;
    tree.insertEls();
    tree.LevelTree();
    std::vector<Node*> Result = tree.getResult();
    std::sort(Result.begin(), Result.end(), Comparator);
    const int size = Result.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << Result[i]->data<<" ";
    }
    return 0;
}