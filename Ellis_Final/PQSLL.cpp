#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<time.h>
#include<math.h>
#include"PQSLL.h"

using namespace std;

pqll::pqll(){
    head = NULL;
    tail = NULL;

}

pqll::~pqll(){
    deletePQ();
}

void pqll::addPat(string name, int p, int t){
    sllNode *temp;
    temp = head;
    sllNode *newpat = new sllNode(name, p,t);

    if(head == NULL){
        head = newpat;
        tail = newpat;
        return;
    }
    while(temp != NULL){
        if((newpat->prio < temp->prio) || ((newpat->prio == temp->prio) && (newpat->treat < temp->treat))){
            
            newpat->next = temp;
            newpat->prev = temp->prev;

            if(temp != head){
                temp->prev->next = newpat;
                temp->prev = newpat;
                return;
            }
            else{
                temp->prev = newpat;
                head = newpat;
                return;
            }
        }
        else if((newpat->prio > temp->prio) && temp == tail){
            temp->next = newpat;
            newpat->prev = temp;
            tail = newpat;
            cout<< tail->patient << endl;
            return;
        }
        temp = temp->next;
    }
}

void pqll::builder(string filename, int a){
    ifstream myfile(filename);
    ofstream outfile;
    outfile.open("lltest.csv");

    string name, priority, treatment;
    getline(myfile,name,'\r');
    clock_t start, end;
   
    int linenum = 0;

    while(!myfile.eof() && linenum < a){
        getline(myfile,name,',');
        getline(myfile,priority, ',');
        getline(myfile,treatment, '\r');
       
            int p = stoi(priority);
            int t = stoi(treatment);
            start = clock();
            addPat(name,p,t);
            end = clock();
            float runtime = (end - start) / (CLOCKS_PER_SEC/1000.0);
            outfile << to_string(runtime)+",";
            linenum++;
    }

    myfile.close();
    sllNode *temp = head;
    int i = 1;
    cout << "Rank" << '\t' << "Patient, Priority, Treatment" << endl;
    while(temp != NULL){
        cout << i << ":" << '\t' << temp->patient << ", " << temp->prio << ", " << temp->treat << endl; 
        temp = temp->next;
        i++;
    }
}

void pqll::pop(){
    sllNode *temp = head;
    head = temp->next;
    head->prev = NULL;
    delete temp;
}

void pqll::deletePQ(){
    sllNode *curr = head;
    sllNode *nextN = head;

    while(curr!=NULL){
        nextN = curr->next;
        delete curr;
        curr = nextN;
    }
    
    head = NULL;
    tail = NULL;
}


