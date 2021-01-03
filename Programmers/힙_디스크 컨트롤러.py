
def solution(jobs):

    time = 0
    jobs.sort()
    work_times = []
    while jobs:
        if time < jobs[0][0] :
            time = jobs[0][0]
        temp = list(filter(lambda x: x[0] <= time, jobs))
        temp.sort(key = lambda x : x[1])
        # print(temp)

        select = temp[0]
        # print(select)
        time += select[1]
        work_times.append(time-select[0])
        jobs.remove(select)

    return int(sum(work_times) / len(work_times))