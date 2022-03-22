//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

    
    void OrderTree(Node* curr,long long& sum)
    {
        if(!curr)
        {
            return;
        }
        
        if(curr && !curr->leftNode && !curr->rightNode)
        {
            if (curr->data%2!=0)
            {
                sum += curr->data;
            }
        }
        OrderTree(curr->leftNode,sum);
        OrderTree(curr->rightNode,sum);
        
    }
    
	void leaves(Node *root) {
        long long sum=0;
        OrderTree(root,sum);
		
        std::cout<<sum;
       
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leaves(root);
    return 0;
}