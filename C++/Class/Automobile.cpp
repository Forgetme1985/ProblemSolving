#include <iostream>
using namespace std;

class automobile{
    public:
        automobile(int modelYear,string manufactureName,string modelName)
        {
            setModelName(modelName);
            setManufactureName(manufactureName);
            setModelYear(modelYear);
        }
        void setManufactureName(string newName)
        {
            _manufactureName = newName;
        }
        void setModelName(string newName)
        {
            _modelName = newName;
        }
        void setModelYear(int newYear)
        {
            _modelYear = newYear;
        }

        string getManufactureName()
        {
            return _manufactureName;
        }
        string getModelName()
        {
            return _modelName;
        }
        int getModelYear()
        {
            return _modelYear;
        }
        string getDescription()
        {
            return to_string(getModelYear()) + " " + getManufactureName() + " " + getModelName();
        }
        int getAge()
        {
            return (2023 - getModelYear());
        }
    private:
        string _manufactureName;
        string _modelName;
        int _modelYear;

};
int main()
{
    automobile a(1957,"Chevrolet","Impala");
    cout << "Description: " << a.getDescription() << endl;
    cout << "Age: " << a.getAge() << endl;
    return 0;
}