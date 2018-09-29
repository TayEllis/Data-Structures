#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <time.h>
#include "PQSLL.cpp"
#include "PQH.cpp"
#include <math.h>
#include <cmath>
#include <chrono>
#include <cstdlib>

using namespace std;

struct patNode{
	string name;
	int priority;
	int treat;
	patNode(){};
	patNode(string n, int p, int t){
		name = n;
		priority = p;
		treat = t;
	}

	
};


class compare{
	
	public:
		int operator()(const patNode &a, const patNode &b){
			if(a.priority == b.priority){
				return a.treat > b.treat;
			}
			else{
				return a.priority > b.priority;
			}
		}
};


int main(){

		// reading in patients info for patarr
	ifstream myfile;
	string name, priority, treatment,line;
	patNode patarr[881];
	int i = 1;
	myfile.open("patientData2270.csv");

	if(!myfile.is_open()){
		cout << "ERROR OPENING FILE" << endl;
	}
	
	getline(myfile,line,'\r');

	while(!myfile.eof()){
        getline(myfile,name,',');
        getline(myfile,priority, ',');
        getline(myfile,treatment, '\r');
       
       	patarr[i].name = name;
       	patarr[i].priority = stoi(priority);
       	patarr[i].treat = stoi(treatment);
       	//cout << patarr[i].name << patarr[i].priority << patarr[i].treat << endl;
        i++;    
    }

	clock_t start, end;
	int testnum[9] = {100,200,300,400,500,600,700,800,880};

/*
				//HEAP TESTING (WORKING!!)
	minHeap h(880);
	ofstream hofile;
	ofstream hopop;
	hofile.open("hDataPUSH.csv");
	hopop.open("hDataPOP.csv");


	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 9; j++){ 
			start = clock();
			h.buildH("patientData2270.csv",testnum[j]); 
			end = clock();
			float poptime = (end - start) / (CLOCKS_PER_SEC/1000.0);

			start = clock();
			h.deleteH();
			end = clock();
			float hruntime = (float(end) - float(start)) / (CLOCKS_PER_SEC/1000.0);
			hofile << to_string(hruntime)+",";
		}
		hofile << "\n";
		hopop << "\n";
	}

*/


				//LL TESTING (WORKING!!)
	pqll lil;
	ofstream lloutfile;
	ofstream llpopfile;
	lloutfile.open("llDatapush.csv");
	llpopfile.open("llDatapop.csv");

	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 9; j++){
			//start = clock();
			lil.builder("patientData2270.csv", testnum[j]);
			//end = clock();
			//float llPUSH = (end - start)/(CLOCKS_PER_SEC/1000.0)
			//llpopfile << to_string(llPUSH)+",";
			//start = clock();
			lil.deletePQ();
			//end = clock();
			//float llruntime = (float(end) - float(start)) / (CLOCKS_PER_SEC/1000.0);
			//lloutfile << to_string(llruntime)+",";
		}

		
		//lloutfile << "\n";
		//llpopfile << "\n";
	}




						//STL 

	ofstream stlPUSH;
	ofstream stlPOP;
	stlPUSH.open("stlPUSH.csv");
	stlPOP.open("stlPOP.csv");

	int linecount = 0;
	priority_queue <patNode, vector<patNode>, compare > STL;


	for(int i = 0; i < 500; i++){
		for(int j = 0; j < 9; j++){
			linecount = 0;
			i = 0;
			while(linecount < testnum[j]){	
				start = clock();
				STL.push(patarr[i]);
				
				i++;
				linecount++;
			
				//cout << linecount << endl;
			}
			float pushtime = (end - start) / (CLOCKS_PER_SEC);
			stlPUSH << to_string(pushtime)+",";
			while(!STL.empty()){
				cout << STL.top().name << endl;
				STL.pop();
				end = clock();
				
			}
			float poptime = (end - start) / (CLOCKS_PER_SEC / 500.0);
			stlPOP << to_string(poptime)+",";
		}
		stlPOP << "\n";	
	}
}
