# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        
        def test(root):
            print(root.val) #이게 왼쪽 끝나면 오른쪽으로 가야하는데.
            if root.left==None and root.right == None: #자기자신 혹은 리프일때
                #return False
                if root.val==0:
                    #리프토드 false
                    return False
                if root.val==1:
                    #리프노드 true
                    return True
            if root.val==2:
                #리프노드가 아니라면 or
                return test(root.left) or test(root.right)
            if root.val==3:
                #리프노드가 아니라면 and
                return test(root.left) and test(root.right)
        
        return test(root)
        #test(root.left.val)
        #test(root.right.val)
        #print(root.left.val)
                
               