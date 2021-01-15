from queue import Queue

def bfs(index, computers, visited):
    que = Queue()
    count = Queue()
    
    que.put(index)
    count.put(0)
    
    while que.empty()==False:
        cur = que.get()
        num = count.get()
        visited[cur] = True
        
        links = computers[cur]
        
        for i in range(len(links)):
            if links[i] == 1 and i != cur and visited[i] == False:
                que.put(i)
                count.put(num+1)
                
def solution(n, computers):
    answer = 0
    visited = [False for i in range(n)]
    
    for i in range(n):
        if visited[i] == False:
            bfs(i, computers, visited)
            answer += 1
    
    return answer