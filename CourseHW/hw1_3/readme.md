# 1-3
    時間來到寒假結束後的開學，眾所皆知小嵐的教授們都很愛突襲小考，但無奈小嵐是個懶惰的大學生，於是他根據一套不怎麼科學的理論發明了一個考試預測演算法，用來偷懶好準備少一點的考試內容，算法內容如下。
    根據理論我們可以知道教授們都喜歡考最近提過的章節，而小嵐最多可以記住 N 個章節的內容，當教授提的章節數量超過 N 後，小嵐就會忘掉目前記得的章節中最早被教授提過的章節然後記住新提到的章節，因此你需要提供下面兩種操作命令。  

    - set a b，代表教授提到了章節 a 並且內容是 b，
        如果出現了"重複的章節"則更新其內容以及提到的時間。(更新時間與內容)
        (否則插入新的)  
    - get a，代表小考考到了章節 a ，你需要從你記住的內容中檢查是否存在，
        如果存在的話因為在腦中回憶了一遍，因此也需要"更新"提到的時間。(更新並輸出其內容)
        (否則輸出-1)  

    English Version:
    A new semester has started! It is well known that professors in the Arashi87's course  like to have pop quiz. However, Arashi87 is a quite lazy student. He invented a "Test Prediction Algorithm" according to an unscientific theory. This allows him to prepare less stuff and get more to time to slack off. The algorithm he invented is described down below:
    According to the theory, we can know that professors like to have quiz for the chapter they have mentioned lately. And, Arashi87 can memorize at most  N . If professor teach more chapter than N,  Arashi87  will forget the earliest chapter that the professor taught and memorize the new chapter.  Here we need you to provide two operations like down below:

第一行輸入兩個整數 N 和 M 代表小嵐總共可以記得 N 個章節，和總共會有 M 條操作。
接下來有 M 行命令，每行皆符合上述操作命令格式，且所有命令依照時間先後順序給出。
First line contains two integers N and M. This means that Arashi87 can memorize N chapters at most. And, there are totally M operations.
For the next M  line commands, every line is a valid operation according to the description. All commands will be given in time order.
* 1\leq N\leq 10^5
* 1\leq M\leq 10^6
* 1\leq a, b\leq 5\times 10^5
對於所有 get 命令，如果存在章節 a 則輸出其內容 b，反之則輸出 -1，最後緊接著一個換行。
For each get operation, if there exist chapter a, output its content b. Otherwise, output -1. At last, make a new line.
小嵐發明的算法在現實中是真實存在且廣泛運用到的喔，詳細請見 <a href="https://www.youtube.com/watch?v=a3Z7zEc7AXQ">維基百科</a>！

---
# ans 
- how to maintain the inserted order ?
- using a single map structure is not enough, which can not maintain the order(it is internally sorted)
- using vector is not fast enough in finding the key.
- sol: using list to store the data by input order, and use map to store the iterator of the list(with chapt as key values), which enhance the speed of finding key.
```
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#define ft first
#define sd second
using namespace std;
typedef pair<int, int> pii;

int n, m, a, b;
string opt;
list<pii> _list;
unordered_map<int, list<pii>::iterator> mp;

int main()
{
    cin >> n >> m;
    while (cin >> opt >> a) {
        if (opt == "get") {
            if (mp.find(a) != mp.end()) {
                cout << (*mp[a]).sd << '\n';
                _list.erase(mp[a]);
                _list.push_front({ a, (*mp[a]).sd });
                mp[a] = _list.begin();
            } else
                cout << "-1\n";
        } else {
            cin >> b;
            if (mp.find(a) != mp.end())
                _list.erase(mp[a]);
            _list.push_front({ a, b }), mp[a] = _list.begin();
            if (_list.size() > n)
                mp.erase(_list.back().ft), _list.pop_back();
        }
    }
}
```