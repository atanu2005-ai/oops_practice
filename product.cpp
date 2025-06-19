#include <iostream>
using namespace std;

class shop{
    int counter;
    string itemname[50];
    int itemid[50];
    int itemprice[50];
    public:
    void setcounter() {counter = 0;} 
    void getname();
    void getid();
    void getprice();
    void display();
};
void shop::getname() {
    cout << "Enter the name of the item number " << counter + 1 << ": ";
    cin >> itemname[counter];
}
void shop::getid() {
    cout << "Enter the ID of the item: ";
    cin >> itemid[counter];
}
void shop::getprice() {
    cout << "Enter the price of the item: ";
    cin >> itemprice[counter];
    counter++;
}
void shop::display() {
    cout << "Items in the shop:" << endl;
    for (int i = 0; i < counter; i++) {
        cout << "Item Name: " << itemname[i] << endl << "ID: " << itemid[i] << endl << "Price: " << itemprice[i] << " Rupees " << endl << "_____________________________" << endl;
    }
}
int main() {
    shop product;
    int n;
    cout << "Enter the number of items in the shop: ";
    cin >> n;
    product.setcounter();
    for(int i=0; i < n; i++) {
        product.getname();
        product.getid();
        product.getprice();
    }
    product.display();
    cout << "Thank you for using the shop management system!" << endl;

    return 0;
}