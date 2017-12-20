class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = 0, offset = 0, end = nums.size() - 2;
       /* method 1
        for(; start < end; start++) {
            if(nums[start] + start > next) {
                next = nums[start] + start;
            } else {
               if(start == next) return false;
            }
            //cout << next << endl;
            if(next >= end) {
                return true;
            }
        }
        method 2*/ 
        for(; end >= 0; end--) {
            if(nums[end] == 0) {
                offset = 1;
                next = end - 1;
                while(next >= 0) {
                    if(nums[next] > offset){
                        end = next;
                        break;
                    } else {
                        next--, offset++;
                    }
                }
                if(next < 0) return false;
            }
        }
        return true;
    }
};
