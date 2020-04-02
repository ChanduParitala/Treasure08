/* 
-Two types of people can enter into a library- students and teachers. After entering the library, the
visitor searches for the required books and gets them. In order to get them issued, he goes to the single
CPU which is there to process the issuing of books. Two types of queues are there at the counter-one
for students and one for teachers. A student goes and stands at the tail of the queue for students and
similarly the teacher goes and stands at the tail of the queue for teachers (FIFO). If a student is being
serviced and a teacher arrives at the counter, he would be the next person to get service (PRIORITYnon preemptive).
If two teachers arrive at the same time, they will stand in their queue to get service(FIFO).
WAP to ensure that the system works in a non-chaotic manner.

-If a teacher is being served and during the period when he is being served, another teacher comes,
then that teacher would get the service next. This process might continue leading to increase in
waiting time of students. Ensure in your program that the waiting time of students is minimized.*/
//-------------------------------------------------------------------------------------------------------
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class process
{
	public:
	int pid;
	int at, bt, ct, rt;
};

process F[100],S[100],M[100];
int no_of_processes;
int fc=0,sc=0,mc=0;
//---------------------------------------------------------------------------------------------------------
void MERGER()
{
	int isc=0, ifc= 0, min, flag;
	if( fc!=0  && sc!=0){
		while(isc<sc && ifc<fc){
			if(F[ifc].at == S[isc].at){
				M[mc] = F[ifc];
				mc++;
				ifc++;
				M[mc]= S[isc];
				mc++;
				isc++;
			}
			else if(F[ifc].at < S[isc].at)
			{
				M[mc]= F[ifc];
				mc++;
				ifc++;
			}
			else if(F[ifc].at > S[isc].at)
			{
				M[mc]= S[isc];
				mc++;
				isc++;
			}
			else;
		}
		if(mc != (fc+sc))
		{
			if(fc!=ifc)
			{
				while(ifc!=fc){
					M[mc]= F[ifc];
					mc++;
					ifc++;
				}
			}
			else if(sc!=isc)
			{
				while(isc!=sc){
					M[mc]= S[isc];
					mc++;
					isc++;
				}
			}
		}
	}
	else if(fc==0)
	{
		while(isc!=sc){
			M[mc]= S[isc];
			mc++;
			isc++;
		}
	}
	else if(sc==0)
	{
		while(ifc!=fc){
			M[mc]= F[ifc];
			mc++;
			ifc++;
		}
	}
	else {
		cout<<"\n No valid Jobs available\n";
	}
}
//---------------------------------------------------------------------------------------------------------

void FIFO()
{
    int time= M[0].at, mark=0, cc=0, rc;
	while(cc!=mc)
	{
		for(int i=0; i<=mark; i++)
		{
			if(M[i].rt > 0){
				time += M[i].bt ;
				M[i].rt -= M[i].bt;
				M[i].ct = time;
				cc++;
			}
		}
		int start = mark+1;
		for(rc= start; rc<mc; rc++)
		{
			if(M[rc].at <= time)
			{
				mark++;
			}
		}
	}	
}

//------------------------------------------------------------------------------------------------------
int main()
{			//	INSTRUCTIONS:
	cout<<"\nAll Time units are in minutes. \n\n";
	
			//	INPUT PROCEDURE:
		int x,t;
		cout<<"Enter the number of Persons to enter the Library: \n";
		cin>>no_of_processes;
		if(no_of_processes==0)
		{
			cout<<"THERE ARE NO QUERIES FOUND!..";
		}
		else
		{
		 cout<<"--------------------------------------------------------------------------";
		 cout<<"\n>>Enter 1 for Faculty_Queue and 2 for Student_Queue\n"<<"**FACULTY have more priority**\n\n";
		for(int i=0;i<no_of_processes;i++)
		{
			cout<<"Job Type(1/2) ? : ";
			cin>>x;	
			if(x==1)
			{
				cout<<"Query Id: "; cin>>F[fc].pid;
				cout<<"Arrival Time: "; cin>>F[fc].at;
				cout<<"Burst Time: "; cin>>F[fc].bt;
			     F[fc].rt= F[fc].bt;
				F[fc].ct= 0;
				fc++;
			} 
			else
			{
				cout<<"Query Id: "; cin>>S[sc].pid;
				cout<<"Arrival Time: "; cin>>S[sc].at; 
				cout<<"Burst Time: "; cin>>S[sc].bt;
				S[sc].rt= S[sc].bt;
				S[sc].ct= 0;
				sc++;
			}
		}
     }
			// MERGE ALL THE PROCESSES INTO ONE QUEUE:
			MERGER();
			// IMPLEMENT FIFO OVER THE MERGED ARRANGEMENT:
			FIFO();
			//PRINT THE SUMMARY
	int i=0, total=0, sum=0; 
	double avg;
	cout<<"-------------------------------------------------------------------------------";
	cout<<"\n>>Summary for the Execution :\n";
	cout<<"\n|Query ID|   |Arrival Time |  |Burst Time |"
	<<"   |Completion Time|   |Turn Around Time|  |Waiting Time|\n";
	for(i; i<mc; i++)
	{
	cout<<M[i].pid<<"\t\t"<<(M[i].at)<<"\t\t"<< M[i].bt<<"\t\t"<<(M[i].ct)<<"\t\t\t"
	<<(M[i].ct-M[i].at)<<"\t\t\t"<< ((M[i].ct-M[i].at)- M[i].bt)<<endl;
	total+= M[i].ct;
	sum+= (M[i].ct-M[i].at);
	}
	avg = sum/mc;
	cout<<"\n\n"<<">>Total time Spent for all queries: "<< total;
	cout<<"\n"<<">>Average query time: "<< avg;
	cout<<"\n"<<">>Process Execution Complete" " :}\n\n";		
			return 0;
}

