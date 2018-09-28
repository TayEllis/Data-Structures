#include"LLPQ.hpp"
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include"pat.hpp"
using namespace std;
llpq::llpq(){
    head=NULL;
    tail=NULL;
} //default constutor

llpq::~llpq(){} // defualt destructor
 
void llpq::insert(pat *in)
{
    if(head==NULL)
    {
        //cout<< "this case is happening"<< endl;
        // tail will also be NULL therefore the queue is empty
        head=in;
        tail=in;
        return;
    }
    pat* temp=head;
    while(temp!=NULL)
    {
        //cout<< "temp = "<< temp->name<< ", " <<temp->priority<< ", " << temp->treatment;
        //cout<< " compaterd to in =" <<in->name<< ", "<< in ->priority<< ", " << in->treatment<< endl;
        if(in->priority>temp->priority)
        {
            //test if at tail, insert
            //else, next
            if(temp==tail)
            {
                temp->next=in;
                in->prev=temp;
                tail=in;
                return;
            }
            // next
            temp=temp->next;
            continue;
        }
        else if(in->priority<temp->priority)
        {
            //cout<< "hello"<<endl;
            if(temp==head)
            {
                //cout<< "this should happen"<<endl;
                in->next=temp;
                temp->prev=in;
                head=in;
                return;
            }
            // insert before
            in->prev=temp->prev;
            temp->prev->next=in;
            in->next=temp;
            temp->prev=in;
            return;
        }
        else if(in->priority==temp->priority)
        {
            // then check for seondary priority
            if(in->treatment<temp->treatment)            
            {
                if(temp==head)
                {
                    in->next=temp;
                    temp->prev=in;
                    head=in;
                    return;
                }
                // insert before
                in->prev=temp->prev;
                temp->prev->next=in;
                in->next=temp;
                temp->prev=in;
                return;
            }
            else if(in->treatment>temp->treatment)
            {
                if(temp==tail)
                {
                    temp->next=in;
                    in->prev=temp;
                    tail=in;
                    return;
                }
                // next
                temp=temp->next;
                continue;
            }
            else
            {
                if(temp==head)
                {
                    in->next=temp;
                    temp->prev=in;
                    head=in;
                    return;
                }
                // insert before
                in->prev=temp->prev;
                temp->prev->next=in;
                in->next=temp;
                temp->prev=in;
                return;
            }
            
        }
    }
}

void llpq::build(string filename)
{
    string holder;
    ifstream datafile;
    string nam;
    int pri;
    int treat;
    datafile.open(filename);
    if(datafile.fail())
    {
        cout<< "File: "<< filename<< " does not exisit in current directory"<< endl;
    }
    getline(datafile, holder, '\r');
    string segment;
    while(getline(datafile,holder, '\r'))
    {
        stringstream ss(holder);
        getline(ss,segment, ',');
        nam=segment;
        getline(ss, segment, ',');
        pri= stoi(segment);
        getline(ss,segment, ',');
        treat= stoi(segment);
        pat *temp= new pat(nam, pri, treat);
        insert(temp);
    }
    datafile.close();
}
void llpq::printLLPQ()
{
    pat * temp=head;
    cout<<"Rank" << '\t'<< "patient,  Priority,  Treatment"<< endl;
    int i=1;
    if(temp->next==NULL)
    {
        cout<< "the linked list only has one item"<< endl;
    }
    while(temp!=NULL)
    {
       cout<<i<<":"<< '\t'<<temp->name<< ",  "<<temp->priority<< ",  "<< temp->treatment<< endl;
       temp=temp->next;
       i++;
    }
}
void llpq::dequeue()
{
    pat* temp=head;
    if(temp->next==NULL)
    {
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    temp=temp->next;
    delete temp->prev;
    temp->prev=NULL;
    head=temp;
}
void llpq::remove()
{
    while(head!=NULL && tail!=NULL)
    {
        dequeue();
    }
}