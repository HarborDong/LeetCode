class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::reverse_iterator iter = digits.rbegin();
        int carry = 1;
        
        if(digits.size() == 0) {
            digits.push_back(1); 
            return digits;
        }
        while(carry || iter != digits.rend()) {
            if(iter != digits.rend()) {
                *iter = *iter + carry;
                carry = *iter / 10;
                *iter = *iter % 10;
            }

            if(carry && iter == digits.rend()) {
                digits.insert(digits.begin(), carry);
                carry = 0;
                break;
            }
            iter++;
        }
        return digits;
    }
};
