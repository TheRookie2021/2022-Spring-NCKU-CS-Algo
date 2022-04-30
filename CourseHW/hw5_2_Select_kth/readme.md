# title
    小邱是一個黑暗調酒師，為了調出更多讓人一喝就醉的調酒，他下定決心要躲到深山閉關修練。他夜以繼日不間斷第一直調酒。
    直到有一天，小邱忽然發現自己調了太多杯了跟本喝不完，所以他決定只喝杯數第 K 多的那一種調酒。
    請你幫小邱找出他該喝哪一種調酒。
    另外，如果有2種調酒杯數相同，則名稱字典序較小的調酒排名會比較前面。
    --- 
    English version:
    Chiu is a dark bartender. In order to make more cocktails that make people drunk, he is determined to hide in the mountains and practice retreat.
    Until one day, he suddenly realized that he had made too many glasses of cocktail and couldn't finish it, so he decides to drink only the K most numbered cocktail.
    Please help him find out which cocktail he should drink.
    Also, if 2 cocktails have the same amount, the cocktail with the lower lexicographical order will be ranked higher.

# input/output
    第一行輸入二個整數 N, K ，代表總共有 N 杯調酒以及小邱只喝第 K 多的調酒。
    接下來有 N 行，每行皆有一個字串 S_i(1 \leq i \leq N)，代表第i杯調酒的名稱為 S_i
    --- 
    First line will be two integers N and K, which means there are N glasses of cocktail and he only drink the K most numbered cocktail.
    For the next line, each line will have a string N and K, which means the name of the ith glass of cocktail.
    請輸出小邱會喝哪一種調酒
    Please print which cocktail he would drink.

# pitfalls
- bug: Also, if 2 cocktails have the same amount, the cocktail with the lower lexicographical order will be ranked higher.
- detail: string comparison vs char comparison
- tech: sort with custom compare function, map structure is internally sorted, and its find() is fit for the counting problem
- 