// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart()
{
    CustomerName = "none";
    currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string n, string d)
{
    CustomerName = n;
    currentDate = d;
}
string ShoppingCart::customerName()
{
    return CustomerName;
}
string ShoppingCart::date()
{
    return currentDate;
}
void ShoppingCart::addItem(ItemToPurchase item)
{
    cartItems.push_back(item);
}
void ShoppingCart::removeItem(string item)
{
    int c = 0;
    int size = cartItems.size();
    vector<ItemToPurchase> v;
    for(int i = 0; i < size; ++i)
    {
        if(cartItems.at(i).name() == item)
        {
            c = 1;
        }
    }
    if(c == 1)
    {
        for(int i = 0; i < size; ++i)
        {
            if(cartItems.at(i).name() != item)
            {
                v.push_back(cartItems.at(i));
            } 
        }
    }
    else
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
    
    cartItems = v;
}
void ShoppingCart::modifyItem(ItemToPurchase item)
{
    int c = 0;
    int size = cartItems.size();
    for(int i = 0; i < size; ++i)
    {
        if(cartItems.at(i).name() == item.name())
        {
            c = 1;
        }
    }
    if(c == 1)
    {
        for(int i = 0; i < size; ++i)
        {
            if(cartItems.at(i).name() == item.name())
            {
                cartItems.at(i).setQuantity(item.quantity());
                //cout << "yeehoo is: " << cartItems.at(i).quantity() << endl;
            } 
        }
    }
    else
    {
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}
int ShoppingCart::numItemsInCart()
{
    int size = cartItems.size(), numI = 0;
    for(int i = 0 ; i < size; ++i)
    {
        numI = numI + cartItems.at(i).quantity(); 
    }
    return numI;
}
int ShoppingCart::costOfCart()
{
    int cost = 0, quan;
    int size = cartItems.size();
    for(int i = 0; i < size ; ++i)
    {
        quan = cartItems.at(i).price() * cartItems.at(i).quantity();
        cost = cost + quan;
    }
    return cost;
}
void ShoppingCart::printTotal()
{
    int size = cartItems.size();
    cout << CustomerName <<"'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl << endl;
    if(size == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else
    {
        for(int i = 0; i < size; ++i)
        {
            cartItems.at(i).printItemCost();
        }
    }
        
    cout << endl;
    cout << "Total: $" << costOfCart() << endl << endl;
    
}
void ShoppingCart::printDescriptions()
{
    int size = cartItems.size();
    cout << CustomerName <<"'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions"<< endl;
    for(int i = 0; i < size; ++i)
    {
        cartItems.at(i).printItemDescription();
        cout << endl;
    }
    cout << endl;
}