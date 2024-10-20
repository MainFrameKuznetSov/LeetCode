class Solution:
    def stringSequence(self, target: str) -> List[str]:
        ans=[]
        temp=""
        for ind in range(len(target)):
            for i in range(ord('a'),ord(target[ind])+1):
                temp+=chr(i)
                ans.append(temp)
                temp=temp[:-1]
            temp+=target[ind]
        return ans