import math

def solution(progresses, speeds):
    answer = []
    time_left = []
    for progress, speed in list(zip(progresses, speeds)):
        time_left.append(math.ceil((100-progress)/speed))
    
    cnt = 1
    max_time = time_left[0]
    for i in range(len(time_left)-1):
        if max_time >=time_left[i+1]:
            cnt += 1
        else:
            answer.append(cnt)
            max_time = time_left[i+1]
            cnt = 1
      
    answer.append(cnt)
    
    return answer