#include <bits/stdc++.h>
#define feach(type, content,i) for(type::iterator i = content.begin() ; i != content.end() ; ++i)
#define farray(start, end, i) for(int i = start; i < end; ++i)

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> grid;
typedef vector<string> vs;

grid matriz;
vs name;
vi color;
int rep;
vi all;
unordered_map<string, int> my_hash;
grid p_color;

int dp[64][64] = {0,3,2,3,2,3,4,5,3,4,1,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,4,3,4,5,3,4,3,4,3,4,5,4,4,3,4,3,4,5,4,5,5,4,5,4,5,4,5,6,
                            3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,4,3,4,4,3,4,3,4,3,4,5,3,4,3,4,3,4,5,4,4,5,4,5,4,5,4,5,
                            2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,4,3,3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,5,5,4,5,4,5,4,5,4,
                            3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,2,3,2,3,2,3,2,3,3,2,3,2,3,2,3,4,4,3,4,3,4,3,4,3,3,4,3,4,3,4,3,4,4,5,4,5,4,5,4,5,
                            2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,3,2,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,5,4,5,4,5,4,5,4,
                            3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,4,3,2,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,4,3,4,3,4,3,5,4,3,4,3,4,3,4,4,5,4,5,4,5,4,5,
                            4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,4,3,4,3,4,4,5,4,3,4,3,4,3,5,4,5,4,5,4,5,4,
                            5,4,3,2,3,2,3,0,4,3,4,3,2,1,4,3,5,4,3,2,3,4,1,2,4,3,4,3,2,3,2,3,5,4,3,4,3,2,3,2,4,5,4,3,4,3,4,3,5,4,5,4,3,4,3,4,6,5,4,5,4,5,4,5,
                            3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,4,3,4,5,3,4,3,4,3,4,5,4,4,3,4,3,4,5,4,5,
                            4,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,4,3,4,4,3,4,3,4,3,4,5,3,4,3,4,3,4,5,4,
                            1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,4,3,3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,5,
                            2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,2,3,2,3,2,3,2,3,3,2,3,2,3,2,3,4,4,3,4,3,4,3,4,3,3,4,3,4,3,4,3,4,
                            3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,3,2,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,
                            4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,4,3,2,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,4,3,4,3,4,3,5,4,3,4,3,4,3,4,
                            3,4,3,2,1,2,3,4,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,4,3,4,3,4,4,5,4,3,4,3,4,3,
                            4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,3,2,3,5,4,3,4,3,2,3,2,4,5,4,3,4,3,4,3,5,4,5,4,3,4,3,4,
                            2,1,4,3,2,3,4,5,3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,4,3,4,5,3,4,3,4,3,4,5,4,
                            1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,4,3,4,4,3,4,3,4,3,4,5,
                            4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,4,3,3,4,3,4,3,4,3,4,
                            3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,2,3,2,3,2,3,2,3,3,2,3,2,3,2,3,4,4,3,4,3,4,3,4,3,
                            2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,3,2,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,4,3,4,3,4,3,4,
                            3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,4,3,2,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,4,3,4,3,4,3,
                            4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,4,3,4,3,4,
                            5,4,3,2,3,4,1,2,4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,3,2,3,5,4,3,4,3,2,3,2,4,5,4,3,4,3,4,3,
                            3,2,3,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,4,3,4,5,
                            2,3,2,3,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,4,3,4,
                            3,2,3,2,3,2,3,4,4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,4,3,
                            2,3,2,3,2,3,2,3,3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,2,3,2,3,2,3,2,3,3,2,3,2,3,2,3,4,
                            3,2,3,2,3,2,3,2,2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,3,2,3,2,3,2,3,2,4,3,2,3,2,3,2,3,
                            4,3,2,3,2,3,2,3,3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,4,3,2,3,2,3,2,3,3,4,3,2,3,2,3,2,
                            3,4,3,2,3,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,3,2,3,2,4,3,4,3,2,3,2,3,
                            4,3,4,3,2,3,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,3,2,3,5,4,3,4,3,2,3,2,
                            2,3,2,3,4,3,4,5,3,2,3,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,3,2,3,4,3,4,
                            3,2,3,2,3,4,3,4,2,3,2,3,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,3,2,3,4,3,
                            2,3,2,3,2,3,4,3,3,2,3,2,3,2,3,4,4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,3,2,3,2,3,2,3,4,
                            3,2,3,2,3,2,3,4,2,3,2,3,2,3,2,3,3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,2,3,2,3,2,3,2,3,
                            4,3,2,3,2,3,2,3,3,2,3,2,3,2,3,2,2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,3,2,3,2,3,2,3,2,
                            3,4,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,4,3,2,3,2,3,2,3,
                            4,3,4,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,3,2,3,2,
                            5,4,3,4,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,3,2,3,
                            3,4,3,4,3,4,5,4,2,3,2,3,4,3,4,5,3,2,3,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,2,1,4,3,2,3,4,5,
                            4,3,4,3,4,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,2,3,2,1,2,3,4,3,1,2,1,4,3,2,3,4,
                            3,4,3,4,3,4,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,2,3,4,4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,4,1,2,1,4,3,2,3,
                            4,3,4,3,4,3,4,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,2,3,3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,3,4,1,2,1,4,3,2,
                            3,4,3,4,3,4,3,4,4,3,2,3,2,3,2,3,3,2,3,2,3,2,3,2,2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,2,3,4,1,2,1,4,3,
                            4,3,4,3,4,3,4,3,3,4,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,3,2,3,4,1,2,1,4,
                            5,4,3,4,3,4,3,4,4,3,4,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,2,4,3,2,3,4,1,2,1,
                            4,5,4,3,4,3,4,3,5,4,3,4,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,5,4,3,2,3,4,1,2,
                            4,3,4,3,4,5,4,5,3,4,3,4,3,4,5,4,2,3,2,3,4,3,4,5,3,2,3,2,3,4,3,4,2,1,4,3,2,3,4,5,3,2,1,2,3,4,3,4,0,3,2,3,2,3,4,5,3,2,1,2,3,4,3,4,
                            3,4,3,4,3,4,5,4,4,3,4,3,4,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,4,3,2,1,2,3,4,3,
                            4,3,4,3,4,3,4,5,3,4,3,4,3,4,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,2,3,4,4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,1,2,3,2,1,2,3,4,
                            3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,2,3,3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,2,1,2,3,2,1,2,3,
                            4,3,4,3,4,3,4,3,3,4,3,4,3,4,3,4,4,3,2,3,2,3,2,3,3,2,3,2,3,2,3,2,2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,3,2,1,2,3,2,1,2,
                            5,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,3,4,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,4,3,2,1,2,3,2,1,
                            4,5,4,3,4,3,4,3,5,4,3,4,3,4,3,4,4,3,4,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,3,4,3,2,1,2,3,4,
                            5,4,5,4,3,4,3,4,4,5,4,3,4,3,4,3,5,4,3,4,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,1,2,3,5,4,3,2,3,2,3,0,4,3,4,3,2,1,2,3,
                            5,4,5,4,5,4,5,6,4,3,4,3,4,5,4,5,3,4,3,4,3,4,5,4,2,3,2,3,4,3,4,5,3,2,3,2,3,4,3,4,2,1,4,3,2,3,4,5,3,4,1,2,3,4,3,4,0,3,2,3,2,3,4,5,
                            4,5,4,5,4,5,4,5,3,4,3,4,3,4,5,4,4,3,4,3,4,3,4,5,3,2,3,2,3,4,3,4,2,3,2,3,2,3,4,3,1,2,1,4,3,2,3,4,2,3,2,1,2,3,4,3,3,0,3,2,3,2,3,4,
                            5,4,5,4,5,4,5,4,4,3,4,3,4,3,4,5,3,4,3,4,3,4,3,4,2,3,2,3,2,3,4,3,3,2,3,2,3,2,3,4,4,1,2,1,4,3,2,3,1,2,3,2,1,2,3,4,2,3,0,3,2,3,2,3,
                            4,5,4,5,4,5,4,5,3,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,3,2,3,2,3,2,3,4,2,3,2,3,2,3,2,3,3,4,1,2,1,4,3,2,2,1,2,3,2,1,2,3,3,2,3,0,3,2,3,2,
                            5,4,5,4,5,4,5,4,4,3,4,3,4,3,4,3,3,4,3,4,3,4,3,4,4,3,2,3,2,3,2,3,3,2,3,2,3,2,3,2,2,3,4,1,2,1,4,3,3,2,1,2,3,2,1,2,2,3,2,3,0,3,2,3,
                            4,5,4,5,4,5,4,5,5,4,3,4,3,4,3,4,4,3,4,3,4,3,4,3,3,4,3,2,3,2,3,2,4,3,2,3,2,3,2,3,3,2,3,4,1,2,1,4,4,3,2,1,2,3,2,1,3,2,3,2,3,0,3,2,
                            5,4,5,4,5,4,5,4,4,5,4,3,4,3,4,3,5,4,3,4,3,4,3,4,4,3,4,3,2,3,2,3,3,4,3,2,3,2,3,2,4,3,2,3,4,1,2,1,3,4,3,2,1,2,3,2,4,3,2,3,2,3,0,3,
                            6,5,4,5,4,5,4,5,5,4,5,4,3,4,3,4,4,5,4,3,4,3,4,3,5,4,3,4,3,2,3,2,4,3,4,3,2,3,2,3,5,4,3,2,3,4,1,2,4,3,4,3,2,1,4,3,5,4,3,2,3,2,3,0};
string pos(int i, int j){
    string aux = "";
    aux += char(i + 'a');
    aux += char(j + '1');
    return  aux;
}
int main() {
    farray(0,8,i){
        farray(0,8,j){
            string aux = pos(i,j);
            name.push_back(aux);
            my_hash.insert({aux,rep++});
        }
    }
    int n;
    cin >> n;
    while(n--){
        string a,b;
        cin >> a >> b;
        cout << dp[my_hash.at(a)][my_hash.at(b)] << endl;
    }
}