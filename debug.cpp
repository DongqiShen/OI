/*
 * Description: debug purpose
 * Date: 2021.09.12
 * Author: 觉不醒的王子殿下
 */
#include <limits.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int maxn = 1000;
deque<int> readyQ;
queue<int> blockQ;
int n, quantum, c[5], var[26] = {0}, ip[maxn];
bool locked;
char prog[maxn][10];

void run(int pid){
    int q = quantum;
    while(q > 0) {
        char* p = prog[ip[pid]];
        switch (p[2]){
            case '=':
                var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
                q -= c[0];
                break;
            case 'i':
                fout<<pid + 1<<": "<<var[p[6]-'a']<<"\n";
                q -= c[1];
                break;
            case 'c':
                if(locked){
                    blockQ.push(pid);
                    return;
                }
                locked = true;
                q -= c[2];
                break;
            case 'l':
                locked = false;
                if(!blockQ.empty()){
                    int pid2 = blockQ.front();
                    blockQ.pop();
                    readyQ.push_front(pid2);
                }
                q -= c[3];
                break;
            case 'd':
                return;
        }
        ip[pid]++;
    }
    readyQ.push_back(pid);
}


int main()
{
    int T;
    fin>>T;
    while(T--){
        fin>>n>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>quantum;
        memset(var, 0, sizeof(var));
        int line = 0;
        for(int i = 0; i < n; ++i){
            fin.getline(prog[line++], maxn);
            while(prog[line-1][0] == '\0'){
                fin.getline(prog[line-1], maxn);
            }
            ip[i] = line - 1;
            while(prog[line-1][2] != 'd'){
                fin.getline(prog[line++], maxn);
                if(prog[line-1][0] == '\0'){
                    line--;
                }
            }
            readyQ.push_back(i);
        }

        locked = false;
        while(!readyQ.empty()){
            int pid = readyQ.front();
            readyQ.pop_front();
            run(pid);
        }
        if(T){
            fout<<"\n";
        }
    }
    return 0;
}