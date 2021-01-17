

priceOfJeans_count = 2
priceOfJeans = [2, 3]

priceOfShoes_count = 1
priceOfShoes = [4]
priceOfSkirts_count = 1
priceOfSkirts = [2]
priceOfTops_count= 3
priceOfTops = [1, 2, 3]
budgeted = 10
ans = 0
for i in range(priceOfJeans_count):
    cur = budgeted
    if priceOfJeans[i] >= cur:
        continue
    else:
        cur -= priceOfJeans[i]

    for j in range(priceOfShoes_count):
        cur2 = cur
        if priceOfShoes[j] >= cur2:
            continue
        else:
            cur2 -= priceOfShoes[j]

        for k in range(priceOfSkirts_count):
            cur3 = cur2
            if priceOfSkirts[k] >= cur3:
                continue
            else:
                cur3 -= priceOfSkirts[k]

            for l in range(priceOfTops_count):
                cur4 = cur3
                if priceOfTops[l] >cur4:
                    continue
                else:

                    ans += 1
print(ans)