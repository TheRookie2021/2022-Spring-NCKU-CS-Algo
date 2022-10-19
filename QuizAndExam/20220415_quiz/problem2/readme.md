找出班上的
中位數

要使用分群的方法來找到中位數。
1. 分群使用每 5 個一群的方式
2. 為了計算的簡便，若有偶數個資料，則中位數為第 N/2 小的資料
3. 為了確保答案唯一 (無多重解)，在 partition 或其他運算中，陣列中的所有數字，前後順
序不可調換，5 個數字 sort 時，也請勿在原陣列上 sort，可以新開暫存陣列，並對暫存
陣列進行 sort。固定 partition 的步驟如下。實作方式不固定，只要等價於此段程式碼即
可。

``` c
vector<int> small, big; // partition 的 目 的 是 分 成 兩 堆，small 與 big
for(int i = 0; i < n; i++) { // 照 順 序 掃 描 原 陣 列
    if(pivot > v[i]) small.push_back(v[i]); // 將 比pivot小 的 數 字， 放 入small
    if(pivot < v[i]) big.push_back(v[i]); // 將 比pivot大 的 數 字， 放 入big
}

```
// 若 要 之 後 要 進 行 遞 迴 呼 叫， 請 用 small 或 big 進 行 遞 迴 呼 叫

請輸出找中位數的過程之中，每次 partition 所使用的 pivot 的值，以及最後輸出所有學生成
績的中位數