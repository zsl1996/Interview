// trick
//two sorted array find kth min number
// add # make always odd !!
//refer to https://www.cnblogs.com/voidsky/p/5373982.html
using namespace std;

double find_midsortedarrays(vector<int>& v1,vector<int>& v2,int k){
	int n = v1.size();
	int m = v2.size();
	if (n > m)  //make sure V1 is  shorted
	{
		return find_midsortedarrays(v2,v1);
	}
	int L1,L2,R1,R2,c1,c2,lo = 0,hi = 2*n;
	while（lo <= hi）{
		c1 = (lo+hi)/2;
		c2 = 2*k-c1;
		L1 = (c1 == 0)? INT32_MIN : v1[(c1-1)/2]; // map to original element
		R1 = (c1 == 2*n)? INT32_MAX : v2[c1/2];
		L2 = (c2 == 2*m)? INT32_MIN : v2[(c2-1)/2];
		R2 = (c2 == 2*m)? INT32_MAX : v2[c2/2];

		if (L1 > R2)
		 {
		 	hi = c1-1;
		 } 
		 else if (L2 > R1)
		 {
		 	lo = c1+1;
		 }
		 else break;
	}
	return (std::max(L1,L2)+std::min(R1,R2))/2.0;
}






//bymyself
double find_midsortedarrays(vector<int>& v1,vector<int>& v2,int k){

	int L1 = v1.size();
	int L2 = v2.size();
	if(L1 > L2) return find_midsortedarrays(v2,v1,k);
	int l = 0;
	int r = L1 - 1;
	int p1 = 0;
	int p2 = 0;
	while(l <= r){
		p1 = (l + r)/2;  //p1 + 1 elements actually
		p2 = k - p1 - 1;   //k - p1 elements,p2 is not in k
		if (v1[p1] < v2[p2]) 
		{
			l = p1 + 1;
		}
		else if (v1[p1] == v2[p2])
		{
			return v1[p1];
		}
		else{
			r = p1 - 1;
		}
	}
	if(r == -1) return v2[k-1];
	if(l == L1) return std::min(v1[L1-1],v2[k-L1-1]);
	return std::min(v1[p1],v2[k-p1-1]);
}