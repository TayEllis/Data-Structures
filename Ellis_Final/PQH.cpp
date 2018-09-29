#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "PQH.h"
using namespace std;

minHeap::minHeap(int cap){
	currentSize = 0;
	capacity = cap;
}

minHeap::~minHeap(){}

void minHeap::buildH(string filename,int a){
	clock_t start,end;
	ifstream myfile(filename);
	//ofstream outfile("")
	string name, priority, treatment;
	int i = 0;
	int linecount = 0;
	while(!myfile.eof() && linecount < a){
		getline(myfile,name,',');
		getline(myfile,priority,',');
		getline(myfile,treatment, '\r');
		if(name != "Name"){
			int p = stoi(priority);
			int t = stoi(treatment);
			node *newpatH = new node(name,p,t);
			//start = clock();
			push(newpatH);
			//end = clock();
			//float runtime = (end - start)/ (CLOCKS_PER_SEC);

			linecount++;
		}
	}
	myfile.close();
}

void minHeap::push(node* l){
	if(currentSize == capacity){
		cout << "ERROR -- FULL" << endl;
	}
	else{
		currentSize++;
		int i = currentSize;
		heaparr[i] = l; // puts @ first unused index in arr
		while(i > 1 && (heaparr[i/2]->prio > heaparr[i]->prio|| (heaparr[i/2]->prio == heaparr[i]->prio && heaparr[i/2]->treat > heaparr[i]->treat))){
			//cout << i << endl;
			node *temp = heaparr[i];
			heaparr[i] = heaparr[i/2];
			heaparr[i/2] = temp;
			i = i/2;
		}	
	}
}

node* minHeap::pop(){
	if(currentSize == 0){
		cout << "~EMPTY~" << endl;
		return heaparr[0];
	}
	if(currentSize == 1){
		currentSize--;
		return heaparr[1];
	}

	node *popper = heaparr[1];
	heaparr[1] = heaparr[currentSize]; //moves last index to root pos->
	currentSize--;
	minHeapify(1);
	return popper;
}


void minHeap::minHeapify(int i){
	int l = 2*i;
	int r = 2*i + 1;
	int small = i;
	if(l <= currentSize && (heaparr[l]->prio < heaparr[i]->prio)){
		small = l;
	}
	if(l <= currentSize && (heaparr[l]->prio == heaparr[i]->prio && heaparr[l]->treat < heaparr[i]->treat)){
		small = l; 
	}
	if(r <= currentSize && heaparr[r]->prio < heaparr[small]->prio){
		small = r;
	}
	if(r <= currentSize && (heaparr[r]->prio == heaparr[small]->prio && heaparr[r]->treat < heaparr[small]->treat)){
		small = r;
	}
	if(small != i){
		node * temp = heaparr[i];
		heaparr[i] = heaparr[small];
		heaparr[small] = temp;
		minHeapify(small);
	}
}

void minHeap::deleteH(){
	cout<<"Rank"<<'\t'<<"patient,  Priority,  treat"<<endl;
	int sizestart = currentSize;
	for(int i = 1; i <= sizestart; i++){
		node* dVal = pop();
		cout<<i<<":"<<'\t'<<dVal->patient<<",  "<<dVal->prio<<",  "<<dVal->treat<<endl;
	}
}

