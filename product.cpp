#include <iostream>
using namespace std;

class shop{
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
    void update(int id);
    void sort();
    void total();
    void additem();
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
    cout << "\\n========= Shop Inventory =========\\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "Item #" << i + 1 << endl;
        cout << "Name  : " << itemname[i] << endl;
        cout << "ID    : " << itemid[i] << endl;
        cout << "Price : " << itemprice[i] << " Rupees" << endl;
        cout << "------------------------------" << endl;
    }
}
void shop::searchid(int id){
    bool found = false;
    for (int i = 0; i < counter; i++)
    {
        if (itemid[i] == id)
        {
            cout << "Item found with ID " << id << " !" << endl;
            cout << "Item name: " << itemname[i] << endl;
            cout << "Item price: " << itemprice[i] << " Rupees" << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Item with ID " << id << " not  found" << endl;
    }
}
void shop::update(int id){
    bool found = false;
    for (int i = 0; i < counter; i++){
        if (itemid[i] == id){
            found = true;
            cout << "What do you want to update? [(/name), (/price)]" << endl;
            string up;
            cin >> up;
            if (up == "/name"){
                cout << "Enter the new name: ";
                cin >> itemname[i];
                cout << "Process succesful!!" << endl;
            }
            else if (up == "/price"){
                cout << "Enter the new price: ";
                cin >> itemprice[i];
                cout << "Process succesful!!" << endl;
            }
            else{
                cout << "Invalid command detected" << endl;
            }
        }
    }
    if (!found){
        cout << "No item found with certain ID" << endl;
    }
}
void shop::sort(){
    int sortedprice[50];
    cout << "Enter 'a' for ascending, 'b' for descending: ";
    char sh;
    cin >> sh;
    for (int i = 0; i < counter; i++){
        sortedprice[i] = itemprice[i];
    }

    if (sh == 'b'){
        for (int i = 0; i < counter - 1; i++){
            for (int j = i + 1; j < counter; j++){
                if (sortedprice[i] < sortedprice[j]){
                    swap(sortedprice[i], sortedprice[j]);
                }
            }
        }
        cout << "\\n========= Sorted Inventory (Descending by Price) =========\\n";
            for (int i = 0; i < counter; i++){
                for (int j = 0; j < counter; j++){
                    if (itemprice[j] == sortedprice[i]){
                    cout << "Item #" << i + 1 << endl;
                    cout << "Name  : " << itemname[j] << endl;
                    cout << "ID    : " << itemid[j] << endl;
                    cout << "Price : " << itemprice[j] << " Rupees" << endl;
                    cout << "------------------------------" << endl;
                    break;
                }
            }
        }
    } else if (sh == 'a'){
        for (int i = 0; i < counter - 1; i++){
            for (int j = i + 1; j < counter; j++){
                if (sortedprice[i] > sortedprice[j]){
                    int temp = sortedprice[i];
                    sortedprice[i] = sortedprice[j];
                    sortedprice[j] = temp;
                }
            }
        }
        cout << "\\n========= Sorted Inventory (Ascending by Price) =========\\n";
        for (int i = 0; i < counter; i++) {
            for (int j = 0; j < counter; j++) {
                if (itemprice[j] == sortedprice[i]) {
                    cout << "Item #" << i + 1 << endl;
                    cout << "Name  : " << itemname[j] << endl;
                    cout << "ID    : " << itemid[j] << endl;
                    cout << "Price : " << itemprice[j] << " Rupees" << endl;
                    cout << "------------------------------" << endl;
                    break;
                }
            }
        }
    } else {
        cout << "Invalid command detected" << endl;
    }
}
void shop::total(){
    cout << "Total number of items: " << counter << endl;
    int total = 0;
    for(int i = 0; i < counter; i++){
        total += itemprice[i];
    }
    cout << "Total worth: " << total << "  Rupees" << endl;
}
void shop::additem(){
    getname();
    getid();
    getprice();
    display();
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
    cout << endl;
    string cmd;
    int id;
    while (true) {
        cout << "Choose command [(/update), (/sort), (/total), (/add), (/search), (/end)]" << endl;
        cout << "=> ";
        cin >> cmd;

        if (cmd == "/update") {
            cout << "Enter the id: ";
            cin >> id;
            product.update(id);
        } else if (cmd == "/sort") {
            product.sort();
        } else if (cmd == "/total") {
            product.total();
        } else if (cmd == "/add") {
            product.additem();
        } else if (cmd == "/search") {
            char c = 'y';
            while (c == 'y') {
                cout << "Enter the item id: ";
                cin >> id;
                product.searchid(id);
                cout << "Do you want to search an item again? [y/n]" << endl;
                cout << "=> ";
                cin >> c;
            }
        } else if (cmd == "/end") {
            break;
        } else {
            cout << "Invalid command!!" << endl;
        }
    }

    cout << "Thank you for using the shop management system!" << endl;
    return 0;
}