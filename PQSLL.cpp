#include <iostream>
#include "PQSLL.hpp"
using namespace std;



void pqList::enqueue(string n, int p, int t )
{



    // Create new Node
   listNode *temp = new listNode(n,p,t);
   if (head == NULL)
   {
    // cout << "create head" << endl;
     head = temp;
     return;
   }

    if (head->pri > p)
    {
      //cout << "new head" << endl;

        // Insert New Node before head
        temp->next = head;
        head = temp;
    }
    else
    {

          listNode *start = head;
          while (start->next != NULL && *(start->next) < *temp)
            start = start->next;


          temp->next = start->next;
          start->next = temp;



    }


}

void pqList::dequeue()
{
  while (head != NULL)
  {
    listNode * temp = head;
    //cout << temp->name << " dequeued\n";
    head = head->next;
    delete temp;
  }





}

void pqList::printQueue()
{
  listNode * current;
  current = head;
  int count = 1;
  while (current!= NULL)
  {
    cout <<count << ": " << current->name << " " << current->pri << " " << current->treat << endl;
    count++;
    current = current->next;
  }


}