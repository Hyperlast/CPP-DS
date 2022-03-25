#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printLeftProfile() {
           queue<pair<Node*,int>> q;
        q.push({ root,0 });
        int leveltoprint=0;
        while (!q.empty())
        {
            std::pair<Node*, int> front;
            front = q.front();
            if (front.first->left)
            {
                q.push({ front.first->left,front. second+1 });
            }
            if (front.first->right)
            {
                q.push({ front.first->right,front.second+1 });
            }
            
            if (q.front().second == leveltoprint)
            {
                cout << q.front().first->value << " ";
                leveltoprint++;
            }
            q.pop();
        }

      //TODO: implement this function
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.printLeftProfile();
    return 0;
}