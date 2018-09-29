#ifndef PQH_h
#define PQH_h
#include <iostream>
#include <climits>

using namespace std;

struct node{
	string patient;
	int prio; //time to delivery
	int treat; // treatment time
	node(){};
	node(string n, int p, int t){
		patient = n;
		prio = p;
		treat = t;
	}
};



class minHeap{
	
		

	public:
		node* heaparr[881];  //array for patients
		int currentSize;
		int capacity; 

		~minHeap();
		minHeap(int);      // array size as argument
		void push(node*);   // heap of ints
		node* pop();	  // remove
		void minHeapify(int);
		void buildH(string,int);
		void deleteH();
		
		
		
		
	

};

#endif