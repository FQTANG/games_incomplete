int MakeTeam(const Queue * team){
	puts("made team");
	puts("1 from keyboard 2 from files");
	int select=0;
	while(scanf("%d",&select)!=1);
	select==1?TeamLoadKeyboard:select==2?TeamLoadFile(team);:puts("error");//１であればキーボートによってチームを作る。そうでなければ２の場合ファイルからチームロースターをよみ取る。
	return 1;
}

int TeamLoadFile(const Queue * team){
	FILE *fp=NULL;
	eatline();//バッファを掃除する。
	char filename[256];
	int i=0;
	char ch;
	while((ch=getchar())!='\0'){//ファイル名を読み取る
		filename[i]=ch;
		i++;
	}
	filename[i]='\0';//文字列にする
	fp=fopen(filename."a");//ファインをオープン
	InitializeQueue(team);//チームを処理する
	TeamAddPlayer(team,fp);
	return 0;
}

int TeamLoadKeyboard(Queue * team){
	InitializeQueue(team);//チームを処理する
	TeamAddPlayer(team,stdin);
	return 0;
}
int TeamAddPlayer(Queue * team,FILE * fp){
	item * temp;
	int i=0;
	while(1){
		eatline();
		if(fscanf(fp,"%s %s %lf %lf 0 0",&temp->first_name,&temp->last_name,&temp->bat_avg,&temp->Slugging_percentage,&temp->Run_Bat_In,&temp->Home_Run)!=6)
			break;
		i++;
		AddItem(temp,team);
	}
	
	if(i<9)
		puts("player not enough ");
}

int TeamEditPlayer(Queue * team){
	traverse(team);
	puts("enter player name that you want edited");
	char first_name[20];
	char last_name[20];
	item * player=NULL
	if(scanf("%s %s",first_name,last_name)==2)
		player=SeekPlayer(first_name,last_name,team);//プレーヤーを探す
	else
		puts("Error");
	if(!player)
		return 0;
	EditMenu();　//メニューを書く
	int option=0;
	scanf("%d",&option);
	switch(player){ //プレーヤーを処理する
	           case 1 :
         			   scanf("%s",&player->first_name);
			          break;
			   case 2 :
			           scanf("%s",&player->last_name);
	                   break;
			  case 3 : 
			           scanf("%s",&player->bat_avg);
                       break;
               case 4 :
                        scanf("%s",&player->Slugging_percentage);
                       break;
			   case 5 :
			            scanf("%s",&player->Run_Bat_In);
                       break;
				case 6 :
				        scanf("%s",&player->Home_Run);
                       break;
				default : puts("Exit");
				         break;
	}
    return 0;	
}
item * SeekPlayer(char * f_name,char * l_name,Queue * team){
	if(QueueIsEmpty(team)==0)
		return NULL;
	Node * seek=team->front;
	int count=0;
	while(1){
		if(strcmp(f_name,seek->player->first_name)==0)
			if(strcmp(l_name,seek->player->last_name)==0)
				break;
		seek=seek->next;
		count++;
		if(count>team->items)
			return NULL;
	}
	return seek;
}
void EditMenu(void){
	puts("1 first_name 2 last_name 3 bat_avg ");
	puts("4 Slugging_percentage 5 Run_Bat_In 6 Home_Run ");
	return;
}
int TeamBattingOrder(Queue * team,Queue * order){
	traverse(team);
	char first_name[20];
	char last_name[20];
	item * player=NULL
	int count=0
	for(;count<9;count++){
	if(scanf("%s %s",first_name,last_name)==2)
		player=SeekPlayer(first_name,last_name,team);
	AddItem(*player,order)
	}
	return 0;
}
