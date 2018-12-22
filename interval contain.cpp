
//whether I in the v?

using namespace std;



bool cmp(const pair<int,int> a,const pair<int,int> b){
	return a.first < b.first 
} 

bool include_interval(vector<pair<int,int>> v,pair<int，int> I){
	sort(v.begin(),v,end(),cmp());
	auto it = v.begin();
	vector<pair<int,int>> m;
	pair<int,int> last = *v.begin();
	for (auto u ： v)
	{
		if (u.first <= last.second)
		{
			if (u.second > last.second)
			{
				last.second = u.second;
			}
		}
		else{
			 v.push_back(last)
			 last = u;
	}
	bool b_find(vector<pair<int,int>> v,pair<int，int> I);
}

bool b_find(vector<pair<int,int>> v,pair<int，int> I){

 	int l = 0;
 	int r = v.size() - 1;
 	if (l == r) 
 	{
 		if (I.first >= v[r].first && I.second <= v[r].second) return true;	
 		else return false;
 	}
 	if (l == r-1)
 	{
		if (I.first >= v.begin().first && I.second <= v.begin().second) return true;
 		if (I.first >= v.back().first && I.second <= v.back().second) return true; 		
 		return false;
 	}

 	while(l != r - 1){
 		int p = l + (r-l)/2;
 		if (I.first < v[p].first) r = p - 1;
 		if (I.first >= v[p].first) l = p;
	}
	if (r == p - 1)
	{
		if (I.first >= v[r].first && I.second <= v[r].second) return true;
		if (I.first >= v[l].first && I.second <= v[l].second) return true;
		return false;
	}
	if (l == p)
	{
		if (I.second <= v[l].second) return true;
		if (I.first >= v[r].first && I.second <= v[r].second) return true;
		return false;	
	}
}