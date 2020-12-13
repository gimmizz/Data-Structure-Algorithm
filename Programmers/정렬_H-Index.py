import re 

def solution(citations):
    answer = 0
    
    citations.sort()

    for h in range(citations[-1], -1, -1):
        if h in citations:
            cursor = citations.index(h) 
        else:
            for i in range(len(citations)):
                if citations[i] >= h:
                    cursor = i
                    break;
                
        if len(citations) - cursor >= h :
            answer = h
            break;
    
    return answer