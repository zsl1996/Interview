//find and sort

int q_find(const vector<int> v,int value){
	int l = 0;
	int r = v.rsize()-1;
	int p = 0;
	while(l <= r){
		p = l + (r-l)/2;
		if(v[p] == value) return p;
		else if(v[p] > value) r = p - 1;
		else l = p + 1;
	}
	return -1;
}

void q_sort(vector<int>& v,int l, int r){
	if(l > r) return;  
	p = partition(v,l,r);
	q_sort(v, p+1, r);
	q_sort(v, l, p -1);
}

int partition(const vector<int>& v, int l, int r){
	int p = l - 1;
	while(l < r){
		if(v[l] < v[r]){
			p++;
			std::swap(v[l],v[p]);
		}
	}
	std::swap(v[p+1],v[r]);
	return p + 1;
}





//mergesort 

void merge(vector<int>& v,int l, int p, int r){
	vector<int> temp;
	int l2 = p + 1;
	int i = 0;
	while(l <= p && l2 <= r){
		if (v[l] < v[l2]){
			temp.back(v[l]);
			l++;
		}
		else{
			temp.push_back(v[l2]);
			l2++;
		}
	}
	if (l > p)
	{	int j = 0;
		for (auto u : temp)
		{
			v[l+j] = u;
		}
	}
	else{
		for(;p >= l;p--,r--){
			v[r] = v[p];
		}
		int j = 0;
		for (auto u : temp)
		{
			v[l+j] = u;
		}
	}
}


vector<int> mergesort(vector<int> v,int l,int r){
	int p = l + (r - l)/2;
	mergesort(v,l,p);
	mergesort(v,p+1,r);
	merge(v,l,p,r);

}













//面试8 q_find + 旋转数组,有序数组（非严格递增）最开始几个元素换到末尾，find minima，

int spinvector_find(vector<int> v,int value)
{
	if (v.empty()){
		throw std::exception("erro v.size()");
	}
	int l = 0;
	int r = v.size() -1;
	int p = 0;
	while(v[l] >= v[r]){
		p = l + (r - l)/2;
		if(v[p] > v[r]) l = p + 1;
		if(v[p] < v[r]) r = p - 1;
		if（v[p] ==v[r]) return min_element(v.begin(),v.end()) - ve.begin();
	}
	if(l >= p) return l; //考虑反转了0个元素
}