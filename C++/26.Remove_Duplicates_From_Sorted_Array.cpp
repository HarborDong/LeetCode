class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator change_point = nums.begin(), head_point = nums.begin();
        while(head_point < nums.end()) {
            *change_point = *head_point;
            while(head_point + 1 < nums.end() && (*head_point == *(head_point + 1)) ) {
                    head_point++;
            }
            change_point++;
            head_point++;
        }
        if(change_point < nums.end())
            nums.erase(change_point , nums.end());
        return nums.size();
    }
};

