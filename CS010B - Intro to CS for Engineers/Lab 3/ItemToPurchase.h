#include <iostream>
using namespace std;
#ifndef _ITEMTOPURCHASE_
#define _ITEMTOPURCHASE_
class ItemToPurchase{

public:
    ItemToPurchase();
    ItemToPurchase(string, string, int, int);
    void setName(string); //sets name
    string name(); //returns name

    void setPrice(int); //sets price
    int price(); //returns price

    void setQuantity(int); //sets quantiy
    int quantity(); //returns quantity

    void setDescription(string);//sets description
    string description(); //returns description

    void printItemCost();//prints cost
    void printItemDescription();//prints description
    
private:

    string _name();
    int _price();
    int _quantity();


    string ItemName;
    string ItemDescription;
    int ItemCost;
    int ItemQuantity;
};
#endif