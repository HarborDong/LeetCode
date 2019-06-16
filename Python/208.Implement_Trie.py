class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.key = False
        self.son = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self
        for ch in word:
            if ch not in node.son:
                node.son[ch] = Trie()
            node = node.son[ch]
        
        node.key = True
        return None

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self
        for ch in word:
            if ch not in node.son:
                return False
            node = node.son[ch]
        return node.key

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self
        for ch in prefix:
            if ch not in node.son:
                return False
            node = node.son[ch]
        return True
