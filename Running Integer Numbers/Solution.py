import heapq

class MedianFinder:
    def __init__(self):
        self.maxheap = [] 
        self.minheap = [] 

    def addNum(self,num):

        
        heapq.heappush(self.minheap,num)
        heapq.heappush(self.maxheap,-heapq.heappop(self.minheap))
        
        if len(self.maxheap)  > len(self.minheap):
            heapq.heappush(self.minheap,-heapq.heappop(self.maxheap))

                

    def findMedian(self):
        if len(self.maxheap) == len(self.minheap):
            return (-self.maxheap[0] + self.minheap[0])/2.0
        elif len(self.maxheap) > len(self.minheap): 
            return -self.maxheap[0]
        else:
            return self.minheap[0]
