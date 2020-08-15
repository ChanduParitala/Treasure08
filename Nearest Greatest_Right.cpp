#include<bits/stdc++.h>
using namespace std;
void NGR(int arr[],int size)
{
	stack<int> s;
	for(int i=size-1;i>=0;i--)
	{
		if(i==size-1)
		{
		 cout<<-1<<" ";
      	}
		else if(s.size()>0 && s.top()>arr[i])
		cout<<s.top()<<" ";
		else if(s.size() && s.top()<=arr[i])
		{
			while(s.size()>0 && s.top()<=arr[i] )
			{
				s.pop();
			}
			if(s.size()==0)
			cout<<-1<<" ";
			else
			cout<<s.top()<<" ";
		}
		s.push(arr[i]);
	}
	return;
}

int main()
{
int arr[2002];
int size; cout<<"size: ";
cin>>size;
for(int i=0;i<size;i++)
cin>>arr[i];
NGR(arr,size);
return 0;
}
