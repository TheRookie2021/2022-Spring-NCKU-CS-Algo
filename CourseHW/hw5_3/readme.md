# multiset vs set
    小邱是一個黑暗調酒師，在比了一大堆比賽之後，小邱終於從參賽選手進化到變成裁判長。
    這次比賽總共有N位選手，每一位選手會調1杯調酒，編號分別為1\sim N。
    裁判的部分則是每人負責評比M杯的調酒。
    第一位裁判負責編號1 \sim M的調酒，第二位裁判負責編號2 \sim M+1的調酒，...，第i為裁判負責編號i \sim i+M-1的調酒，因此共有N-M+1位裁判。
    由於小邱是個不公平的裁判，所以對調酒的評分方式很簡單，他根本不管好不好喝，酒精濃度越高則分數就越高。
    由於小邱覺得往年每次都是讓裁判選出第一名的那杯實在是太無聊又單調了，因此他決定擅自更改遊戲規則，改成讓每位裁判挑出分數第K低的那杯調酒。
    請你告訴小邱每位裁判分別會挑哪一杯調酒。
    ///
    English version:
    Chiu is a dark bartender. After a lot of competitions, he was finally promoted from player to chief referee of the competition.
    There are K players in this competition, Each contestant will make a glass of cocktail, numbered from 1\sim N.
    Please help him find out which cocktail each judge picks.
    Each judge is responsible for M glasses of cocktail.
    The first judge is responsible for judging the cocktails numbered 1 \sim M, the second judge is responsible for judging the cocktails numbered 2 \sim M+1, the ith judge is responsible for judging the cocktails numbered i \sim i+M-1, so there will be N-M+1 judges.
    Since Chiu is an unfair referee, the way to score cocktails is simple, he doesn't care whether it is good or not, the higher the alcohol concentration, the higher the score.
    Because he felt that it was too boring to have the judges pick the cocktail with the highest score every time, so he decided to change the rules of the game and let each judge pick the cocktail with the K lowest score.
    Please tell him which cocktail each judge will pick.

# input/output
    第一行輸入三個整數 N, M, K 代表總共有 N 杯調酒，每位裁判負責M杯調酒的評比，以及裁判會找出分數第K小的調酒。
    接下來有 N 行，每行皆有一個整數 X_i 
    代表第i杯調酒的濃度為X_i
    First line will be three integers N, M, K, which means there are N glasses of cocktail, each judge is responsible for M glasses of cocktail, and each judge will pick the cocktail with the Kth lowest score.
    For the next N line, each line will have one integer X_i , which means the concentration of ith glass of cocktail is X_i.
    ///
    請依序輸出每位評審會選出的調酒的濃度
    Please print the concentration of the cocktails selected by each judge in order.
    盡量不要亂砸一些奇怪的資料結構QwQ
    然後建議不要幾乎整份抄網路的QwQ
    STL set/multiset

# pitfalls
