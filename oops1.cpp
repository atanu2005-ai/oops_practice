#include <iostream>
using namespace std;

class student {
        private:
        int rank, marks, division;
        public:
        int roll;
        string name;

        void setdata(int a1, int b1, int c1);
        void getdata(){
            cout << "Name: " << name << endl;
            cout << "Roll: " << roll << endl;
            cout << "Division: " << division << endl;
            cout << "Rank: " << rank << endl;
            cout << "Marks: " << marks << endl;
        };
    };
     void student::setdata(int a1, int b1, int c1){
            rank = a1;
            marks = b1;
            division = c1;
        };

int main() {
    student Atanu;
    Atanu.name = "Atanu Debnath";
    Atanu.roll = 37;
    Atanu.setdata(1, 95, 1);
    Atanu.getdata();

    return 0;
}