#include <iostream>
using namespace std;

struct listNode
{
    int value;
    listNode * next;
};
typedef listNode* listPtr;

void addNode(listPtr& ptr,int v)
{
    listNode* newNode = new listNode;
    newNode->value = v;
    newNode->next = ptr;
    ptr = newNode;
}
int countNegativeSignedNumberInList(listPtr head)
{
    if(head == NULL) return 0;
    int count = countNegativeSignedNumberInList(head->next);
    if(head->value < 0)count++;
    return count;
}
int main()
{
    listPtr head = new listNode;
    head->value = 1;
    addNode(head,2);
    addNode(head,-1);
    addNode(head,3);
    addNode(head,-5);
    listNode* tempNode = head;
    while(tempNode != NULL)
    {
        cout << tempNode->value << endl;
        tempNode = tempNode->next;
    }
    cout << "Neg: " << countNegativeSignedNumberInList(head) << endl;
    return 0;
}