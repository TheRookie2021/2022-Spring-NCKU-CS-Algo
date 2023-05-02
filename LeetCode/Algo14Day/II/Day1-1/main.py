from typing import List 
class Solution:

    def binarySearch(self,nums: List[int],front,end, target: int)->int:
        if(len(nums)==0):
            return -1
    
        while(front<=end): # don't forget "<=", instead of "<", or the special case with one element will fail
            mid=int((end+front)/2)
            if(nums[mid]>target):
                end=mid-1
            elif(nums[mid]<target):
                front=mid+1
            else:
                return mid
            
        return -1
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if(len(nums)==0):
            return[-1,-1]
        if(len(nums)==1):
            if(nums[0]==target):
                return[0,0]
            else:        
                return[-1,-1]

        front=0
        end=len(nums)-1
        first=-1
        second=-1
        mid=self.binarySearch(nums,front,end,target)
        if(mid==-1):
            return[-1,-1]

        flag_left=mid
        flag_right=mid
        
        while(flag_left!=-1 or flag_right!=-1 ):
            
            if(flag_left!=-1):
                first=flag_left
                flag_left= self.binarySearch(nums,front,flag_left-1,target)

            if(flag_right!=-1):
                second=flag_right
                flag_right= self.binarySearch(nums,flag_right+1,end,target)
           
        return [first,second]
#-----------------------------------------------------------------------------
S=Solution()
nums = [5,7,7,8,8,10]
# nums = [8,8] 
target = 8
for i in enumerate(nums):
    print(i)
print(S.binarySearch(nums,0,len(nums)-1,target))
print(S.searchRange(nums,target))

