from itertools  import combinations
import collections
def solution(info, query):
    answer = []
    lists = collections.defaultdict(list)
    for x in info:
        print(info)
        infos = x.split(' ')[0:5]
        info_key = infos[:-1]
        info_val = int(infos[-1])
        for size in range(0,5):
            for c in combinations(info_key,size):
                tmp_key = ''.join(c)
                lists[tmp_key].append(info_val)

    for key in lists.keys():
        lists[key].sort()

    for x in query:
        x = x.split(' ')
        query_score = int(x[-1])
        x = x[:-1]
        while x.__contains__('and'):
            x.remove('and')
        while x.__contains__('-'):
            x.remove('-')
        x = ''.join(x)

        if x not in lists:
            answer.append(0)
            continue

        scores = lists[x]
        left = 0
        right = len(scores)
        while left < right:
            mid = (left+right) // 2
            if scores[mid] >= query_score:
                right = mid
            else:
                left = mid+1
        answer.append(len(scores) - left)

    return answer


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    info = {"java backend junior pizza 150",
            "python frontend senior chicken 210",
            "python frontend senior chicken 150",
            "cpp backend senior pizza 260",
            "java backend junior chicken 80",
            "python backend senior chicken 50"};
    query = {"java and backend and junior and pizza 100",
             "python and frontend and senior and chicken 200",
             "cpp and - and senior and pizza 250",
             "- and backend and senior and - 150",
             "- and - and - and chicken 100",
             "- and - and - and - 150"};
    print(info)
    answer = solution(info,query)
    print(answer)