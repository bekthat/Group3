#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id, group;
public:
    //set all parameters
    void set(){
        cout << "Please type name: ";
        cin >> name;
        cout << endl << "Please type id: ";
        cin >> id;
        cout << endl << "Please type group: ";
        int temp;
        cin >> temp;
        setGroup(temp);
    }
    //print state of object
    void print() {
        cout << "id: " << id << ", name: " << name << ", group: " << group << endl;
    }
    string getName(){
        return name;
    }
    void setName(string _name){
        name = _name;
    }
    int getId(){
        return id;
    }
    void setId(int _id){
        id = _id;
    }
    int getGroup(){
        return group;
    }
    void setGroup(int _group){
        if(_group < 1) {
           cout << "wrong group number" << endl; 
        }
        else {
        group = _group;
        }
    }
};

class Rectangle {
    int height, width;

    int getArea() {
        return height * width;
    }
};

int main() {
    Student student1;
    student1.set();
    Student student2;
    student2.set();

    student1.print();
    student2.print();
    return 0;
}