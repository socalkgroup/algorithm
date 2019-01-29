#include <vector>
#include <iostream>

using namespace std;

bool canJump(vector<int>& nums) {
    
    int size = nums.size();
    int last = size - 1;
    for(int i = size - 1; i >= 0; --i) {
        
        if(i + nums[i] >= last) {
            last = i;
        }
    }
    
    return last == 0;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums) ? "true" : "false" << endl;
    return 0;
}