
#include <stdio.h>

void display(char *ttt){
	printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n",ttt[0],ttt[1],ttt[2],ttt[3],ttt[4],ttt[5],ttt[6],ttt[7],ttt[8]);
}



int game_status(char *ttt){
	
	// horizontal
    if ((ttt[1-1] == ttt[2-1]) && (ttt[2-1] == ttt[3-1])) 
		return 1;
    else if (ttt[4-1] == ttt[5-1] && ttt[5-1] == ttt[6-1])
        return 1;
    else if (ttt[7-1] == ttt[8-1] && ttt[8-1] == ttt[9-1])
        return 1;

    // vertical
    else if (ttt[1-1] == ttt[4-1] && ttt[4-1] == ttt[7-1])
        return 1;
    else if (ttt[2-1] == ttt[5-1] && ttt[5-1] == ttt[8-1])
        return 1;
    else if (ttt[3-1] == ttt[6-1] && ttt[6-1] == ttt[9-1])
        return 1;

    // diagonal
    else if (ttt[1-1] == ttt[5-1] && ttt[5-1] == ttt[9-1])
        return 1;
    else if (ttt[7-1] == ttt[5-1] && ttt[5-1] == ttt[3-1])
        return 1;
		
	else{
		return 0;
		}
}


void update_board(char *ttt, int postion,char symbol){
	
	ttt[postion-1] = symbol ; 

}

int validation(char *ttt, int pos)
{
	
	if(pos > 9 && pos < 1){
		return 0 ;
	}
	else if (ttt[pos] == 'X' || ttt[pos] == 'O'){
		return 0 ;
	}
	else{
		return 1 ; 
	}
	
}



int main(){
	
	char ttt[9];
	int user1, user2 ;
	
	for (int i = 49, j = 0 ; i < 49+10 ; i++,j++ ){
		ttt[j] = i;
	
	}
	

	while (1) {
		 
			printf("Position for User 1 (X) : \n");
			scanf("%d",&user1);
			update_board(ttt,user1,'X');
				
			display(ttt);

			if (game_status(ttt) == 1){
				printf("User 1 (X) won.\n");
				break;
				
			}
						
			
			printf("Position for User 2 (O) : \n");
			scanf("%d",&user2);
			update_board(ttt,user2,'O');
				
				
			if (game_status(ttt) == 1){
				printf("User 2 (O) won.\n");
				break;
				
			}
			
			display(ttt);
		
	}
	
	return 0 ;
	
	
	
	
	
	
}