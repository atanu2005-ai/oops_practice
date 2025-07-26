#include <iostream>
using namespace std;

class shop
{
    int counter;
    string itemname[50];
    int itemid[50];
    int itemprice[50];

public:
    void setcounter() { counter = 0; }
    void getname();
    void getid();
    void getprice();
    void searchid(int id);
    void display();
};
void shop::getname(){
    cout << "Enter the name of the item number " << counter + 1 << ": ";
    cin >> itemname[counter];
}
void shop::getid(){
    cout << "Enter the ID of the item: ";
    cin >> itemid[counter];
}
void shop::getprice(){
    cout << "Enter the price of the item: ";
    cin >> itemprice[counter];
    counter++;
}
void shop::display(){
    cout << "\n========= Shop Inventory =========\n";
    for (int i = 0; i < counter; i++){
        cout << "Item #" << i + 1 << endl;
        cout << "Name  : " << itemname[i] << endl;
        cout << "ID    : " << itemid[i] << endl;
        cout << "Price : " << itemprice[i] << " Rupees" << endl;
        cout << "------------------------------" << endl;
    }
}
void shop::searchid(int id){
    bool found = false;
    for (int i = 0; i < counter; i++){
        if (itemid[i] == id){
            cout << "Item found with ID " << id << " !" << endl;
            cout << "Item name: " << itemname[i] << endl;
            cout << "Item price: " << itemprice[i] << " Rupees" << endl;
            found = true;
            break;
        }
    }
    if (!found){
        cout << "Item with ID " << id << " not  found" << endl;
    }
}
int main(){
    shop product;
    int n;
    cout << "Enter the number of items in the shop: ";
    cin >> n;
    product.setcounter();
    for (int i = 0; i < n; i++){
        product.getname();
        product.getid();
        product.getprice();
    }
    product.display();
    char c;
    int id;
    cout << "Do you want to search an item? [y/n]" << endl;
    cout << "=> ";
    cin >> c;
    while (c == 'y'){
        cout << "Enter the item id: ";
        cin >> id;
        product.searchid(id);
        cout << "Do you want to search an item again? [y/n]" << endl;
        cout << "=> ";
        cin >> c;
    }
    cout << "Thank you for using the shop management system!" << endl;

    return 0;
}