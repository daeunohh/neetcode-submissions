# Time: N, Space: N
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        letters = dict([])
        for letter in s:
            if letter in letters:
                letters[letter] += 1
            else:
                letters[letter] = 1

        # print(letters)
        
        for letter in t:
            if letter in letters:
                if letters[letter] < 1:
                    return False
                else :
                    letters[letter] -= 1
            else:
                return False
        
        return True   
        