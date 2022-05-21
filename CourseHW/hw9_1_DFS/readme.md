# Escape the 2D maze
    由於上次最後炸彈還是爆炸了，所以小邱終於帶著殘血逃到了廁所之外。
    然而，他卻發現由於爆炸把廁所的磁磚都炸飛了，磁磚散的到處都是，導致有些地方能夠通過，而有些地方則不能夠通過。
    但是出口只有一個。小邱每次移動，可以往他的上下左右的其中一個方向移動一格。
    現在告訴你小邱的起始位置，以及出口所在的位置，請你告訴小邱他是否能夠有機會從當前位置順利走到出口。
# input/output
    第一行輸入三個整數 N, M 代表總共有 N * M個格子。
    接下來有 4 個整數，分別為 S_x, S_y, T_x, T_y，代表小邱當前所在座標(S_x, S_y)，以及出口所在的座標(T_x, T_y)。
    注意座標皆從 1 開始編號。
    接下來有 N 行，每行有 M 個數字 X_{ij}。分別代表每一個格子小邱是否能夠通過，1 代表可以通過，而 0 則代表不能夠通過。
    若小邱可以成功逃離，請輸出"Success!"(不包括引號)
    若無法成功逃離，請輸出"Fail!"(不包括引號)

# pitfalls
- crutial tech: use stack to store and record the steps, and use a flag to make the code cleaner, last but not least, the definition of "dir" variable should be clear.(last step dir? what's the next dir?)
- the input matrix is m*n not n*n !!! mind your words (input part)
- next time try to use 2D vector for eaiser 2D matrix passing 
