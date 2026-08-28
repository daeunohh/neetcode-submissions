class Solution:

    def encode(self, strs: List[str]) -> str:
        header = ""
        encoded = ""
        for s in strs:
            header += str(len(s)) + ","
            encoded += s
        return str(len(strs)) + "," + header + encoded


    def decode(self, s: str) -> List[str]:
        print(s)
        # Get len of strs
        i = 0
        len_strs = ""
        while(1):
            if i > len(s) - 1:
                break
            if s[i] == ",":
                i += 1
                break
            len_strs += s[i]
            i += 1
        len_strs = int(len_strs)
        print(len_strs, i)

        # get lens of each str
        lens = []
        n = ""
        cnt = 0
        while(i < len(s)):
            if s[i] == ',':
                lens.append(n)
                cnt += 1
                if cnt >= len_strs:
                    break
                n = ""
            else:
                n += s[i]
            i += 1
        i += 1
        print(lens, i)

        # get strings from s
        ret = []
        for l in lens:
            l = int(l)
            subs = ""
            for j in range(i, i+l):
                subs += s[j]
                # print(s[j])
            i += l
            ret.append(subs)
            # print(subs)

        return ret
