/*There are 3 student processes and 1 teacher process. Students are supposed to do their assignments and they need 3 things for that pen, paper and question paper.
The teacher has an infinite supply of all the three things. One students has pen,an other has paper and another has question paper. 
The teacher places two things on a shared table and the student having the third complementary thing makes the assignment and tells the teacher on completion.
The teacher then places another two things out of the three and again the student having the third thing makes the assignment and tells the teacher on completion.
This cycle continues. Write a programme to synchronize the teacher and the students.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class requirement
{
	public:
 	bool pen ;
	bool paper ;
	bool question_paper ;
	bool all_three ;
};
int main()
{
	int n=3;
     requirement  s[n];
	s[0].pen=true;		
	s[0].paper = false;
	s[0].question_paper = false;
	s[0].all_three= false;
	s[1].pen=false;		
	s[1].paper = true;
	s[1].question_paper = false;
	s[1].all_three = false;
	s[2].pen=false;		
	s[2].paper = false;
	s[2].question_paper = true;
	s[2].all_three = false	;
	int c=0;
	while(s[0].all_three==false||s[1].all_three==false||s[2].all_three==false)
	{
		int ch1,ch2;
		if(c==0)
		cout<<"\nResources:\n1.pen\n2.paper\n3.question paper\n Enter the two things which is to be placed on the shared table: "<<endl;
		else if(c>0&&c<3)
		cout<<"\nNow which resource u want to keep on Shared Table:\n1.pen\n2.paper\n3.question paper\n Enter the two things which is to be placed on the shared table: "<<endl;
		else if(c==3)
		{
		cout<<"All the students have completed the Assignment!.\n";
		break;}
		cin>>ch1>>ch2;
		if(ch1==1 && ch2==2 && s[2].all_three==false)
		{
			s[2].all_three=true ;
			cout<<"\nThird Student has completed the task\n";
			c=c+1;
		}
		if(ch1==2 && ch2==3 && s[0].all_three==false)
		{
			s[0].all_three=true;
			cout<<"\nFirst Student has completed the task\n";
			c=c+1;
		}
		if(ch1==1 && ch2==3 && s[1].all_three==false)
		{
			s[1].all_three=true;
			cout<<"\nSecond Student has completed the task\n";
			c=c+1;
		}
	}
	cout<<"\nGood, All the students now have completed their respective tasks succesfully\n";
	return 0;
}
