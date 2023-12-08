#include <iostream>
using namespace std;

struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
};
typedef treeNode* treePtr;

void addLeftNode(treePtr& tree,int value)
{
    treeNode* newNode = new treeNode;
    newNode->data = value;
    tree->left = newNode;
}
void addRightNode(treePtr& tree,int value)
{
    treeNode* newNode = new treeNode;
    newNode->data = value;
    tree->right = newNode;
}
int maxValue(treePtr root)
{
    if(root == NULL)return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
    int maxNum = root->data;
    if(maxNum < leftMax) maxNum = leftMax;
    if(maxNum < rightMax) maxNum = rightMax;
    return maxNum;
}
int main()
{
    treePtr root = new treeNode;
    root->data = 4;
    addLeftNode(root,3);
    addRightNode(root,6);
    treeNode* tempNode = root->left;
    addLeftNode(tempNode,4);
    addRightNode(tempNode,2);
    tempNode = root->right;
    addLeftNode(tempNode,5);
    addRightNode(tempNode,1);


    cout << "maxNum: " << maxValue(root) << endl;

    return 0;
}