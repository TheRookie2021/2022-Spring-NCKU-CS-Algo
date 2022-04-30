# 12 . Sort Characters By Frequency
給定一個字串 s，請以字母出現頻率遞減排序該字串。
字母出現頻率定義為字母在字串出現的次數。
請印出排序好的字串，
當有字母間有相同頻率時，以 ASCII Code 順序排列它們。

English Version:
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Print the sorted string.
If there are two or more characters have the same frequency, sort the characters in ASCII Code order.
---
- tip:

use the stl algorithm std::sort with custom compare function 
there are two condition :
    1. the more frequent, the further adhead. (main)
    2. the less ACIII code, the further adhead. (secondary)
cmp func->
    if(more freq) return true
    else if(same freq) return true
    else return false
