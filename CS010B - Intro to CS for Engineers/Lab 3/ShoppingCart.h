#include <iostream>
#include "ItemToPurchase.h"
#include <vector>
#ifndef _SHOPPINGCART_
#define _SHOPPINGCART_
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();

    ShoppingCart(string, string);

    string customerName();

    string date();

    void addItem(ItemToPurchase);

    void removeItem(string);

    void modifyItem(ItemToPurchase);

    int numItemsInCart();

    int costOfCart();

    void printTotal();

    void printDescriptions();

private:
    string CustomerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};
#endif