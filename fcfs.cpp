#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void fcfs(vector<pair <int,int> > process)
{
	sort(process.begin(),process.end());
	int time=0;
	int tot_time=0;
	float turnaround=0;
	float avg_wtime;
	int i,f=0;
	for(i=0;i<process.size();i++)
	{
		time+=process[i].second;
		f+=time-process[i].first;
		if(i<process.size()-1)
		tot_time+=time-process[i+1].first;
		cout<<f<<"-->"<<tot_time<<"\n";
	}
	turnaround=(float)f/process.size();
	avg_wtime=(float)tot_time/process.size();
	cout<<"TURAROUND TIME: "<<turnaround<<"\n";
	cout<<"AVG WAITING TIME: "<<avg_wtime<<"\n";
	return;
}

void sjf(vector <pair <int,int> > process)
{
	int timer=0;
	
	int i=0;
	int size=process.size();
	vector <pair <int,int> > newarr;
	int turnaround=0;
	int wait=0;
	int pos;
	vector <int> cpu;
	for(i=0;i<process.size();i++)
	{
		cpu.push_back(process[i].second);
		cout<<cpu[i];
	}
	i=0;
	while(process.size()!=0)
	{
		int min=9999;
		
		int completion=0;
		for(i=0;i<process.size();i++)
		{
			if(process[i].first<=timer)
			{
				if(process[i].second<min)
				{
				pos=i;
				min=process[i].second;
				}
			}
			
		}
		cout<<min<<"\n ";
		timer++;
		process[pos].second--;
		if(process[pos].second==0)
		{
			cout<<"Process with arr time: "<<process[pos].first<<" completed at time: "<<timer<<"\n";
			turnaround+=timer-process[pos].first;
			wait+=timer-cpu[pos]-process[pos].first;
			process.erase(process.begin()+pos);
			cpu.erase(cpu.begin()+pos);
		}
		
		
		
	}
	cout<<"\n \n Average turnaround time: "<<(float)turnaround/size<<"\n";
	cout<<"\n \n Average waiting time: "<<(float)wait/size<<"\n";
	
}
void sjfnp(vector <pair <int,int> > process)
{
	int timer=0;
	
	int i=0;
	int size=process.size();
	
	int turnaround=0;
	int wait=0;
	int pos;
	vector <int> cpu;
	for(i=0;i<process.size();i++)
	{
		cpu.push_back(process[i].second);
		cout<<cpu[i];
	}
	i=0;
	while(process.size()!=0)
	{
		int min=9999;
		
		int completion=0;
		for(i=0;i<process.size();i++)
		{
			if(process[i].first<=timer)
			{
				if(process[i].second<min)
				{
				pos=i;
				min=process[i].second;
				}
			}
			
		}
		cout<<min<<"\n ";
		
		
		timer+=process[pos].second;
		process[pos].second=0;
		if(process[pos].second==0)
		{
			cout<<"Process with arr time: "<<process[pos].first<<" completed at time: "<<timer<<"\n";
			turnaround+=timer-process[pos].first;
			wait+=timer-cpu[pos]-process[pos].first;
			process.erase(process.begin()+pos);
			cpu.erase(cpu.begin()+pos);
		}
		
		
		
	}
	cout<<"\n \n Average turnaround time: "<<(float)turnaround/size<<"\n";
	cout<<"\n \n Average waiting time: "<<(float)wait/size<<"\n";
	
}

void rr(vector <pair <int,int> >process)
{
	int quantum;
	cout<<"Enter the Value of Time quantum:\n";
	cin>>quantum;
	int timer=0;
	int i=0;
	vector <int> cpu;
	int size=process.size();
	for(i=0;i<size;i++)
	{
		cpu.push_back(process[i].second);
	}
	int wait=0,turnaround=0;
	while(process.size()!=0)
	{
		i=0;
		for(i=0;i<process.size();i++)
		{
			if(process[i].first==-1)
			continue;
			else if(process[i].second>quantum)
			{
				timer+=quantum;
				process[i].second-=quantum;
				
			}
			else
			{
				
				timer+=process[i].second;
				cout<<"Process with arr time: "<<process[i].first<<" completed at time: "<<timer<<"\n";
				turnaround+=timer-process[i].first;
				wait+=timer-cpu[i]-process[i].first;
				process[i].first=-1;
				
			}
		}
		for(i=0;i<process.size();i++)
		{
			if(process[i].first==-1)
			{
				process.erase(process.begin()+i);
				cpu.erase(cpu.begin()+i);
			}
			
			
		}
	}
	cout<<"\n \n Average turnaround time: "<<(float)turnaround/size<<"\n";
	cout<<"\n \n Average waiting time: "<<(float)wait/size<<"\n";
}

void psp(vector < pair <int,int> >process)
{
	vector <int> priority;
	vector <int> cpu;
	int wait=0,turnaround=0,size=process.size();
	cout<<"Enter the priority of the processes in order: \n";
	int i;
	for(i=0;i<process.size();i++)
	{
		int p;
		cpu.push_back(process[i].second);
		cin>>p;
		priority.push_back(p);
	}
	int timer=0;
	int pos;
	while(process.size()!=0)
	{
		int min=9999;
		for(i=0;i<process.size();i++)
		{
			if(process[i].first<=timer)
			{
				if(priority[i]<min)
				{
					pos=i;
					min=priority[i];
				}
			}
		}
		timer++;
		process[pos].second--;
		if(process[pos].second==0)
		{
			cout<<"Process with priority "<<priority[pos]<<" and arrival time: "<<process[i].first<<" completed at time: "<<timer<<"\n";
			turnaround+=timer-process[pos].first;
			wait+=timer-process[pos].first-cpu[pos];
			process.erase(process.begin()+pos);
			cpu.erase(cpu.begin()+pos);
			priority.erase(priority.begin()+pos);
		}
	}
	cout<<"\n \n Average turnaround time: "<<(float)turnaround/size<<"\n";
	cout<<"\n \n Average waiting time: "<<(float)wait/size<<"\n";
	
}
void psnp(vector < pair <int,int> >process)
{
	vector <int> priority;
	vector <int> cpu;
	int wait=0,turnaround=0,size=process.size();
	cout<<"Enter the priority of the processes in order: \n";
	int i;
	for(i=0;i<process.size();i++)
	{
		int p;
		cpu.push_back(process[i].second);
		cin>>p;
		priority.push_back(p);
	}
	int timer=0;
	int pos;
	while(process.size()!=0)
	{
		int min=9999;
		for(i=0;i<process.size();i++)
		{
			if(process[i].first<=timer)
			{
				if(priority[i]<min)
				{
					pos=i;
					min=priority[i];
				}
			}
		}
		timer+=process[pos].second;
		process[pos].second=0;
		if(process[pos].second==0)
		{
			cout<<"Process with priority "<<priority[pos]<<" and arrival time: "<<process[pos].first<<" completed at time: "<<timer<<"\n";
			turnaround+=timer-process[pos].first;
			wait+=timer-process[pos].first-cpu[pos];
			process.erase(process.begin()+pos);
			cpu.erase(cpu.begin()+pos);
			priority.erase(priority.begin()+pos);
		}
		
	}
	cout<<"\n \n Average turnaround time: "<<(float)turnaround/size<<"\n";
	cout<<"\n \n Average waiting time: "<<(float)wait/size<<"\n";
	
}


int main()
{
	vector <pair <int,int> > process;
	int n;
	int i;
	cout<<"Enter the number of process \n";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Enter the arrival time and CPU time for the process: \n";
		int arr_time;
		int cpu_time;
		cin>>arr_time>>cpu_time;
		process.push_back(make_pair(arr_time,cpu_time));
	}
	int choice;
	
	cout<<"Press the following: \n ========================== \n 1 for FCFS scheduling \n 2 for SJF scheduling \n 3 for Round Robin \n 4 for Priority Scheduling \n================\n";
	cin>>choice;
	if(choice==1)
	{
		fcfs(process);
	}
	else if(choice==2)
	{
		cout<<"Enter 1 for SJF for pre-emptive version \n Enter 2 for SJF Non-pre emptive version \n =======================\n";
		int ch=0;
		cin>>ch;
		if(ch==1)
		sjf(process);	
		else if(ch==2)
		sjfnp(process);
		else
		cout<<"You entered a wrong choice\n";
	}
	else if(choice==3)
	{
		rr(process);
	}
	else if(choice==4)
	{
		int ch;
		cout<<"Enter 1 for Non Pre-Emptive Priority Scheduling \n Enter 2 for Pre-emptive Priority Scheduling \n =================\n";
		cin>>ch;
		if(ch==1)
			psnp(process);
		else if(ch==2)
			psp(process);
		else
			cout<<"Wrong Input execute the program again and enter a valid input\n";
	}
	else
		cout<<"Wrong Input execute the program again and enter a valid input\n";
	return 0;	

}
