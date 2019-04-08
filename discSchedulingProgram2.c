#include<stdio.h>
#include<conio.h>
int main()
{
             int queue[5000],n,head,i,j,k,seek=0,diff;
             float avg;
             // clrscr();
             printf("*** FCFS Disk Scheduling Algorithm ***\n");
             printf("Enter the size of Queue\t");
             scanf("%d",&n);
             printf("Enter the Queue\t");
             for(i=0;i<n;i++){
             	int a;
             	scanf("%d",&a);
             	queue[i] = a;
			 }
             head = 50;
             
             diff = abs(head-queue[0]);
             printf("%d\n",diff);
             seek+=diff;
			 for(j=0;j<n-1;j++)
             {
                          diff=abs(queue[j+1]-queue[j]);
                          seek+=diff;
                          printf("Move from %d to %d with Seek %d\n",queue[j],queue[j+1],diff);
             }
             printf("\nTotal Seek Time is %d\t",seek);
             avg=seek/(float)n;
             printf("\nAverage Seek Time is %f\t",avg);
             getch();
}

