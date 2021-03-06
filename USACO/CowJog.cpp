// CowJog.cpp
// thkim

#include "stdafx.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> idx = { 0,1,2,3,6 };
	vector<int> speed = { 1,2,3,2,1 };

	bool sep = false;
	int m = speed[speed.size() - 1];
	int tail = idx[speed.size() - 1];
	int cnt = 1;

	// go though backward
	for (int i = idx.size()-2; i >= 0; --i)
	{		
		if (speed[i] < m || (speed[i] == m && sep)) // if slow or same seperated
		{
			// found a new group
			m = speed[i];
			cnt++;
			sep = false;
		}
		if (tail - idx[i] > 1)
			sep = true;
	}

	cout << cnt << endl;
  return 0;
}

