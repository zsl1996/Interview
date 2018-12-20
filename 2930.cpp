//more lenghth/2 in the array
//solution: 1

int find_middle(vector<int> v){
	int l = 0;
	int r = v.size();
	int j = 0;
	int middle = v.size()/2;
	while(j != middle){
		j = partition(v,l,r);
		if (j > middle)
		{
			l = j + 1;
		}
		else{
			r = j - 1;
		}
	}
	return v[middle];
}


int find_middle(vector<int> v){
	int value;
	int num;
	if(v.empey()){
		throw std::exception('vector is empty');
	}
	auto it = v.begin();
	value = *it;
	it++;
	for(;it != v.end(); it++){
		if(*it != value){
			if(num == 0){
				value = *it;
				it++;
			}
			else if(value == *it){
				num++;
			}
			else{
				num--;
			}
		}
	}
}


//top k 


vector<int> find_topk(const vector<int> v,int k){
	mutiset<int,greater<int>> setk;
	if (v.size() <k)
	{
		return v;
	}
	for (auto u : v)
	{
		if (setk.size() < k)
		{
			setk.insert(u);
		}
		if (u < *(setk.begin())
		{
			setk.erase(setk.begin());
			setk.insert(u);
		}
	}
	vector<int> re;
	for(auto u : setk){
		re.push_back(u);
	}

}

