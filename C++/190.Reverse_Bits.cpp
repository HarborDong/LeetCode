// method1
char dict[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        char *temp = (char *) &n;
        char ch = 0, ch1 = 0;
        uint32_t i = 0;
        ch = temp[0]; temp[0] = temp[3]; temp[3] = ch;
        ch = temp[2]; temp[2] = temp[1]; temp[1] = ch;
        
        for (i = 0; i < sizeof(uint32_t); i++) {
            ch = dict[temp[i] & 0x0f];
            ch1 = dict[(temp[i] & 0xf0) >> 4];
            temp[i] = (ch << 4) | ch1;
        }
        i = *((uint32_t *)temp);
        return i;
    }
};

// method2
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0x0000ffff) << 16) | ((n & 0xffff0000) >> 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
