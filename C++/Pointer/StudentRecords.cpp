#include <iostream>

using namespace std;

struct listNode
{
    int studentNum;
    int grade;
    listNode* next;
};
typedef listNode* studentCollection;
void addRecord(studentCollection& sc,int stdNum, int grd)
{
    listNode* node = new listNode;
    node->studentNum = stdNum;
    node->grade = grd;
    node->next = sc;
    sc = node;
}
double averageRecord(studentCollection sc)
{
     if(sc == NULL)
        return 0;
    int count  = 0;
    double sum = 0;
    listNode* loopPtr = sc;
    while(loopPtr != NULL)
    {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    return sum / count;
}
int main()
{
    studentCollection sc;
    listNode* node1 = new listNode;
    node1->studentNum = 1001; node1->grade = 78;
    listNode* node2 = new listNode;
    node2->studentNum = 1012; node2->grade = 93;
     listNode* node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    
    cout << "before: " << averageRecord(sc) << endl;
    addRecord(sc,1028,78);
    cout << "after: " << averageRecord(sc) << endl;

    return 0;
}