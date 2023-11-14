#include <iostream>
#include <cmath>

using namespace std;

struct student
{
	int grade;
	int studentID;
	string name;
};
int compareGradeFunc(const void* a, const void* b)
{
	student * studentA = (student*)(a);
	student * studentB = (student*)(b);
	return (*studentA).grade - (*studentB).grade;
}
int compareIDFunc(const void* a, const void* b)
{
	student * studentA = (student*)(a);
	student * studentB = (student*)(b);
	return (*studentA).studentID - (*studentB).studentID;
}
int main()
{
	const int ARRAY_SIZE = 10;
	student students[ARRAY_SIZE] =
	{
		 {87, 10001, "Fred"},
		 {28, 10002, "Tom"},
		{100, 10003, "Alistair"},
		{78, 10004, "Sasha"},
		{84, 10005, "Erin"},
		{98, 10006, "Belinda"},
		{75, 10007, "Leslie"},
		{70, 10008, "Candy"},
		{81, 10009, "Aretha"},
		{68, 10010, "Veronica"}
	};
	qsort(students,ARRAY_SIZE,sizeof(student),compareIDFunc);

	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "Grade: " << students[i].grade << " ID: " << students[i].studentID << " Name: " << students[i].name << "\n";
	}
    return 0;
}
