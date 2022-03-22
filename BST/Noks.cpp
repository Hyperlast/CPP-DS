#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>

struct Node
{
    int data;
    Node* left;
    Node* right;
    
    Node(int data , Node* left = nullptr, Node* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

};

class tree
{
    Node* root=NULL;
    std::vector<int> resultvec;
    


    Node* insert(Node* curr,int& num)
    {
        if (!curr)
        {
            return  new Node(num);
        }

        if (num < curr->data)
        {
            curr->left = insert(curr->left, num);
        }
        else if(num>curr->data)
        {
            curr->right = insert(curr->right, num);
        }
        return curr;
    }
public:
    void insertEls(int& Loop)
    {
        int num;
        std::cin >> num;
        this->root = new Node(num);
        Loop--;
        while (Loop > 0)
        {
            std::cin >> num;
            this->root = insert(this->root, num);
            Loop--;
        }
    }

    void LevelTree(Node* curr)
    {
        if(!curr)
        {
            return;
        }
     
        LevelTree(curr->left);
        if (curr)
        {
            resultvec.push_back(curr->data);
        }
        LevelTree(curr->right);
    }

    Node* DeleteNode(Node* curr,int& num)
    {
        if (!curr)
        {
            return curr;
        }

        if(num<curr->data)
        {
            curr->left = DeleteNode(curr->left, num);
        }
        else if (num > curr->data)
        {
            curr->right = DeleteNode(curr->right, num);
        }
        else
        {
            // case 1 -> no children
            // case 2-> 1 child
            // case 3 -> 2 children 
            if (!curr->left && !curr->right)
            {
                delete curr;
                curr = NULL;
                return curr;
            }
            else if (!curr->right)
            {
                Node* tempNode = curr;
                curr = curr->right;
                delete tempNode;
                return curr;
            }
            else if (!curr->left)
            {
                Node* tempNode = curr;
                curr = curr->left;
                delete tempNode;
                return curr;
            }
            else
            {
                Node* temp = findMinEl(curr->right);
                curr->data = temp->data;
                curr->right = DeleteNode(curr->right, temp->data);
            }
        }
        return curr;
    }

    Node* findMinEl(Node* curr)
    {
        Node* temp = curr;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp;
    }


    void PrintLevelTree()
    {

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            std::cout << q.front()->data<<" ";
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

    std::vector<int> getResult()const
    {
        return this->resultvec;
    }

};




int main() {

    int Loop;
    std::cin >> Loop;
    int NumBig;
    std::cin >> NumBig;
    tree tree;
    tree.insertEls(Loop);
    tree.LevelTree(tree.getRoot());
    NumBig--;
    int tempData = tree.getResult()[(tree.getResult().size() - 1) - NumBig];
    tree.DeleteNode(tree.getRoot(), tempData);
    tree.PrintLevelTree();
    return 0;
}