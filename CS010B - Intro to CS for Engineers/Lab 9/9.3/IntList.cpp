// Cristian Molano - cmola002
// Section 20

#include "IntList.h"

#include <ostream>
#include <iostream>
using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &out, const IntList &list)
{
   /*
   IntNode* t = list.head;
   if(t == nullptr)
   {
      return out;
   }
   else
   {
      out << t->value << " ";
      
      if(t->next == nullptr)
      {
         return out;
      }
      else
      {
         IntList l;
         l.push_front(t->next->value);
         cout << l;
         return out;
      }
   }
   */
   if(list.head == nullptr)
   {
      return out;
   }
   else if(list.head)
   {
      out << list.head->value << list.head->next;
   }
   return out;
   
}

ostream & operator<<(ostream &o, IntNode *node)
{
   if(node == nullptr)
   {
      return o;
   }
   o << " " << node->value << node->next;
   return o;
}

bool IntList::exists(int num) const
{

   return exists(head, num);

   /*
   if(head == nullptr)
   {
      return false;
   }
   if(num == head->value)
   {
      return true;
   }
   else
   {
      if(head->next == nullptr)
      {
         return false;
      }
      else if(head->next->value == num)
      {
         return true;
      }
      else
      {
         bool e = exists(head->next, num);
         return e;
      }
   }
   */
}
bool IntList::exists(IntNode *node,int num) const
{
   if(node == nullptr)
   {
      return false;
   }
   else if(node->value == num)
   {
      return true;
   }
   else
   {
      if(node->next == nullptr)
      {
         return false;
      }
      return exists(node->next, num);
   }
  
}