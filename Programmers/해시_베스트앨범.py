def solution(genres, plays):
    answer = []
    genre_play = list(zip(genres, plays))
    album = {}
    
    for genre, play in genre_play:
        if genre in album:
            album[genre] += play
        else:
            album[genre] = play
            
    for genre, _ in sorted(album.items(), key = lambda x : x[1], reverse = True):
        
        # genre_play를 돌면서, 해당 genre 색출
        # play 순으로 sort, index를 저장
        temp = []
        for index, obj in enumerate(genre_play):
            if obj[0] == genre:
                temp.append((obj[1], index))
        
        temp.sort(key = lambda x : x[0], reverse = True)
        # print(temp)
        answer += [x[1] for x in temp[0:2]]
                
    return answer