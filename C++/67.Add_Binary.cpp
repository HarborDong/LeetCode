class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length(), j = b.length();
        int carry = 0, size = 0;
        string ret;
        
        if(a.length() == 0) return b;
        if(b.length() == 0) return a;
        if(j > i) ret = b , size = j; else ret = a, size = i;
        size--; i--; j--;
        
        while(size >= 0 || carry != 0) {
            if(i >= 0 && j >= 0) {                
                ret[size] = a[i] + b[j] - '0' + carry; 
            } else if(i >= 0 && j < 0) {
                ret[size] = a[i] + carry;             
            } else if(j >= 0 && i < 0) {
                ret[size] = b[j] + carry; 
            } else if(carry != 0 && size == -1) {
                ret.insert(ret.begin(), '1');
            }
            if(size >= 0 && ret[size] > '1') {
                ret[size] -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            size--; i--; j--;
        }

        return ret;
    }
};
