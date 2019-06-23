int MakeTeam(Queue * team);
int TeamLoadFile(Queue * team);
int TeamLoadKeyboard(Queue * team);
int TeamAddPlayer(Queue * team);
int TeamEditPlayer(Node * player);
int TeamBattingOrder(Queue * team,Queue * order);
item * SeekPlayer(char * f_name,char * l_name,Queue * team);