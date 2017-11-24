class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>::iterator num1, num2, num3;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3)
            return res;

        for(num1 = nums.begin(); num1 < nums.end() - 2; num1++) {
            if(*num1 > 0) return res;
            num2 = num1 + 1; num3 = nums.end() - 1;
            while(num2 < num3) {
                if(*num2 + *num3 == -*num1) {
                    vector<int> res_element;
                    res_element.push_back(*num1);
                    res_element.push_back(*num2);
                    res_element.push_back(*num3);
                    res.push_back(res_element);
                    while(num2 < num3 && *num2 == *(num2 + 1)) num2++;
                    while(num2 < num3 && *num3 == *(num3 - 1)) num3--;
                    num2++; num3--;
                } else if (*num2 + *num3 < -*num1) {
                    num2++;
                } else {
                    num3--;
                }
            }
            while((num1 < nums.end() - 1) && (*num1 == *(num1 + 1))) num1++;
        }
        return res;
    }
};
