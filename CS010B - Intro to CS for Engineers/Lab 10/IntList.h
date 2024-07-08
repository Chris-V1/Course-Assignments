#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int val) : value(val), next(nullptr) {}
};

class IntList {

 private:
   IntNode *head;

 public:

   /* Initializes an empty list.
   */
   IntList() : head(nullptr) {}

   /* Inserts a data value to the front of the list.
   */
   void push_front(int val) {
      if (!head) {
         head = new IntNode(val);
      } else {
         IntNode *temp = new IntNode(val);
         temp->next = head;
         head = temp;
      }  
   }
   
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   friend ostream & operator<<(ostream &out, const IntList &rhs) {
      if (rhs.head) {
         IntNode *curr = rhs.head;
         out << curr->value;
         for (curr = curr->next ; curr ; curr = curr->next) {
            out << ' ' << curr->value;
         }
      }
      return out;
   }
   
   /* Removes all nodes with an odd value. There is no return, the side effect is to modify the list.
   */
   void removeOdds();

};



#endif