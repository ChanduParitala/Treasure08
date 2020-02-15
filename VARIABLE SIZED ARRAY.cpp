#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int n,q; //n number of variable lenght arrays // q no of queries asked
    cin >>n >>q;
   int ** Vectors = new int *[n];//no of length of var. arrays
   int j;
    for (int i=0;i<n;i++)
    {   
        cin>>j;
        Vectors[i] = new int [j];
        for (int y=0;y<j;y++)
            cin>>Vectors[i][y];
    }
    int q1,q2;
    for (int i=0;i<q;i++)
    {
        cin >>q1 >> q2;
        cout<<Vectors[q1][q2]<<endl;

     }

    return 0; 
}
