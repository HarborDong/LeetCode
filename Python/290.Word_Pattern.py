class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        pattern_length = len(pattern)
        words = s.split();
        word_length = len(words)
        match_word = {}
        match_ch = {}
        if pattern_length != word_length:
            return False
        else:
            for i in range(word_length):
                ch, word = pattern[i], words[i]
                if ch in match_word:
                    if match_word[ch] != word:
                        return False
                else:
                    match_word[ch] = word
                    
                if word in match_ch:
                    if match_ch[word] != ch:
                        return False
                else:
                    match_ch[word] = ch
        
        return True
