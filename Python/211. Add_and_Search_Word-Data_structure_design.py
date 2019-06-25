class node:
    def __init__(self):
        self.key = False
        self.child = {}
class WordDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = node()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        nd = self.root
        for ch in word:
            if ch not in nd.child:
                nd.child[ch] = node()
            nd = nd.child[ch]
        
        nd.key = True;        
        return None
        
    def DFSSearch(self, nd: node, word: str) -> bool:
        for i in range(len(word)):
            if not len(nd.child):
                return False
            if word[i] in nd.child:
                nd = nd.child[word[i]]
            elif word[i] != '.' and word[i] not in nd.child:
                return False
            if word[i] == '.':
                for ch in nd.child.keys():
                    newWord = ch + word[i+1:]
                    if self.DFSSearch(nd, newWord):
                        return True
                return False

        if nd.key: 
            return True
        else:
            return False
        
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.DFSSearch(self.root, word)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
