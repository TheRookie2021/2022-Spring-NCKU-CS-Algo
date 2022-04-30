
# 逆序數 (Inversion number): 
- 即一個數列中逆序數對的數量，是一個評估數列未排序程度的指標。我們定義一個序列 a 中數對 (i,j) 是逆序，如果 i < j 且 ai > aj
- input: 第一行為數列 a 的大小，第二行為組成 a 的 n 個整數
- output: 輸出此數列 a 的逆序數。此數字可能會很大，請先用 524287 對其取餘數再輸出

---
# pitfall: beyond algorithm - data overflow
- the # of input number is very large 
- the data number is very large

