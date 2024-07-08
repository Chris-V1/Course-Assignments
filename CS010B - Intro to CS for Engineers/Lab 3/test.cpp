// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
using namespace std;
void PrintMenu();
int main()
{
    string n, d;
    int c = 0;
    char option;
    cout << "Enter customer's name: " << endl;
    getline(cin, n);
    cout << "Enter today's date: " << endl;
    getline(cin, d);
    cout << endl;
    ShoppingCart cart = ShoppingCart(n,d);
    cout << "Customer name: " << cart.customerName() << endl << "Today's date: " << cart.date() << endl << endl;
    PrintMenu();
    while(true)
    {
        cin >> option;
        cout << endl;
        if(option == 'q')
        {
            break;
        }
        else if(option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o')
        {
            if(option == 'a')
            {
                string an, ad;
                int p, q;
                ItemToPurchase item;
                cout << "ADD ITEM TO CART" << endl;
                cout <<"Enter the item name: " << endl;
                cin.ignore(1000, '\n');
                getline(cin,an);
                item.setName(an);
                cout << "Enter the item description: " << endl;
                getline(cin,ad);
                item.setDescription(ad);
                cout << "Enter the item price: ";
                cin >> p;
                item.setPrice(p);
                cout << endl;
                cout << "Enter the item quantity: " << endl << endl;
                cin >> q;
                item.setQuantity(q);
                cart.addItem(item);
            }
            else if(option == 'd')
            {
                string remove_name;
                cout << "REMOVE ITEM FROM CART" << endl << "Enter name of item to remove: " << endl;
                cin.ignore(1000, '\n');
                getline(cin,remove_name);
                cart.removeItem(remove_name);
                cout << endl;
                
            }
            else if(option == 'c')
            {
                string change_name;
                int quantchange;
                cout << "CHANGE ITEM QUANTITY" << endl << "Enter the item name: " << endl;
                cin.ignore(1000, '\n');
                getline(cin,change_name);
                cout << "Enter the new quantity: " << endl;
                cin >> quantchange;
                ItemToPurchase modiItem;
                modiItem.setName(change_name);
                modiItem.setQuantity(quantchange);
                cart.modifyItem(modiItem);
                
            }
            else if(option == 'i')
            {
                cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cart.printDescriptions();
                
            }
            else if(option == 'o')
            {
                cout << "OUTPUT SHOPPING CART" << endl;
                cart.printTotal();
                
            }
        }
        else
        {
            cout << "Choose an option: " << endl;
        }
        
    }
}
void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: ";
}