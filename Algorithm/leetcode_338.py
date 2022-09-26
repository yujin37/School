#dynamic programming
class Solution:
    def countBits(self, n: int) -> List[int]:
        bits_array=[0]*(n+1)
        
        if n==0:
            bits_array[n]=0
        elif n==1:
            bits_array[n]=1
        else:
            bits_array[0]=0
            bits_array[1]=1
            for i in range(n+1):
                if i==0 or i==1:
                    continue
                if i&1==1:
                    bits_array[i]=bits_array[i>>1]+1
                else:
                    bits_array[i]=bits_array[i>>1]

        return bits_array
            
                
                
                
        
