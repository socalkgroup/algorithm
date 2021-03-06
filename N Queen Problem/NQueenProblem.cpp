// NQueenProblem.cpp
//
// by thkim

#include <iostream>
#include <unordered_set>
#include <deque>

using namespace std;

class Board
{
public:
	Board(int N) : m_N(N) {}
	bool CanPlace(int x, int y) {
		return horiTaken.end() == horiTaken.find(y) &&
			vertTaken.end() == vertTaken.find(x) &&
			digRLTaken.end() == digRLTaken.find(x + y) &&
			digLRTaken.end() == digLRTaken.find((m_N - 1) - (x - y));
	}
	void Add(int x, int y) {
		horiTaken.insert(y);
		vertTaken.insert(x);
		digRLTaken.insert(x + y);
		digLRTaken.insert((m_N - 1) - (x - y));
	}
	void Erase(int x, int y) {
		horiTaken.erase(y);
		vertTaken.erase(x);
		digRLTaken.erase(x + y);
		digLRTaken.erase((m_N - 1) - (x - y));
	}
private:
	int m_N = 0;
	unordered_set<int> horiTaken, vertTaken, digRLTaken, digLRTaken;
};

deque<int> Solution(int n) {
	Board board(n);
	deque<int> queenIdxs;	

	int x = 0;
	while (queenIdxs.size() < n) {
		for (; x < n; ++x) {
			int y = queenIdxs.size();
			if (!board.CanPlace(x, y))
				continue;
			board.Add(x, y);
			queenIdxs.push_back(x); // store where queen places for each row
			x = 0;
			break;
		}

		if (x == n) { // if not found, go back and try next one
			if (queenIdxs.empty())
				return queenIdxs; // cannot solve
			board.Erase(queenIdxs.back(), queenIdxs.size() - 1); // remove it from the board
			x = queenIdxs.back() + 1; // try next one
			queenIdxs.pop_back(); // go back
		}
	}

	return queenIdxs;
}

int main()
{
	constexpr int N = 4;
	auto result = Solution(N);
	while (!result.empty()) {
		for (int i = 0; i < N; ++i)
			cout << (result.front() == i ? "Q " : "- ");
		cout << endl;
		result.pop_front();
	}
}

