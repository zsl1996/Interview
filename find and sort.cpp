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

//q_find + 旋转数组
