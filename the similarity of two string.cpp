
// input two string and return the similaruty ,operation contain add delete and modify,
//diffrent operation should have different cost
// add =delete = c1 modify = c2
// operation flag 1 (s1.lengh-- ) ,flag 2 (s2.lengh--), flag 3 (s1-- ands s2 --)  flag 0 same char

#define c1 1
#define c2 2

float twostring_similarity(string s1, string s2){
	int l1 = s1.size(); 
	int l2 = s2.size();
	if (l1 == 0 || l2 == 0)
	{
		return abs(l1 - l2);
	}
	vector<vector<int>> cost(l1+1);
	for (auto it = cost.begin(); it != cost.end(); ++it)
	{
		it->resize(l2+1);
	}
	//initial 
	for (int i = 0; i < l1; ++i)
	{
		cost[i][0].first = i*c1;
		cost[i][0].second = 1;
	}
	for (int i = 0; i < l2; ++i)
	{
		cost[0][i].first = i*c1;
		cost[0][i].second = 2;
	}
	for (int i = 1; i < l1 + 1; ++i)
	{
		for (int j = 1; j < l2 + 1; ++j)
		{
			if (s1[i-1] == s2[j] )
			{
				cost[i][j].first = cost[i-1][j-1].first;
				cost[i][j].second = 0;
			}
			cost[i][j].first = std::min(std::min(cost[i][j-1].first + c1, cost[i-1][j].first + c1),cost[i][j].first + c2);
			if (cost[i][j].first == cost[i][j-1].first + 1)
			{
				cost[i][j].second = 2;	
			}
			else if (cost[i][j].first == cost[i-1][j].first + 1)
			{
				cost[i][j].second = 1;	
			}
			else{
				cost[i][j].second = 3;
			}
		}
	}
	// cout the operation
	stack<int> stack_operation;
	int i = 0;
	int j = 0;
	while(i != l1 && j != l2){
		cout << cost[i][j].second;
		if (cost[i][j].second == 2)
		{
			i++;
			j++;
		}
		else if(cost[i][j].second == 1)
		{
			i++;
		}
		else if(cost[i][j].second == 2)
		{
			j++;
		}
		else{
			i++;
			j++;
		}
	}	
	return 1/float(cost[i][j].first);	
}