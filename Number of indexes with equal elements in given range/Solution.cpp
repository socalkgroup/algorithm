// CPP program to count the number of indexes
// in range L R such that Ai=Ai+1
#include <iostream>
using namespace std;
const int N = 1000;
  
// array to store count of index from 0 to
// i that obey condition
int prefixans[N];
  
// precomputing prefixans[] array
int countIndex(int a[], int n)
{
    // traverse to compute the prefixans[] array
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1])
            prefixans[i] = 1;
  
        if (i != 0)
            prefixans[i] += prefixans[i - 1];
    }
}
  
// fucntion that answers every query in O(1)
int answer_query(int l, int r)
{
    if (l == 0)
        return prefixans[r - 1];
    else
        return prefixans[r - 1] - prefixans[l - 1];
}
  
// Driver Code
int main()
{
    int a[] = { 1, 2, 2, 2, 3, 3, 4, 4, 4 };
    int n = sizeof(a) / sizeof(a[0]);
  
    // pre-computation
    countIndex(a, n);
  
    int L, R;
  
    // 1-st query
    L = 1;
    R = 8;
  
    cout << answer_query(L, R) << endl;
  
    // 2nd query
    L = 0;
    R = 4;
    cout << answer_query(L, R) << endl;
    return 0;
}
