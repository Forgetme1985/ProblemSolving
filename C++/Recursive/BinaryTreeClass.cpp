#include <iostream>
using namespace std;



class binaryTree
{
    public:
    int countLeaves()
    {
        return countLeaves(_root);
    }
    
    binaryTree(int value)
    {
        _root = new binaryTreeNode;
        _root->data = value;
    }
    ~binaryTree()
    {
        delete _root;
    }
    void addNodeLeft(int value)
    {
        binaryTreeNode* newNode = new binaryTreeNode;
        newNode->data = value;
        _root->left = newNode;
    }
    void addNodeRight(int value)
    {
        binaryTreeNode* newNode = new binaryTreeNode;
        newNode->data = value;
        _root->right = newNode;
    }
   
    private:
        struct binaryTreeNode{
            int data;
            binaryTreeNode* left;
            binaryTreeNode* right;
        };
        typedef binaryTreeNode* treePtr;
        treePtr _root;
        int countLeaves(treePtr rootPtr)
        {
            if(rootPtr == NULL)
            {
                return 0;
            }
            if(rootPtr->left == NULL && rootPtr->right == NULL)
            return 1;
            int leftCount = countLeaves(rootPtr->left);
            int rightCount = countLeaves(rootPtr->right);
            return leftCount + rightCount;
        }

};



int main()
{
    binaryTree tree(2);
    tree.addNodeLeft(3);
    tree.addNodeRight(4);
    
    cout << tree.countLeaves() << endl;

    return 0;
}