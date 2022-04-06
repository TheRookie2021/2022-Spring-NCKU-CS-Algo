# frog
    一座黑心工廠將廢棄汙水排入河流，導致河川的水含有劇毒，任何生物碰到都會死去。
    青蛙小青想要出門吃早餐，然後再回家睡回籠覺，途中必須經過這條河流，於是牠決定踩著河上的石頭跳過去，這條河川的寬度為 W 公尺，河川上有 N 塊石頭，石頭分作大石頭與小石頭，小的石頭踩到後就會沉入水中，大的石頭則不會，一口氣跳太遠容易掉進水裡，請幫牠規劃一下，讓他盡可能每次跳的距離最小化嗎？
    English version:
    A unscrupulous factory discharges waste sewage into a river, causing the water in the river to be highly poisonous, and any creature that touches it will die.
    Frog Qing wants to go out to eat breakfast, and then go home and go back to sleep. On the way, he has to pass this river, so he decides to jump over the stones on the river. The width of this river is W meters. There are N stones on the river. The stones are divided into large stones and small stones. The small stones will sink into the water when you step on them, but the big stones will not. Jumping too far is easy to fall into the water. Please help him plan to minimize the distance he jumps each time?
# input/output
    輸入的第一行是一個整數 T ，代表有幾筆案例。
    每筆案例包含兩行：
    第一行有2個整數 N 、 W ，分別代表石頭數量與河川寬度。
    第二行描述 N 個石頭的大小與位置。每塊石頭有兩個敘述 S 與 P ， S 分作 b 與 s ， b 代表大型石頭， s 代表小型石頭， P 則代表石頭所在的位置，中間以空格隔開。石頭的位置以遞增順序給出。
    The first line of input is an integer T representing several cases.
    Each case contains two lines:
    The first line has two integers N and W , which represent the number of stones and the width of the river respectively.
    The second line describes the size and location of the N stones. Each stone has two descriptions S and P, S is divided into b and s , b represents the big stone, s represents the small stone, and P represents the place where the stone is located positions, separated by spaces. The positions of the stones are given in increasing order.
    * 1 T  100
    * 0  N  1\times 10^2， 1  W  2\times 10^9
    * 0 \lt P \lt W
    對於每筆測資，輸出需要跳的最大距離。
    For each test case, output the maximum distance that needs to be jumped.

# pitfalls
    3 20
    s 5 s 10 s 15
    答案應該是10 不是20

    小青蛙是去了又回來 注意一下題目敘述