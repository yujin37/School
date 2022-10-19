#1382. Balance a Binary Search Tree <level. medium>
# 거의 답을 보지 않고 풀어서 효율성 낮음.(트리노드 생성방법만 참고. 속도 느림)- 정렬 부분을 개선하면 속도 나아질 수 있음.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sorting(self, root,num):
        num.append(root.val)
        if root.left != None:
            self.sorting(root.left,num)
        if root.right != None:
            self.sorting(root.right,num)
        num.sort()
        return num
      
    def balance(self,result1):
        if not result1:
            return None
        mid=len(result1)//2
        root=TreeNode(result1[mid])
        root.left=self.balance(result1[:mid])
        root.right=self.balance(result1[mid+1:])
        return root
        
    def balanceBST(self, root: TreeNode) -> TreeNode:
        num=[]
        result1=self.sorting(root,num)
        result2=self.balance(result1)
        return result2
