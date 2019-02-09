class Solution:
    def fractionToDecimal(self, numerator: 'int', denominator: 'int') -> 'str':
        result = ''
        index = 0
        if denominator == 0:
            return "NaN"
        
        if numerator * denominator < 0:
            result += '-';
        
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        quotient = numerator // denominator
        remainder = numerator % denominator
        
        result += str(quotient)
        if remainder:
            result += '.'
            index = len(str(result))
            
        remainder_dict = {}
        while remainder:
            if remainder in remainder_dict:
                break
            
            remainder_dict[remainder] = index
            index += 1
            
            quotient = remainder * 10 // denominator
            remainder = remainder * 10 % denominator
            result += str(quotient)
        
        if remainder:
            result = result[0: remainder_dict[remainder]] + '(' + \
                     result[remainder_dict[remainder]: ] + ')'
        
        return result
