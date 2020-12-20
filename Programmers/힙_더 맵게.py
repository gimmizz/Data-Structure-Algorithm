# PriorityQueue 모듈모다, 스레드 안전성을 보장하지 않는 heapq가 훨씬 빠르다!

import heapq


def solution(scoville, K):
    answer = 0

    heapq.heapify(scoville)

    while scoville[0] < K and len(scoville) > 1:
        min_one = heapq.heappop(scoville)
        min_two = heapq.heappop(scoville)
        merged = min_one + min_two * 2

        heapq.heappush(scoville, merged)
        answer += 1

        # print(scoville)

    if len(scoville) == 1 and scoville[0] < K:
        answer = -1

    return answer

# Max Heap 활용 예시
# import heapq

# nums = [4, 1, 7, 3, 8, 5]
# heap = []

# for num in nums:
#   heapq.heappush(heap, (-num, num))  # (우선 순위, 값)

# print(heap)

# while heap:
#   print(heapq.heappop(heap)[1])  # index 1