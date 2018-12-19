//two sorted array find kth min number

using namespace std;
int k_min(vector<int> v1,vector<int> v2, int k){
	int l1 = v1.size();
	int l2 = v2.size();
	if (l1 +l2 < k)
	{
		return -1;
	}
	int t1 = 0;
	int t2 = 0;
	int step = 0;
	while(t1 + t2 != k-1 ){
		step = (k - (t1 + t2) )/2；
		if (t1 + step <= l1 && t2 + step <= l2)
		{
			if (v1[t1 + step -1] > v2[t2 + step -1])
			{
				t2 = t2 +step;
			}
			else{
				t1 = t1 + step;
			}
		}
		else if (t1 + step > l1)
		{
			if (v1[l1 -1] > v2[t2 + step -1])
			{
				t2 = t2 +step;
			}
			else{
				t1 = l1 -1;
			}
		else{
			if (v1[t1 +step -1] > v2[l2 -1])
			{
				t1 = t1 +step;
			}
			else{
				t2 = l2 -1;
			}
		}		
		}
	}
	return std::min(v1[t1],v2[t2]);
}