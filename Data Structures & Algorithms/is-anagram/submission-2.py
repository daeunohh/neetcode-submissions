# Time: N, Space: 1
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        letters = dict([])
        for i in range(len(s)):
            letters[s[i]] = letters.get(s[i], 0) + 1
            letters[t[i]] = letters.get(t[i], 0) - 1
        
        # print(letters)
        
        for letter in letters:
            if letters[letter] != 0:
                return False

        return True   
        