#include <bits/stdc++.h>
using namespace std;


struct nodeLL{

	int data;
	nodeLL *pre, *next;

};

struct nodeT{

	int data;
	nodeT *pre, *lch, *rch;
	nodeLL *lp, *rp;
};


void insert(nodeT* ptr, int data){
	if(data < ptr->data){
		if(ptr->lch == NULL){
			
		}
		else insert(ptr->lch, data);
	}
	else if(data > ptr->data){
		if(ptr->rch == NULL){

		}
		else insert(ptr->rch, data);
	}
}




int main(){

	cout << "Enter no of elements" << endl;
	int n;
	cin >> n;

	vector<int> pre(n,0);
	vector<int> in(n,0);
	nodeLL *start = NULL;
	nodeLL *end = NULL;

	for(int i = 0; i < n; i++){
		nodeLL *temp = new nodeLL();
		temp->next = NULL;
		temp->data = in[i];
		if(start == NULL){
			start = temp;
			end = temp;
			temp->pre = NULL;
		}
		else{

			temp->pre = end;
			end->next = temp;
			end = temp;

		}
	}

	nodeT *root = NULL;

	nodeT *temp = new nodeT();
	temp->data = pre[0];
	temp->pre = NULL;
	temp->rch = NULL;
	temp->lch = NULL;
	root = temp;

	nodeLL* itr = start;
	while(itr->data != pre[0])	itr = itr->next;
	if(itr != start){
		temp->lp = start;
		itr->pre->next = NULL;
	} 
	else temp->lp = NULL;

	if(itr != end){
		temp->rp = itr->next;
		itr->next->pre = NULL;
	}
	else temp->rp = NULL;

	for(int i = 1; i < n; i++){
		insert(root,pre[i]);
	}

}