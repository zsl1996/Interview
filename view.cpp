#include<vector>
using namesapce std；

#define maxnum_node 1000000

vector<int> e[maxnum_node]; //拉链法
int n_num; // num of node
int vis[maxnum_node] = {0};
int e_num; //num of edge
 void build_G(){
 	cin >> e_num >> n_num;
 	int a,b;
 	for (int i = 0; i < e_num; ++i)
 	{
 		cin >> a >> b;
 		e[a].push_back(b);
 		e[b].push_back(a); 
 	}
 }

 void DFS(int begin){
 	vis[begin] = 1;
 	for(auto i : e[begin]){
 		if (!vis[i])
 		{
 			DFS[i];
 		}
 	}
 }	




int get_novist(int node){
	for (auto i : e[node])
	{
		if(!vis[i]) return i;
	}
	return 0;
}
void DFS(int begin){
	visi[begin] = 1;
	stack<int> s;
	s.push(begin);
	int p;
	while(!s.empty()){
		p = s.top();
		while(!get_novist(p)){
			p = get_novist(p);
			vis[p] = 1;
		}
		s.pop();
}



void BFS(int i){
	queue<int> q;
	q.insert(i);
	while(！q.empty()){
		p = q.top();
		q.pop();
		for (auto i : e[p])
		{
			 if(!vis[i]){
			 	vis[i] = 1;
			 	q.push(i);
			 }
		}
	}
}


struct linkist {
	int value;
	linkist* next =NULL;
};

linkist* reverselist(linkist* root) {
	if (root == NULL) return root;
	linkist* p;
	linkist* q;
	linkist* newroot;
	newroot = p = q = root;
	q = p->next;
	newroot->next = NULL;
	while (q) {
		p = q;
		q = p->next;
		p->next = newroot;
		newroot = p;
	}
	return newroot;
}

void max_p(int a[],int s, int len ) { //原本一个heap，a[s]元素被替代后如何重新调整
	int large = s;
	int olarge = s+1;
	int l, r;
	while (olarge != large)
	{
		olarge = large;
		l = large * 2 + 1;
		r = large * 2 + 2;
		if (l < len&& a[l] < a[large]) large = l;
		if (r < len && a[r] < a[large])  large = r;
		std::swap(a[olarge], a[large]);
	}
}

void make_heap(int a[],int len) { //
		for (int i = len - 1; i > -1; i--)
		{
			max_p(a, i, len);
		}
}

void heap_sort(int a[], int len) {
	make_heap(a, len);
	for (int i = len - 1; i > -1; i--)
	{
		std::swap(a[i], a[0]);
		max_p(a, 0, i);
	}
}

struct Btree
{
	int val;
	Btree* lc = NULL;
	Btree* rc = NULL;
};

Btree* build_tree() {
	char c;
	cin >> c;
	if (c == '#') return NULL;
	Btree* newnode = new Btree;
	newnode->val = c;
	newnode->lc = build_tree();
	newnode->rc = build_tree();
	return newnode;
}

void pre_visit(Btree* root) {
	stack<Btree*> s;

	Btree* p;
	p = root;
	while (p||!s.empty()) {
		while (p) {
			cout << p->val << ' ';
			s.push(p);
			p = p->lc;
			if(p) s.push(p);
		}
		p = s.top()->rc;
		s.pop();
	}
}




int b_find(vector<int> v, int value) {
	int l = 1;
	int r = v.size() - 1;
	int p = 0;
	while (l <= r)  // !!!小于等于

	{
		p = l + (r - l) / 2;
		if (v[p] < value)
		{
			l = p + 1;
		}
		else if (v[p] > value) {
			r = p - 1;
		}
		else return p;
	}
	return -1;
}

int get_max(vector<int> v, int j) {
	int end = v.size();
	int max = 0;
	for (int i = 0; i < end; i++)
	{
		if (i != j && v[i] > max) max = v[j];
	}
	return max;

}



vector<int> max_num(vector<int> v) {
	vector<int> r;
	if (v.empty()) return r;
	int last = v[0];
	int num = 0;
	for (auto u : v) {
		if (u == last) num++;
		else
		{
			r.push_back(num);
			num = 0;
			last = u;
		}
	}
}

int max_continue(vector<int> v) {
	int end = v.size();
	int max = 0;
	max = v[0] + get_max(v, 0);
	max = std::max( max,v.back() + get_max(v, end - 1));
	int temp = 0;
	for (int i = 1; i < end-1; i++)
	{
		temp = v[i - 1] + v[i + 1];
		temp = std::max(temp, get_max(v, i));
		max = std::max(max, temp + v[i]);
	}
	return max;
}

