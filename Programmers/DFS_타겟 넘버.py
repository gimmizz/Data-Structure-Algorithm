def dfs(nums,i,n,t):
    ret=0
    if i==len(nums):
        if n==t:
            return 1
        else:
            return 0
    ret+=dfs(nums,i+1,n+nums[i],t)
    ret+=dfs(nums,i+1,n-nums[i],t)
    return ret

def solution(numbers, target):
    answer = dfs(numbers,0,0,target)
    return answer