# quick select
    - 小邱是一個黑暗調酒師，最大的興趣就是把來到酒吧裡的客人灌倒。然而小邱的調酒非常奇怪，親手調製的 N 杯調酒之中，只有酒精濃度第 K 高的那杯才會讓客人喝醉。
    小邱的調酒都是由萊姆汁、糖漿、基酒三種元素所構成，而小邱所使用的基酒皆為濃度100\%的酒精。
    也就是說例如一杯調酒用了 20ml 的萊姆汁、20ml的糖漿以及60ml的基酒，則這杯調酒的濃度是60%。現在給出N杯調酒的材料配方，請你幫小邱找出是哪杯會讓客人醉倒。
    - English version:
    Chiu is a dark bartender. His greatest interest is to make the guests who come to the bar get drunk.
    However, his cocktail is very strange. Of the N glass of cocktail, only the glass with the K highest alcohol concentration will cause the guest to get drunk.
    His cocktails are all made from lime juice, syrup, and base liquor The base liquor he uses is 100% alcohol.
    That is, for instance, a glass of cocktail is made of 20ml lime juice, 20 ml syrup, 60ml base liliquor, then the concentration of this cocktail is 60\%.
    Giving the material recipe for N glasses of cocktail, please help him find out which cocktail gets the guest drunk.
===
## input/output
    - 第一行輸入兩個整數 N 和 K 代表總共有 N 杯調酒，以及濃度第 K 高的調酒會讓客人醉倒。
    接下來有 N 行，每行皆有三個整數 a, b, c 以及一個字串 s
    分別代表所使用的
    "萊姆汁、糖漿、基酒的量"，
    以及這杯調酒的名字。
    - First line will be two integers  N and K, which means there are  N glasses of cocktail and  the K highest alcohol concentration will cause the guest to get drunk.
    For the next N line, each line will have three integers a, b, c and a string s, which means the amount of lime juice, syrup, base liquor, and the name of the cocktail.
---
    - 請輸出會讓客人醉倒的那杯調酒的名字
    - Please print the name of the cocktail which gets the guest drunk.
    - 可以試試看quick select

===
# pitfalls
    - use randomize quick select to enhance the time complexity
    - RTE: be careful of the remainer % with random variable, it could be zero and lead to the "divided by zero" situation.  
