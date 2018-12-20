#include "pch.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<set>
#include<map>

//high dimension vector

using namespace std;
vector<vector<int>> resize(int row ,int col) {
	vector<vector<int>>* p = new vector<vector<int>>;
	p->resize(row);
	int j = 0;
	for (vector<vector<int>>::iterator it = p->begin(); it != p->end(); it++)
	{
		it->resize(col);
		for (auto  i = 0; i < col; i++,j++)
		{
			(*it)[i] = j;
		}
	}
	return *p;
}

int main() {
	for (auto it : resize(10,11)) {
		for (auto i: it)
		{
			cout << i << ' ';
		}
		cout << endl;
	}
}

