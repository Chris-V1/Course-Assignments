// Cristian Molano - cmola002
// Section 20

#include "IntList.h"

void IntList::removeOdds() {
   IntNode* pot_copy = 0;
    IntNode* previous = head;
    for(IntNode* t = head; t != nullptr; t= t->next)
    {
        pot_copy = t->next; 
        previous = t;
        while(pot_copy!=nullptr)
        {
            if(t->value % 2 != 0)
            {
               
                IntNode* trash = pot_copy;
                previous->next = pot_copy->next;
                pot_copy = pot_copy->next;
                delete trash;
                
                
            }
            else
            {
                pot_copy = pot_copy->next;
                previous = previous->next; 
            }
            
        }
    }
}