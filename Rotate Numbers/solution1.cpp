#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& in, unsigned beginIdx, unsigned const n)
{
    // swap end n elements into where beginIdx is
    for (int i = in.size() - n; i < in.size(); ++i)
    {
        int tmp = in[beginIdx];
        in[beginIdx++] = in[i];
        in[i] = tmp;
    }
}

bool Solution(vector<int>& in, unsigned const k)
{
    if (k > in.size() || in.empty())
        return false;

    if (k == in.size())
        return true;

    for (int i = 0; i < in.size() - k;) {
        swap(in, i, k);
        i += k;
    }

    return true;
}

int main()
{
    vector<int> input{ 1, 2, 3, 4, 5, 6 };
    unsigned k = 2;

    if (Solution(input, k)) {
        for (auto& v : input) {
            cout << v << ", ";
        }
        cout << endl;
    }
    else
        cerr << "Error was found. Aborted." << endl;
}