//devide the array to two part, make sure that thr sum of each part as close to each other  as possible
using namespace std;

vector<unordered_multiset<int>> array_divide(vector<int> v){
	vector<unordered_multiset<int>> sv(2);
	if (sv.empty())
	{
		return sv;
	}
	int  n = v.size()/2;
	if (!n) //only one element
	{
		v[1].insert(v[0]);
		return v;
	}
	int sum = 0;
	for(auto u : v){
		sum = sum + u;
	}

	vector<vector<pair<bool,int>> lable(n);
	auto it = lable.begin();
	while(it != lable.end()){  //initial
		it->resize(sum/2);
		for (auto it1 = it->begin(); it1 != it->end(); ++it1)
		{
			*it1->first = false;
			*it1->second = 0;
		}
	}

	for (int i = 0; i < 2*n; ++i)
	{
		for (int j = 0; j <= td::min(i,n-1); ++i)
		{
			if(j == 0){
				if(v[i] <= sum / 2) lable[0][v[i]] = std::make_pair(true,v[i];
				break;
			}
			for (int k = v[i] - 1; k < sum/2; ++k)
			{
				lable[j][k].first = lable[j-1][k + 1 -v[i]];
				lable[j][k].second = v[i];
			}
		}
	}
	return re(lable,it,v);

}


//发溯得到解
vector<unordered_multiset<int>> print_best(vector<vector<pair<bool,int>> lable,vector<vector<pair<bool,int>>::iterator,vector<int> v_origin){
	vector<unordered_multiset<int>> v;
	unordered_multiset<int> s1;
	int last_value = it->second;
	s1.insert(last_value);
	int temp = it - lable[lable.size()-1].begin()] - last_value;  //the position on 
	for (int i = n-1; i != -1; i--)
	{
		s1.insert(lable[i][temp]->second);
		temp = temp - lable[i][temp]->second;
	}
	v.push_back(s1);
	unordered_multiset<int> s2;
	for(auto u : v_origin){
		if (find(u,s1))
		{
			continue;
		}
		else s2.insert(u);
	}
	v.push_back(s2);
	return v;
}

bool find(unordered_mutiset s , int u){
	auto it = s.find(u);
	if (it == s.end())
	{
		return false;
	}
	else{
		s.erase(it);
		return true;
	}
}