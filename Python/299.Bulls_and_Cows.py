class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        secret_dict = {'0':0,'1':0, '2':0,'3':0,'4':0,'5':0,'6':0,'7':0, '8':0,'9':0}
        guess_dict = {'0':0,'1':0, '2':0,'3':0,'4':0,'5':0,'6':0,'7':0, '8':0,'9':0}
        numA, numB = 0, 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                numA += 1
            else:
                secret_dict[secret[i]] += 1
                guess_dict[guess[i]] += 1
        
        for i in range(10):
            numB += min(secret_dict[str(i)], guess_dict[str(i)])
        
        return str(numA) + 'A' + str(numB) + 'B'
