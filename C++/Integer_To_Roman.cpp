/*
 * 罗马数字共有7个，即Ⅰ（1）、Ⅴ（5）、Ⅹ（10）、Ⅼ（50）、Ⅽ（100）、Ⅾ（500）和Ⅿ（1000）。按照下述的规则可以表示任意正整数。需要
 * 注意的是罗马数字中没有“0”，与进位制无关。一般认为罗马数字只用来记数，而不作演算。
 * 重复数次：一个罗马数字重复几次，就表示这个数的几倍。
 *
 *  右加左减：
 *      在较大的罗马数字的右边记上较小的罗马数字，表示大数字加小数字。
 *      在较大的罗马数字的左边记上较小的罗马数字，表示大数字减小数字。
 *      左减的数字有限制，仅限于I、X、C。比如45不可以写成VL，只能是XLV
 *      但是，左减时不可跨越一个位值。比如，99不可以用IC（ 100 − 1 {\displaystyle 100-1} 100-1）表示，
 *      而是用XCIX（ [ 100 − 10 ] + [ 10 − 1 ] {\displaystyle [100-10]+[10-1]} [100-10]+[10-1]）表示。
 *      （等同于阿拉伯数字每位数字分别表示。）
 *      左减数字必须为一位，比如8写成VIII，而非IIX。
 *      右加数字不可连续超过三位，比如14写成XIV，而非XIIII。（见下方“数码限制”一项。）
 *
 *  加线乘千：
 *      在罗马数字的上方加上一条横线或者加上下标的Ⅿ，表示将这个数乘以1000，即是原数的1000倍。
 *      同理，如果上方有两条横线，即是原数的1000000（ 1000 2 {\displaystyle 1000^{2}} 1000^{{2}}）倍。
 *
 *  数码限制：
 *      同一数码最多只能连续出现三次，如40不可表示为XXXX，而要表示为XL。
 */

class Solution {
public:
    string intToRoman(int num) {
        int continue_number = 0, high_number = 0, i = 0;
        string res = '\0';
        while(num) {
            i++;
            printf("str %s\n", res);
            if(num >= 1000) {
                num -= 1000;
                res += 'M';
                continue;
            }
            if(num >= 500) {
                num -= 500;
                res += 'D';
                high_number = 1;
                continue;
            }
            if(num >= 100) {
                num -= 100;
                res += 'C';
                continue_number++;
                continue;
            }
            if(continue_number == 4) {
                if(high_number == 1) {
                    res.replace(i - 5, 5 ,"CM");
                } else {
                    res.replace(i - 4, 4, "CD");
                }
                high_number = 0;
                continue_number = 0;
            }
            if(num >= 50) {
                num -= 50;
                res += 'L';
                high_number = 1;
                continue;
            }
            if(num >= 10) {
                num -= 10;
                res += 'X';
                continue_number++;
                continue;
            }
            if(continue_number == 4) {
                if(high_number == 1) {
                    res.replace(i - 5, 5 ,"XC");
                } else {
                    res.replace(i - 4, 4, "XL");
                }
                high_number = 0;
                continue_number = 0;
            }
            if(num >= 5) {
                num -= 5;
                res += 'V';
                high_number = 1;
                continue;
            }
            if(num >= 1) {
                num -= 1;
                res += 'I';
                continue_number++;

                continue;
            }
            if(continue_number == 4) {
                if(high_number == 1) {
                    res.replace(i - 5, 5 ,"IX");
                } else {
                    res.replace(i - 4, 4, "IV");
                }
                high_number = 0;
                continue_number = 0;
            }
        }
        return res;
    }
};
