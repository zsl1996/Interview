//one dimension pooling
//one method of geting max value of  a queue at aby time 
//O(3n)

template<class T>
class maxget_stack
{
public:
	maxget_stack(){ };
	void pop();
	T push(T n);
	T get_max();
	bool empty();
private:
	vector<T> value;
	vector<T> temp_max;	
};

T maxget_stack::pop(){
	if(value.empty()){
		throw std::exception("erro stack is empty"); //c++14
	}
	T v = value.back();
	value.erase(value.end()-1);
	temp_max.erase(temp_max.end()-1);
	return v;
}

void maxget_stack::push(T n){
	if (value.empty())
	{
		value.push_back(n);
		temp_max.push_back(n);
	}
	else if(n > temp_max.back()){
		value.push_back(n);
		temp_max.push_back(n);	
	}
	else{
		value.push_back(n);
		temp_max.push_back(temp_max.back());		
	}
}

T maxget_stack::get_max(){
	return temp_max.back();
}

bool maxget_stack::empty(){
	return value.empty();
}


template<class T>
class maxget_queue{
	
	public:
	maxget_queue(){};
	void pop();
	void insert(T n);
	T get_max();

	private:
	maxget_stack s1;
	maxget_stack s2;

}


void  maxget_queue::insert(T n){
	s1.push(n);
}

void  maxget_queue::pop(){
	if (s1.empty()&&s2,empty())
	{
		throw std::exception("erro queue is empty");
	}
	else if (s1.empty())
	{
		while(!s2.empty()){
			s1.push(s2.pop());
		}
		s1.pop();
	}
	else s1.pop();
	}

}

T maxget_queue::get_max(){
	return std::max(s1.get_max(),s2.get_max());
}


vector<int> onedimension_pooling(vector<int> v, int windows_size,int stride){ // 不能被整除，按填充0 处理
	vector<int> r;
	maxget_queue<int> q;
	int i = 0;
	int j = 0;
	if (v.empty()){
		throw std::exception("erro v is empty");
	}
	else if (v.size() <= windows_size)
	{
		 *max_element(v.begin(),v.end());
	}
	else{
		int i = 0;
		int j = 0;
		for (auto u : v)
		{
			if (i < windows_size)
			{
				q.push(u);
			}
			else {
				j++;
				q.pop();
				q.push(u);
				if (j == n)
				{
					v.push_back(q.get_max());
					j = 0;
				}
			}

		}
	}
	if (j < n)
	{
		v.push_back(q.get_max());
	}
	return v;
}