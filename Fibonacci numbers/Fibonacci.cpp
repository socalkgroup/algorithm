// Fibonacci 
// Author thkim

#include "stdafx.h"
#include <unordered_map>
#include <iostream>

using namespace std;

namespace
{
	unordered_map<int, int> s_memo;
}

int Fibo(int n)
{
	if (n != 0 && n != 1)
	{
		auto it = s_memo.find(n);
		if (it != s_memo.end())
			return it->second;
		n = s_memo[n] = Fibo(n - 2) + Fibo(n - 1);
	}
	return n;
}

int main()
{    
	for (int i = 0; i < 15; ++i)
	{
		cout << Fibo(i) << ",";
	}
	cout << endl;
}

