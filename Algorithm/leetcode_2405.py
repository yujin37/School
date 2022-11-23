class Solution:
    def partitionString(self, s: str) -> int:
        result=[]
        temp=''
        for i in s:
            if i in temp:
                result.append(temp)
                temp=''
            temp+=i
        if len(temp)!=0:
            result.append(temp)
        return len(result)