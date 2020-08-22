class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        """
        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0
        status transferation function, mq(x,y) represents that the size of the square sub-matrix 
        where (x,y) is the rightmost and bottommost entry in sub-matrix.
        mq(x,y) = min(mq(x-1,y), mq(x,y-1), mq(x-1, y-1))
        """
        width = len(matrix)
        length = len(matrix[0]) if width else 0
        if length == 0:
            return 0
        max_sq = 0
        mq = [[0 for _ in range(length)] for _ in range(width)]
        
        for i in range(length):
            mq[0][i] = 1 if matrix[0][i] == '1'else 0         
        max_sq = max(mq[0])

        for i in range(1,width):
            mq[i][0] = 1 if matrix[i][0] == '1' else 0
            if mq[i][0] == 1: max_sq = 1

        for i in range(1, length):
            for j in range(1, width):
                mq[j][i] = min(mq[j-1][i], mq[j][i-1], mq[j-1][i-1]) + 1 if matrix[j][i] == '1' else 0
                if mq[j][i] > max_sq:
                    max_sq = mq[j][i]
       
        return max_sq ** 2
