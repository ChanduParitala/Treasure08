#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> ip,vector<int> op)
{
	if(ip.size()==0)
	{
	    /*if(op.size()<2)
		return;
		int m1=0,m2=0;
		int m1i,m2i;
		for (int i = 0; i < op.size(); i++)
             m1= max(m1,op[i]);
          for (int i = 0; i < op.size(); i++)
          {
           if (op[i] != m1)
            m2= max(m2,op[i]);
          }
          for(int i=0;i<op.size();i++)
          {
          	if(op[i]==m1)
          	m1i=i;
          	if(op[i]==m2)
          	m2i=i;
		}
		if(m1i>m2i)
		{
		cout<<"["<<m1i<<" "<<m2i<<"]"<<"from: "<<endl;
		for(int i=0;i<op.size();i++)
		cout<<op[i]<<" ";
		cout<<endl;
       	}*/
       	for(int i=0;i<op.size();i++)
       	cout<<op[i]<<" ";
       	cout<<endl;
		return;
	}
	vector<int> op1= op;
	vector<int> op2= op;
	op2.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	solve(ip,op1);
	solve(ip,op2);
	return;
}

int main()
{
	vector<int> arr;
	int size;
	cout<<"size: ";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		int x;cin>>x;
		arr.push_back(x);
	}
	vector<int> op;
	solve(arr,op);
}
