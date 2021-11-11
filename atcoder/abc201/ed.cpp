#include <cctype>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <string_view>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <regex>
#include <set>
#include <bitset>

const int64_t infl = 1LL << 60;
const int64_t cc = pow(10, 9) + 7;
bool sort_pair(std::pair<int64_t, int64_t> origin, std::pair<int64_t, int64_t> another){return origin.first < another.first;}
template <typename T> bool chmin(T &a, const T& b) {if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b) {if(a < b) {a = b;return true;}return false;}

int main()
{
    std::string A[2020];
    int64_t q,k,n,s,h,w;
    
    std::cin>> h;
    std::cin>> w;
    int memo[h+1][w+1];
    std::string a;

    for( int i = 0; i < h; i++ )
    {
        std::cin>> A[i];
    }


    for( int i = h - 1; i > -1; i-- )
    {
        for( int r = w - 1; r > -1; r-- )
        {
            //std::cout<< i << " " << r <<"\n";
            if( i == h - 1
                && r == w - 1 )
            {
                memo[i][r] = 0;
                continue;
            }

            int64_t dp1, dp2;
            dp1 = -infl;
            dp2 = -infl;
            k = 1;

            if( ( i + r ) % 2 == 1 )
            {
                k = -1;
                dp1 *= -1;
                dp2 *= -1;
            }

            if( i != h - 1 )
            {
                dp1 = ( A[i+1][r] == '+' ? 1 : - 1 ) * k + memo[i+1][r];
            }

            if( r != w - 1 )
            {
                dp2 = ( A[i][r+1] == '+' ? 1 : - 1 ) * k + memo[i][r+1];
            }

            if( ( i + r ) % 2 == 0 )
            {
                memo[i][r] = std::max( dp1, dp2 );
            }
            else
            {
                memo[i][r] = std::min( dp1, dp2 );
            }
        }
    }

    /*
    for( int i = 0; i < h; i++ )
    {
        for( int r = 0; r < w; r++ )
        {
            std::cout<< memo[i][r] <<" ";
        }

        std::cout<< "\n";
        }*/

    if( memo[0][0] > 0 ) std::cout<< "Takahashi";
    else if( memo[0][0] < 0 ) std::cout<< "Aoki";
    else std::cout<<"Draw";
}


