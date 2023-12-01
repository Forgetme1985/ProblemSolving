#include <iostream>
using namespace std;
class studentRecord
{
    public:
        studentRecord(int newGrade,int newStudentID, string newName)
        {
            setGrade(newGrade);
            setStudentID(newStudentID);
            setName(newName);
        }
        studentRecord()
        {
            setGrade(0);
            setStudentID(0);
            setName("");
        }
        int grade()
        {
            return _grade;
        }
        void setGrade(int newGrade)
        {
            if(isValidGrade(newGrade))
                _grade = newGrade;
        }
        string name()
        {
            return _name;
        }
        void setName(string newName)
        {
            _name = newName;
        }
        int studentID()
        {
            return _studentID;
        }
        void setStudentID(int newStudentID)
        {
            _studentID = newStudentID;
        }
        string letterGrade()
        {
            const int NUMBER_CATEGORIES = 11;
            const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
            const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
            int category = 0;
            while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
                category++;
            return GRADE_LETTER[category - 1];
        }
        bool isValidGrade(int grade)
        {
            if ((grade >= 0) && (grade <= 100))
                return true;
            else
                return false;
        }
    private:
        int _grade;
        int _studentID;
        string _name;
};

class studentCollection
{
    private:
        struct studentNode
        {
            studentRecord studentData;
            studentNode* next;
        };
        
    public:
        studentCollection()
        {
            
            _listHead = NULL;
        }
        studentCollection(const studentCollection& original)
        {
            _listHead = copyList(original._listHead);
        }
        ~studentCollection()
        {
            deleteList(_listHead);
        }
        void addRecord(studentRecord newStudent)
        {
           studentNode* newNode = new studentNode;
           newNode->studentData = newStudent;
           newNode->next = _listHead;
           _listHead = newNode;
           
        }
        void removeRecord(int idNum)
        {
            studentNode* loopPtr = _listHead;
            studentNode* trailing = NULL; 
            while(loopPtr != NULL && loopPtr->studentData.studentID() != idNum)
            {
                trailing = loopPtr;
                loopPtr = loopPtr->next;
            }
            if(loopPtr == NULL)return;
            if(trailing == NULL)
            {
                _listHead = _listHead->next;
            }
            else{
                trailing->next = loopPtr->next;
            }
            trailing->next = loopPtr->next;
            delete loopPtr;
        }
         studentRecord recordWithNumber(int idNum)
        {
           studentNode* loopPtr = _listHead;
           while(loopPtr->studentData.studentID() != idNum)
           {
                loopPtr = loopPtr->next;
           }

           if (loopPtr == NULL) {
                studentRecord dummyRecord(-1, -1, "");
                return dummyRecord;
            } else {
                return loopPtr->studentData;
            }
        }
        studentCollection& operator=(const studentCollection& rhs)
        {
            if(this != &rhs)
            {
                delete(_listHead);
                _listHead = copyList(rhs._listHead);
            }
            return *this;
        }
    private:
    typedef studentNode* studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr)
    {
        while(listPtr != NULL)
        {
            studentNode* node = listPtr;
            listPtr = listPtr->next;
            delete node;

        }
    }
    studentList copyList(const studentList original)
    {
        if(original == NULL)
        {
            return NULL;
        }
        studentList newList = new studentNode;
        newList->studentData = original->studentData;

        studentNode * oldLoopPtr = original->next;
        studentNode * newLoopPtr = newList;
        while (oldLoopPtr != NULL) {
            newLoopPtr->next = new studentNode;
            newLoopPtr = newLoopPtr->next;
            newLoopPtr->studentData = oldLoopPtr->studentData;
            oldLoopPtr = oldLoopPtr->next;
        }
        newLoopPtr->next = NULL;
        return newList;
    }
};
int main()
{
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    studentCollection s2 = s;  
    s.removeRecord(4875);
    cout << s2.recordWithNumber(4875).name() << endl;
    return 0;
}