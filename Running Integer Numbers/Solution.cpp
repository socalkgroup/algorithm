#include <vector>
#include <queue>
#include <functional>

using namespace std;

class RunningIntegers {
    public:
        priority_queue<int> lowNumbers;
        priority_queue<int, vector<int>, greater<int>> highNumbers;

        void AddNumber(int n) {
            highNumbers.push(n);
            lowNumbers.push(highNumbers.top());
            highNumbers.pop();

            if(lowNumbers.size() > highNumbers.size()) {
                highNumbers.push(lowNumbers.top());
                highNumbers.pop();
            }
        }

        double GetMedianNumber() {
            if ((lowNumbers.size() + highNumbers.size()) %2 == 1) {
                return highNumbers.top();
            }

            return (lowNumbers.top() + highNumbers.top())/2;
        }
};