#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

char * s_gets(char * st,int n);

int main(void)
{
	Queue line;
	Node * ground[3]={NULL,NULL,NULL};
	Node * batter;
	Item temp;
	int game_count;
	int game;
	int count;
	char batting_average[16];
	char Slugging_percentage[16];
	int inning=9;
	int inning_count;
	int out;
	double hit_temp; 
	int hit_base=0;
    srand((unsigned int)time(0));
	InitializeQueue(&line);
    puts("Welcome to Batting simulation!");
	puts("Now Enter how many game your want to play.");
	scanf("%d",&game);
	eatline();
	puts("Enter the player first name.");	
	while((s_gets(temp.first_name,20)!=NULL)&&temp.first_name[0]!='\0')
	{
		puts("Enter the player last name.");	
		if((s_gets(temp.last_name,20)!=NULL)&&temp.last_name[0]!='\0')
		{
			printf("Enter batting average rate of the player.\n");
			scanf("%lf",&temp.bat_avg);
			printf("Enter Slugging percentage of the player.\n");
			eatline();
			scanf("%lf",&temp.Slugging_percentage);
			temp.Run_Bat_In=0;
			temp.Home_Run=0;
			if(AddItem(temp,&line)==false)
			{
				fprintf(stderr,"Problem allocating memory.\n");
				break;
			}
			if(QueueIsFull(&line))
			{
				puts("The list is now full.");
				break;
			}
			puts("Enter the next player first_name");
			eatline();
		}
	}
	if(QueueIsEmpty(&line))
		printf("No data entered");
	else
	{
		printf("Here is the roster\n");
	    traverse(&line);
	}
	for(game_count=0;game_count<game;game_count++)
	{
	batter=line.front;
	for(inning_count=0;inning_count<=inning;inning_count++)
	{
		out=0;
		while(out<3)
		{
		hit_temp=rand()%100;
		hit_temp/=100;
		if(hit_temp>=batter->player.bat_avg)
		{
		   out++;
		   batter=batter->next;
		}
		else
		{
					hit_temp=rand()%100;
		            hit_temp/=100;
					if(hit_temp>=batter->player.Slugging_percentage)
					{
						hit_temp=rand()%3;
						if(hit_temp>=2)
							batter->player.Home_Run++;
						for(count=2;count>0;count--)
						{
							if(ground[count]!=NULL)
							{
								if(count+hit_temp+1>=3)
								{
									batter->player.Run_Bat_In++;
									ground[count]=NULL;
								}
								else 
								{
									ground[count+(int)hit_temp]=ground[count];
									ground[count]=NULL;
								}
							}
						}
					    ground[(int)hit_temp]=batter;
						batter=batter->next;
					}
					else
					{
						if(ground[2]!=NULL)
						{
						   batter->player.Run_Bat_In++;
						   ground[2]=NULL;
						}
						for(count=1;count>0;count--)
						{
							ground[count+1]=ground[count];
							ground[count]=NULL;
						}
						ground[0]=batter;
						batter=batter->next;
					}
		}
		}
        for(count=0;count<2;count++)
        {
		ground[count]=NULL;	
		}		
	}
	}
	traverse_score(&line);
	return 0;
}

char * s_gets(char * st,int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if(ret_val)
	{
		find=strchr(st,'\n');
		if(find)
			*find='\0';
		else
		{
				while(getchar()!='\n')
		continue;	
		}
	}
	return ret_val;
}