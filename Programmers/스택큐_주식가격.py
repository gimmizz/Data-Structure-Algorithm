def solution(prices):
    answer = [0 for i in range(len(prices))]

    for i in range(len(prices) - 1):
        current = prices[i]
        count = 0
        for j in range(i + 1, len(prices)):
            count += 1
            if current > prices[j]:
                break;
        answer[i] = count

    return answer

# 이전풀이
# def solution(prices):
#     answer = []
#
#     for i in range(len(prices)):
#       index = prices[i]
#       # print("index:", index)
#       temp = 0
#       for j in range(i+1,len(prices)):
#         temp += 1
#         # print(j)
#         if prices[j] < index :
#           break;
#       answer.append(temp)
#     return answer