class Solution:
    def __init__(self):
        self.subset = []
    def explore(self,k,nums,start, selected):
        if k==0:
            s=[]
            for i in range(len(selected)):
                if selected[i]:
                    s.append(nums[i])
            self.subset.append(s)
            return
        for i in range(start, len(selected)):
            if not selected[i]:
                selected[i]=True
                self.explore(k-1, nums, i+1, selected)
                selected[i]=False
        return
    def subsets(self, nums: List[int])-> List[List[int]]:
        result=[]
        selected=[False]*len(nums)
        for k in range(len(nums)+1):
            self.subset=[]
            self.explore(k,nums, 0, selected)
            result = result + self.subset
        return result