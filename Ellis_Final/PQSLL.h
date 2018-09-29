#ifndef PQSLL_h
#define PQSLL_h
#include <iostream>
using namespace std;

struct sllNode{
	string patient;
	int prio; //time to delivery
	int treat; // delivery time
	sllNode *next;
	sllNode *prev;
	sllNode(){};
	sllNode(string pat, int p, int t){
		patient = pat;
		prio = p;
		treat = t;
		next = NULL;
		prev = NULL;
	}
};

class pqll{

	public:
		pqll();
		~pqll();
		void pop();
		void builder(string,int);
		void deletePQ();
		sllNode* head;

	private:
		void addPat(string,int,int);
		sllNode* tail;

};

#endif