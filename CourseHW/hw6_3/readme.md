<p>給定兩個字串 $s$ 和 $t$ ，內容由小寫英文字母組成，並給定一個空的字串 $z$ ，你的目標是通過以下操作，使得字串 $z$ 與 $t$ 相等。<br/>
你可以將 $s$ 的任何子序列 (subsequence)接在 $z$ 字串之後，舉例來說：若 $z$ = "ac"， $s$ = "abcde"，只進行一次操作的情況下， $z$ 可以轉換成以下字串(並未列出所有可能)：<br/>
$z$ =  "acace" (選擇 "ace" 作為子序列)<br/>
$z$ =  "acbcd" ( 選擇 "bcd" 作為子序列)<br/>
請計算將字串 $z$ 轉換成 字串 $t$ 需要多少次運算。</p>
<p>English Version:<br/>
You are given two strings $s$ and $t$ consisting of lowercase Latin letter. Also, you have a string $z$ which is initially empty. You want to string $z$ to be equal to string $t$ . You can perform the following operation to achieve this: append any subsequence of $s$ at the end of string $z$ . For example, if $z$ = "ac", $s$ = "abcde", you may turn $z$ into following string in one operation (not listed all possible):<br/>
$z$ = "acace" (select "ace" as subsequence)<br/>
$z$ = "acbcd" (select "bcd" as subsequence)<br/>
Calculate how many operations are required to convert string $z$ to string $t$ .</p>
<p>第一行有一個整數 $T$ 代表接下來有幾筆測資。<br/>
接下來的兩行為兩個字串 $s$ 和 $t$  ，字串內所有字元都是小寫英文字母。</p>
<p>The first line of input contains one integer giving the number of cases that follow.<br/>
The next two lines are two strings $s$ and $t$, all characters in the strings are lowercase Latin letters.<br/>
* $1\leq T \leq 100$<br/>
* $1 \leq s.size() \leq 1\times 10^5$， $1 \leq t.size() \leq 1\times 10^5$</p>
<p>輸出所需要的操作數量，若沒辦法將 $z$ 轉換成 $t$ ，則輸出 -1。</p>
<p>Output the number of operations required, or -1 if there is no way to convert $z$ to $t$ .</p>

# pitfalls
- use cin is better than gets in C++ (<code><iostream></code>)
- flag is needed for condtion check
- 