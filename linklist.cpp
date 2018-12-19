//related to linklist 
#include<stack>
struct node{
	int val = 0;
	node* next = NULL;
}

//swap linklist 

node* swaplist(node* head){
	if(head ==NULL||head->next == NULL) return head;
	node* p = head;
	node* q = NULL;
	node* new_head = NULL;
	while(p->next){
		q = p->next;
		p->next = new_head;
		new_head = p;
		p = q;
	}
	return new_head;
}

void backorder_print(node* head){
	using namespace std;
	stack<node*> s;
	node* p = head;
	while(p){
		s.push_back(p);
		p = p->next;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
} 
