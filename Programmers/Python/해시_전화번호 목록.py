def solution(phone_book):

    answer = True

    for i in range(len(phone_book)):
      for j in range(len(phone_book)):
        if phone_book[j].startswith(phone_book[i]) and i != j:
          answer = False
          break
      if not(answer):
        break;
    return answer