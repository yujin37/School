class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        bottles=numBottles
        while True:
            
            temp=numBottles//numExchange
            bottles+=temp
            numBottles=temp+(numBottles%numExchange)
            if numBottles<numExchange or numBottles==0:
                break
        return bottles