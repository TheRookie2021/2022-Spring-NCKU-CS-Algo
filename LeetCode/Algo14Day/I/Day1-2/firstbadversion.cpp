#include <iostream>
#include <vector>
using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1 && isBadVersion(n)) return 1;
        else if(n==1 && !isBadVersion(n)) return -1;

        long long int l = 1, r = n ;
        while(l<=r){
            long long int m = (l + r) / 2;
            // judging
            if(isBadVersion(m)){
                if (m == 1) // bug: set boundary condition(before checking m-1)
                    return m;
                if (isBadVersion(m - 1))
                    r = m - 1;
                else
                    return m;

            }else{
                if (m == n)
                // it's weird that adding this dummy condition will enhance the speed, 
                // maybe it has sth to do with adding very large num 
                    return -1;
                else
                    l = m + 1;
            }
        }
        return -1;
    }
};
int main(){

    return 0;
}