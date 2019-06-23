#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
void main_manu(void);

int main(){
	;
	main_manu();
	unsigned int team_number=0;
	while(scanf("%d",&team_number)==1){
		teams ** league=(teams **)malloc(team_number*sizeof(teams **));
		for(int i=0;i<team_number;i++){
			 league[i]=(teams *)malloc(team_number*sizeof(teams *));
			 MakeTeam(league[i]);
		}
		puts("Enter the games");
		unsigned int games=0;
		scanf("%d",&games);
		teams ** league_schedule;
		league_schedule=made_schedule(league,games):
	}
	
}
void main_manu(void){
	puts("Welcome to Batting simulation!");
	puts("Now enter the number of team in your league");
}