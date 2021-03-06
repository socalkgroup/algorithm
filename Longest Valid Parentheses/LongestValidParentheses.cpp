// LongestValidParentheses.cpp
// thkim

#include "stdafx.h"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	string input = ")()())(())))))((()))((((";
	int q = 0;
	int cnt = 0;
	priority_queue<int> maxq;

	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '(')
			q++;
		else if (q > 0)
		{
			cnt++;
			if (--q == 0)
			{
				maxq.push(cnt);
				cnt = 0;
			}
		}
	}

	cout << maxq.top() * 2 << endl;

  return 0;
}

