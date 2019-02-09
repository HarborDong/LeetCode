class Solution:
    def twoSum(self, numbers: 'List[int]', target: 'int') -> 'List[int]':
        l_index, r_index = 0,  len(numbers) - 1
        result = []
        while l_index < r_index:
            if numbers[l_index] + numbers[r_index] == target:
                result.append(l_index + 1)
                result.append(r_index + 1)
                break
            elif numbers[l_index] + numbers[r_index] < target:
                l_index += 1
            else:
                r_index -= 1
        
        return None if not len(result) else result
        """
        l_index, r_index = 0,  len(numbers) - 1
        while l_index < r_index:
            if numbers[l_index] + numbers[r_index] == target:
                return [l_index+1, r_index+1]
            elif numbers[l_index] + numbers[r_index] < target:
                l_index += 1
            else:
                r_index -= 1
        """
  
