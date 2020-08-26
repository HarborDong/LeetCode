class Solution:
    def calculate(self, s: str) -> int:
        tmp, ex_op, num = [], '+', 0
        s = s + '+'
        length = len(s)
        
        for i in range(length):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            elif s[i].isspace():
                pass
            else:
                if ex_op == '+':
                    tmp.append(num)
                elif ex_op == '-':
                    tmp.append(-num)
                elif ex_op == '*':
                    tmp.append(tmp.pop() * num)
                elif ex_op == '/':
                    ex_num = tmp.pop()
                    if ex_num < 0:
                        tmp.append(-((-ex_num) // num))
                    else:
                        tmp.append(ex_num // num)

                ex_op = s[i]
                num = 0
        
        return sum(tmp)
