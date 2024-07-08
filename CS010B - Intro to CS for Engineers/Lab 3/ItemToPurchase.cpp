// Cristian Molano - cmola002
// Section 20

#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    ItemName = "none";
    ItemDescription = "none";
    ItemCost = 0;
    ItemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string n, string d, int p, int q)
{
    ItemName = n;
    ItemDescription = d;
    ItemCost = p;
    ItemQuantity = q;
}
void ItemToPurchase::setName(string n)
{
    ItemName = n;
}
string ItemToPurchase::name()
{
    return ItemName;
}
void ItemToPurchase::setPrice(int p)
{
    ItemCost = p;
}
int ItemToPurchase::price()
{
    return ItemCost;
}
void ItemToPurchase::setQuantity(int q)
{
    ItemQuantity = q;
    
}
int ItemToPurchase::quantity()
{
    return ItemQuantity;
}
void ItemToPurchase::setDescription(string d)
{
    ItemDescription = d;
}
string ItemToPurchase::description()
{
    return ItemDescription;
}
void ItemToPurchase::printItemCost()
{
    cout << ItemName << " " << ItemQuantity << " @ $" << ItemCost << " = $" << ItemQuantity * ItemCost << endl;
}
void ItemToPurchase::printItemDescription()
{
    cout << ItemName << ": " << ItemDescription;
}