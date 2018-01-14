class Solution {
public:
    void IpAddressHelper(vector<string> &ret, string &s, string &addr, int start, int dotNum) {
        int addrlen = addr.length();
        if((s.length() - start) > (4 - dotNum) * 3) {
            return;
        }
        if(s.length() == start && dotNum < 4) return;
        if(dotNum == 4) {
            addr.pop_back();
            ret.push_back(addr);
        }
        if(s[start] != '0' ) {
            for(int j = 1; (j + start - 1) < s.length() && j < 4; j++) {
                if(stoi(s.substr(start, j)) < 256) {
                    addr += s.substr(start, j);
                    addr += '.';
                    IpAddressHelper(ret, s, addr, start + j, dotNum + 1);
                    addr.erase(addrlen, j + 1);
                 } else {
                    break;
                }
            }
        } else {
            addr += s.substr(start, 1); addr += '.';
            IpAddressHelper(ret, s, addr, start + 1, dotNum + 1);
            addr.erase(addrlen, 2);
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string addr;
        int start = 0, dotNum = 0;
        IpAddressHelper(ret, s, addr, 0, 0);
        return ret;
    }
};
