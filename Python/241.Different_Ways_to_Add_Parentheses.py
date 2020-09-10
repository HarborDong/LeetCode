class Solution:
    def calculate(self, left: int, right: int, op: str) -> int:
        if op == '+':
            return left + right
        elif op == '-':
            return left - right
        elif op == '*':
            return left * right

    def computeHelper(self, nums:List[int], ops:List[str], res:List[int]):
        length = len(nums)
        if not ops and length == 1:
            res.append(nums[0])
            return
        # the length of nums == the lenght of ops + 1
        for i in range(length - 1):
            left = list(); right = list()
            op = ops[i]
            self.computeHelper(nums[0:i+1], ops[0:i], left)
            self.computeHelper(nums[i+1:], ops[i+1:], right)
            for m in range(len(left)):
                for n in range(len(right)):
                    res.append(self.calculate(left[m], right[n], op))
        
        
    def diffWaysToCompute(self, input: str) -> List[int]:
        num, op = 0, '+'
        
        self.nums = []
        self.ops = []
        self.res = []
        for i in range(len(input)):
            if input[i].isdigit():
                num = 10 * num + int(input[i])
            else: 
                op = input[i]
                self.nums.append(num)
                num = 0
                self.ops.append(op)
        
        self.nums.append(num)
        self.computeHelper(self.nums, self.ops, self.res)

        return self.res
