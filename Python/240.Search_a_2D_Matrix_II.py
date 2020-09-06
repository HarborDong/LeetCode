class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        
        up_row, down_row = 0, len(matrix) - 1
        left_col, right_col = 0, len(matrix[0]) - 1
        while (up_row <= down_row and left_col <= right_col):
            left, right = up_row, down_row
            while left <= right:
                middle = (left + right)//2
                if matrix[middle][left_col] == target:
                    return True
                elif matrix[middle][left_col] < target:
                    left = middle + 1
                else:
                    right = middle - 1

                if right >= up_row:
                    down_row = right
                else:
                    return False

            left, right = up_row, down_row
            while left <= right:
                middle = (left + right)//2
                if matrix[middle][right_col] == target:
                    return True
                elif matrix[middle][right_col] < target:
                    left = middle + 1
                else:
                    right = middle -1

            if left <= down_row:
                up_row = left
            else:
                return False

            left, right = left_col, right_col
            while left <= right:
                middle = (left + right)//2
                if matrix[up_row][middle] == target:
                    return True
                elif matrix[up_row][middle] < target:
                    left = middle + 1
                else:
                    right = middle -1

            if right >= left_col:
                right_col = right
            else:
                return False

            left, right = left_col, right_col
            while left <= right:
                middle = (left + right)//2
                if matrix[down_row][middle] == target:
                    return True
                elif matrix[down_row][middle] < target:
                    left = middle + 1
                else:
                    right = middle - 1

            if left <= right_col:
                left_col = left
            else:
                return False
            
        return False
        
        
        
            
