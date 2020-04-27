#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string > tt;
string str;

int main()
{
    getline(cin,str);
    str += " end";
    int jump = 1;
    int tmp = 100;
    int id = 100;
    stringstream ss(str);
    string s;
    while(ss>>s)
    {
        if(s == "or" || s == "end")
        {
            int len = tt.size();
            int i;
            if(s == "or")
                tmp = tmp + 2;
            else
                tmp = 0;
            for(i=0;i<len-3;i+=3)
            {
                printf("%d(j%s,%s,%s,%d)\n",id,tt[i+1].c_str(),tt[i].c_str(),tt[i+2].c_str(),id+2);
                id++;
                printf("%d(j,_,_,%d)\n",id,tmp);
                tmp = id++;
            }
            printf("%d(j%s,%s,%s,%d)\n",id,tt[len-2].c_str(),tt[len-3].c_str(),tt[len-1].c_str(),jump);
            jump = id++;
            printf("%d(j,_,_,%d)\n",id,tmp);
            id++;
            tt.clear();
            if(s == "end")
                break;
        }
        else if(s == "and")
            tmp += 2;
        else
            tt.push_back(s);
    }
    return 0;
}
