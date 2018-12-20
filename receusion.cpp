
// 有记忆的递归，动态规划，2*1 填充 2*8的矩阵
int num_fill（）{
	int std::vector<int> v(8,0);
	v[0] = 1;
	v[1] = 2;
	for (int i = 2; i < 8; ++i)
	{
		V[i] = v[i-1] + v[i-2];
	}
}


//bit operation
int num_bit1(int t){
	int test_bit = 1;
	int num;
	while(test_bit != 0){
		if (test_bit & t != 0)
		{
			num++;
		}
	}
	return num;
}

//最优

int num_bit1(int t){
	int num = 0;
	while(t){
		t = t & t-1; 
	}
	return num;
}