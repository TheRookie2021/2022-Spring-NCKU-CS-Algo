# title   
    前陣子，因為某些緣故，生產俄羅斯娃娃的工廠突然被迫停工，工人們匆匆離開，留下了許多未完成品。近期工廠可能有望復工(?)，工人們想清點一下有多少組娃娃是還可以販賣的，可以幫幫他們嗎？
    大的俄羅斯娃娃可以放進中的俄羅斯娃娃，中的俄羅斯娃娃可以放進小的俄羅斯娃娃，以此類推。（只能放入更小的娃娃）
    俄羅斯娃娃就是要一層一層才漂亮，所以請盡量疊在一起。（最少化俄羅斯娃娃的組數）
    給定數個不同大小的娃娃，請幫工人們算出有多少組俄羅斯娃娃。
    ---
    English Version:
    For some reason, the factory that produced Russian dolls was suddenly forced to stop, and the workers left in a hurry, leaving many unfinished products. The factoy may be expected to resume work in near future. The workers want to count how many sets of dolls are avaliable for sale. Can you help them?
    A large Russian doll can hold a medium Russian doll, a medium Russian doll can hold a small Russian doll, and so on. (Can only accommodate smaller dolls). Russian dolls are beautiful layer upon layer, so try to stack them as much as possible. (minimize the number of groups of Russian dolls)
    Given a number of dolls of different sizes, help the workers figure out how many sets of Russian dolls there are.

# input/output
    每筆測資輸入為兩行。
    第一行有一個整數N代表有幾個俄羅斯娃娃。
    第二行有N個整數M代表每個娃娃的尺寸。
    Input starts with an integer N, where N denotes the number of Russia dolls.
    Each of the next  lines gives N integers M which represent the size of dolls.
    * 1\leq N\leq 1\times 10^3， 1\leq M\leq 1\times 10^2
    --- 
    對於每筆輸入，輸出每組俄羅斯娃娃的組合，由小到大排列，每個數字後面接上一個空白字符。
    輸出有多種解，輸出任意一種即可。
    Output every set of the dolls, in ascending order. Each number is followed by a blank.
    There are multiple solutions for the output, and any one can be output.

# pitfalls
- LIST: SEGMENTATION FAULT
- list.erase(itrator): return the itr++, not internally make itr=itr+1, so make sure you use itr = list.erase(itr)

### resource:
- https://www.cplusplus.com/reference/list/list/erase/
- https://stackoverflow.com/questions/5145634/c-segmentation-when-using-erase-on-stdlist