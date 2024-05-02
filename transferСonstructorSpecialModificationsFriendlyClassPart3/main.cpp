#include <iostream>
#include <vector>
using namespace std;

//Створіть клас для представлення документа та клас для його керування (створення, редагування, збереження). Використовуйте friend class, щоб дозволити класу керування документами отримати доступ до внутрішніх структур документа.

class AddValue;

class Data
{
private:
    vector<int> data;
    
public:
    friend class AddValue;
    
    
};

class AddValue
{
public:
    void addData(Data& value, int val)
    {
        value.data.emplace_back(val);
    }
    
    void setData(Data& value, int index, int val)
    {
        value.data[index] = val;
    }
 
    void print(Data& value)
    {
        for (int i = 0 ; i < value.data.size(); i++)
        {
            cout<<value.data[i]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    Data data;
    AddValue add;
    add.addData(data, 2);
    add.addData(data, 3);
    add.print(data);
    add.setData(data, 0, 1);
    add.print(data);
    
}
