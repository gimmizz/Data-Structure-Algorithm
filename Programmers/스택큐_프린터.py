def solution(priorities, location):
    ans = []
    seq = [i for i in range(len(priorities))]
    
    while priorities:
        current = priorities.pop(0)
        s_current = seq.pop(0)
        if not priorities:
            ans.append(s_current)
        else:
            if current < max(priorities):
                priorities.append(current)
                seq.append(s_current)
            else:
                ans.append(s_current)
                
    answer = ans.index(location) + 1
    
    return answer