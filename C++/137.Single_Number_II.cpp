/**
 * 位操作。不管非孤异元素重复多少次，这是通用做法。
 * 对于右数第i位，如果孤异元素该位为0，则该位为1的元素总数为3的整数倍。
 * 如果孤异元素该位为1，则该位为1的元素总数不为3的整数倍（也就是余1）。
 * 换句话说，如果第i位为1的元素总数不为3的整数倍，则孤异数的第i位为1，否则为0.
 * 我没想出来查baidu知道.好shame.虽然知道用unordered_map去做,但是空间不是O(1)
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        int mask = 1;
        
        for(int i = 0; i < 32; i++)
        {
            int count = 0;
            mask = 1 << i;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] & mask)
                    count++;
            }
            if(count % 3 == 1)
                ret |= mask;
        }
        return ret;
    }
};
