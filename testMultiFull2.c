#include<stdio.h>

struct process
{
      char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
      int enter;
}process_queue[100],roundRobin[100];

int limit;
int quant_time;
void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}
void round_robin(int time,int size){
  int i, limit, total = 0, x, counter = 0, time_quantum; 
  int wait_time = 0, turnaround_time = 0; 
  limit = size;
  x = limit;
  time_quantum = time;
  printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
  for(total = 0, i = 0; x != 0;) 
      { 
            if(roundRobin[i].burst_time <= time_quantum && roundRobin[i].burst_time > 0) 
            { 
                  total = total + roundRobin[i].burst_time; 
                  roundRobin[i].burst_time = 0; 
                  counter = 1; 
            } 
            else if(roundRobin[i].burst_time > 0) 
            { 
                  roundRobin[i].burst_time = roundRobin[i].burst_time - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(roundRobin[i].burst_time == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, roundRobin[i].ct, total - roundRobin[i].arrival_time, total - roundRobin[i].arrival_time - roundRobin[i].ct);
                  wait_time = wait_time + total - roundRobin[i].arrival_time - roundRobin[i].ct; 
                  turnaround_time = turnaround_time + total - roundRobin[i].arrival_time; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(roundRobin[i+1].arrival_time <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
}
void main()
{
      int i, time = 0, burst_time = 0, largest;
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            process_queue[i].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].arrival_time );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].burst_time);
            process_queue[i].ct = process_queue[i].burst_time;
            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i].priority);
            process_queue[i].status = 0;
            process_queue[i].enter = 0;
            burst_time = burst_time + process_queue[i].burst_time;
      }
      Arrival_Time_Sorting();
      process_queue[99].priority = -9999;
      //printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      int k = 0;
      int r = -1;
      largest = 0;
      int sub_time = 1;
      for(time = process_queue[0].arrival_time; time < burst_time;time++)
      {
            
            if(process_queue[largest].burst_time<=0){
            	//printf("i %c\n",process_queue[largest].process_name);
               	int end_time = time;
            	process_queue[largest].turnaround_time = end_time - process_queue[largest].arrival_time;
            	process_queue[largest].status = 1;
		    }
            for(i = 0; i < limit; i++)
            {
            	  if(process_queue[largest].status==1 && process_queue[i].arrival_time<=time){
            	  	largest = i;
				  }else if(process_queue[i].arrival_time <= time && process_queue[i].status != 1 && process_queue[i].priority > process_queue[largest].priority)
                  {
                  	    
                  	    //printf("in %c\n ",process_queue[largest].process_name);
                  	    int end_time = time;
                  	    process_queue[largest].turnaround_time = end_time - process_queue[largest].arrival_time;
                  	    
						r++;
						roundRobin[r] = process_queue[largest];
						roundRobin[r].arrival_time = time;
						roundRobin[r].ct = roundRobin[r].burst_time;
						process_queue[largest].enter = 1;
                  	    process_queue[largest].status = 1;
                  	    burst_time = burst_time - process_queue[largest].burst_time;
                        largest = i;
                        sub_time = 1;
                  }
            }
            process_queue[largest].burst_time = process_queue[largest].burst_time - sub_time;
            //printf("%c -> %d\n",process_queue[largest].process_name,process_queue[largest].burst_time);
            
			//printf("%c\n",process_queue[largest].process_name);
            /*time = time + process_queue[largest].burst_time;
            process_queue[largest].ct = time;
            process_queue[largest].waiting_time = process_queue[largest].ct - process_queue[largest].arrival_time - process_queue[largest].burst_time;
            process_queue[largest].turnaround_time = process_q
			ueue[largest].ct - process_queue[largest].arrival_time;
            process_queue[largest].status = 1;
            wait_time = wait_time + process_queue[largest].waiting_time;
            turnaround_time = turnaround_time + process_queue[largest].turnaround_time;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", process_queue[largest].process_name, process_queue[largest].arrival_time, process_queue[largest].burst_time, process_queue[largest].priority, process_queue[largest].waiting_time);
            */
	  }
	  //printf("outer %d",time);
	  int end_time = time;
      process_queue[largest].turnaround_time = end_time - process_queue[largest].arrival_time;
      int prC = 0;
      
	  for(prC;prC<limit;prC++){
        process_queue[prC].waiting_time =  process_queue[prC].turnaround_time - process_queue[prC].ct;
	  }
	  prC = 0;
	  for(prC;prC<=r;prC++){
	  	roundRobin[prC].waiting_time = roundRobin[prC].turnaround_time - roundRobin[prC].ct;
	  	//roundRobin[prC].arrival_time = time;
	  }
	  prC = 0;
	  printf("Waiting time of Interactive processes\n");
	  for(prC;prC<limit;prC++){
        if(process_queue[prC].enter!=1){
        	printf("%c => %d\n",process_queue[prC].process_name,process_queue[prC].waiting_time);
		}
	  }
	  
	  /*average_waiting_time = wait_time / limit;
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage waiting time:\t%f\n", average_waiting_time);
      printf("Average Turnaround Time:\t%f\n", average_turnaround_time);*/
      int l = 0;
      /*printf("%d\n",r);
	  for(l;l<=r;l++){
      	printf("%c => %d\n",roundRobin[l].process_name,roundRobin[l].burst_time);
	  }*/
	  
	  printf("\n");
	  printf("Enter the quantum time for roundRobin algorithm\n");
	  scanf("%d",&quant_time);
	  round_robin(quant_time,r+1);
      
}
