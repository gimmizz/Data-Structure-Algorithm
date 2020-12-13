def solution(clothes):
    answer = 1
    
    cloth = dict()
    for i in clothes:
        if i[1] in cloth:
            cloth[i[1]] += [i[0]]
        else:
            cloth[i[1]] = [i[0]]
            
    print(cloth)
            
    for cloth_type in cloth:
        answer *= (len(cloth[cloth_type])+1)
    
    return answer-1