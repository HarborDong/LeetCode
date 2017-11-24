class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int>::iterator num1, num2, num3, num4;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.size() < 4)
            return res;
        num1 = nums.begin();
        while(num1 < nums.end() - 3) {
            num2 = num1 + 1;
            //the sum of the most four min number is bigger than target, break loop
            if(*num1 + *num2 + *(num2 + 1) + *(num2 + 2) > target) break;
            //the sum of the current num add the most three max num is less than target, continue loop
            if(*num1 + *(nums.end() -1) + *(nums.end() -2) + *(nums.end() -3) < target) {
                num1++; continue;
            }
            while(num2 < nums.end() - 2) {
                num3 = num2 + 1; num4 = nums.end() - 1;
                if(*num1 + *num2 + *num3 + *(num3 + 1) > target) break;
                if(*num1 + *num2 + *num4 + *(num4-1) < target) {
                    num2++; continue;
                } 

                while(num3 < num4) {
                    if(*num1 + *num2 + *num3 + *num4 == target) {
                        vector<int> element;
                        element.push_back(*num1);
                        element.push_back(*num2);
                        element.push_back(*num3);
                        element.push_back(*num4);
                        res.push_back(element);
                        while(num3 < num4 && *num3 == *(num3 + 1)) num3++;
                        while(num3 < num4 && *num4 == *(num4 - 1)) num4--;
                        num3++;num4--;
                    }
                    else if (*num1 + *num2 + *num3 + *num4 < target) {
                        while(num3 < num4 && *num3 == *(num3 + 1)) num3++;
                        num3++;
                    } else {
                        while(num3 < num4 && *num4 == *(num4 - 1)) num4--;
                        num4--;
                    }
                }
            //skip same num2
            while((num2 < nums.end() -2) && *num2 == *(num2 + 1)) num2++;
                num2++;
            }
            //skip same num1
        while((num1 < nums.end() -3) && *num1 == *(num1 + 1)) num1++;
            num1++;
        }
        return res;
    }
};
