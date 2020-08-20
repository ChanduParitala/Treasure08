/*  */
#include <bits/stdc++.h>

using namespace std;

int N;
char S[101];
vector<int> cnt;
map<vector<int>, int> M;

int main()
{
    int T;
    cin>>T;
    cnt.resize(26);
    while(T--)
    {
        M.clear();
        cin>>S;
        N=strlen(S);
        int ans=0;
        for(int i=0; i<N; i++)
        {
            cnt.assign(26, 0);
            for(int j=i; j<N; j++)
            {
                cnt[S[j]-'a']++;//increment at the ascii value of char; indexes65-91                                   //('0-25')
                ans = ans + M[cnt]++; // add the incremented value+1 the new occurance
                                     // From the map<vector,int> add it to ans.
            }
        }
       cout<<ans<<endl;
    }
    return 0;
}
