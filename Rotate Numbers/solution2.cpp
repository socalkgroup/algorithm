#include <iostream>
#include <vector>

using namespace std;

void juggle(vector<int>& input, int num, int current, int org, int rotateNum) {
    int next = (current + rotateNum) % input.size();
    int temp = input[next];
    input[next] = num;

    if (next == org) {
        return;
    } 

    juggle(input, temp, next, org, rotateNum);
}

void rotate(vector<int>& input, int rotateNum) {
    for(int i = 0 ;  i < rotateNum; i++) {
        juggle(input, input[i], i, i, rotateNum);
    }
}

int main()
{
    vector<int> input = { 1, 2, 3, 4, 5, 6 };
    rotate(input, 2);

    for (auto v : input) {
        cout << v << ", ";
    }
    
    return 0;
}