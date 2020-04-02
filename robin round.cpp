/*Sudesh Sharma is a Linux expert who wants to have an online system where he can handle student 
queries. Since there can be multiplerequests at any time he wishes to dedicate a fixed amount of time 
to every request so that everyone gets a fair share of his time.
He will log into the system from 10am to 12am only.  He wants to have separate requests queues for 
students and faculty.
Implement a strategy for the same. The summary at the end of the session should include the total time
he spent on handling queries and average query time.*/
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
int time_quanta;
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

void ROBIN_ROUND()
{
    int time= M[0].at, mark=0, cc=0, i, rc;
	while(time!=1200 && cc!=mc)
	{
		for(i=0; i<=mark; i++)
		{
			if(M[i].rt > time_quanta){
				time += time_quanta;
				M[i].rt -= time_quanta;
			}
			else if(M[i].rt <=time_quanta && M[i].rt !=0){
				time += M[i].rt;
				M[i].rt =0;
				M[i].ct = time;
				cc++;
			}
			else;
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
	cout<<"\nWelcome, please follow these instruction for proper functioning of the program"<<"\n>>Enter time in 2400 hours format. example for 10:30 am enter 1030"
			<<"\n>>Enter Query arrival times in ascending order,i.e.,Enter the time in increasing manner\n"
			<<"\nAll Time units are in minutes. \n\n";
	
			//	INPUT PROCEDURE:
		int x,t;
		cout<<"Enter the number of queries: \n";
		cin>>no_of_processes;
		cout<<"Enter the Time Quanta for Robin_Round algorithm: \n";
		cin>>time_quanta;
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
				cout<<"Arrival Time: "; cin>>t;
				if(t<1000 || t>1200)
				{
					cout<<"\nEnter Correct Time between 1000 and 1200 : \n";
					cin>>t;
				}
				else{F[fc].at= t-1000;}
				cout<<"Burst Time: "; cin>>F[fc].bt;
			     F[fc].rt= F[fc].bt;
				F[fc].ct= 0;
				fc++;
			} 
			else
			{
				cout<<"Query Id: "; cin>>S[sc].pid;
				cout<<"Arrival Time: "; cin>>t; 
				if(t<1000 || t>1200)
				{
					cout<<"\nEnter Correct Time between 1000 and 1200 : \n";
					cin>>t;
				}
				else {S[sc].at= t-1000; }
				cout<<"Burst Time: "; cin>>S[sc].bt;
				S[sc].rt= S[sc].bt;
				S[sc].ct= 0;
				sc++;
			}
		}
     }
			// MERGE ALL THE PROCESSES INTO ONE QUEUE:
			MERGER();
			// IMPLEMENT ROBIN ROUND OVER THE MERGED ARRANGEMENT:
			ROBIN_ROUND();
			//PRINT THE SUMMARY
	int i=0, total=0, sum=0; 
	double avg;
	cout<<"-------------------------------------------------------------------------------";
	cout<<"\nTime Quanta is: "<<time_quanta<<"\n>>Summary for the Execution :\n";
	cout<<"\n|Query ID|   |Arrival Time |  |Burst Time |"
	<<"   |Completion Time|   |Turn Around Time|  |Waiting Time|\n";
	for(i; i<mc; i++)
	{
	cout<<M[i].pid<<"\t\t"<<(M[i].at+1000)<<"\t\t"<< M[i].bt<<"\t\t"<<(M[i].ct+1000)<<"\t\t\t"
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

