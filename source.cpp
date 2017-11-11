#include <iostream>
#include <string>
#include <cmath>
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

class Triangle {
    int a, b, c;
public:
    void set(int _a, int _b, int _c){
        if(_a + _b >= _c && _a + _c >= _b && _b + _c >= _a) {
            a = _a;
            b = _b;
            c = _c;
        }
        else {
            cout << "a, b and c are wrong values for triangle";
        }
    }
    float getArea(){
        float p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
void f1(){
    Student student1;
    student1.set();
    Student student2;
    student2.set();

    student1.setGroup(2);
    student1.print();
    student2.print();
}
void f2() {
    Triangle a;
    a.set(3, 4, 5);
    cout << a.getArea() << endl;
}
int main() {
    return 0;
}