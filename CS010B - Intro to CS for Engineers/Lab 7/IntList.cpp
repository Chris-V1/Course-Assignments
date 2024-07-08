// Cristian Molano - cmola002
// Section 20

#include "IntList.h"
#ifndef INTLIST
#define INTLIST
#include <iostream>
using namespace std;

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}
IntList::~IntList()
{
    while(!empty())
    {
        pop_front();
    }
}
void IntList::push_front(int num)
{
    //tail = head;
    IntNode* t = head;
    head = new IntNode(num);
    head->next = t;
}
void IntList::pop_front()
{
    IntNode* temp = head;
    head = head->next;
    delete temp;
}
bool IntList::empty() const
{
    if(head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}
const int& IntList::front() const
{
   // IntNode* t = head;
   // int x = &t;
    //return x;
    if(empty())
    {
        exit(1);
    }
    return head->value;
   // return ee;
}
const int& IntList::back() const
{
    if(empty())
    {
        exit(1);
    }

    IntNode* temp = head;

    while(temp->next != 0)
    {
       temp = temp->next; 

       if(temp->next == 0)
       {
           return temp->value;
       }
    }

    if(temp->next == 0)
    {
         return temp->value;
    }
    else
    {
        return tail->value;
    }
    

    
}
ostream& operator<<(ostream & out, const IntList & list)
{
    if(list.empty())
    {
        return out;
    }
   IntNode* temp = list.head;
   if(temp->next == 0)
       {
           out << temp->value;
       }
   while(temp->next != 0)
    {
       out << temp->value << " ";
       temp = temp->next; 
       if(temp->next == 0)
       {
           out << temp->value;
       }
    }
    
   return out;

}
#endif