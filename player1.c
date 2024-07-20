#include<stdio.h>
#include<string.h>
struct Player
{
	int jersey_number;
	char name[20];
	int runs;
	int wickets;
	int matches_played;
};

void add_player(struct Player playersarr[],int*);
void added_payers(struct Player*, int* );
void delete_player(struct Player playersarr[],int*);
void search_player(struct Player playersarr[],int*);
void update_player(struct Player playersarr[],int);
void display_top_players(struct Player playersarr[],int);
void display_all_players(struct Player playersarr[], int);

void main()
{
	int size=6;
	struct Player playersarr[100];
	int choice;
	int digit;
	added_players(playersarr,&size);
	
	do
	{
		printf("\n >>>>> PLAYER MANAGEMENT <<<<<\n");
		printf("  1. Add Player\n");
		printf("  2. Delete Player\n");
		printf("  3. Search Player\n");
		printf("  4. Update Player Data\n");
		printf("  5. Display Top Players\n");
		printf("  6. Display All Players\n");
		printf("  7. Exit...\n");
		printf(" \nEnter Your Choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				{
					add_player(playersarr,&size);
					break;
				}
			case 2:
				{
					delete_player(playersarr,&size);
                	break;
            	}
            case 3:
            	{
                	search_player(playersarr,&size);
                	break;
            	}
            case 4:
            	{
                	update_player(playersarr, size);
                	break;
            	}
            case 5:
            	{
            	    display_top_players(playersarr, size);
                	break;
            	}
            case 6:
            	{
            		display_all_players(playersarr, size);
            		break;
				}
			case 7:
				{
                	printf("Exiting...\n");
                	break;
                }
			default:printf("Invalid choice. Please try again.\n");
		}
		printf("\nDo You Want To Continue(Enter Any Digit):");
		scanf("%d",&digit);	
	}while(choice != 7);
}

//1.function 2 add player
void add_player(struct Player* playersarr,int* size)
{
	if(*size<100)
	{
		struct Player newplayer;
		
		printf("Enter Joursey Number :");
		scanf("%d",&newplayer.jersey_number);
		printf("Enter Player Name :");
		scanf("%s",&newplayer.name);
		printf("Enter Runs Scored :");
		scanf("%d",&newplayer.runs);
		printf("Enter Wickets Taken :");
		scanf("%d",&newplayer.wickets);
		printf("Enter Matches Played :");
		scanf("%d",&newplayer.matches_played);
		playersarr[*size]=newplayer;
		(*size)++;
		printf("Player Added Successfully\n");
	}
}

//2.function to remove a player
void delete_player(struct Player playersarr[],int*size)
{
	int index=-1;
	int i;
	int jerseynumber;
	printf("\nenter jersey number to remove :");
	scanf("%d",&jerseynumber);
	
	for(i=0;i<*size;i++)
	{
		if(playersarr[i].jersey_number==jerseynumber)
		{
			index=i;
			break;
		}
	}
	if(index!=-1)
	{
		for(i=index;i<*size-1;i++)
		{
			playersarr[i]=playersarr[i+1];
		}
		(*size)--;
		
		printf("player with jersey number %d remove successfully \n",jerseynumber);	
	}
	else
	{
		printf("Player not found.\n");
	}
}

//3.function to search for a player
void search_player(struct Player playersarr[],int *size)
{
	int choice;
    printf("\n1.Search by Jersey Number :");
    printf("\n2.Search by Player Name :");
    printf("\nPlease Enter (1. OR 2.) :");
    scanf("%d", &choice);
    
    int jerseynumber;
    char searchname[20];
	int found=0;
	int i;
	
	switch(choice)
	{
		case 1:
			{
				printf("\nEnter Jersey Number :");
				scanf("%d",&jerseynumber);
				
				for(i=0;i<*size;i++)
				{
					if(playersarr[i].jersey_number==jerseynumber)
					{
						printf("\n     ....Player Found....\n       ");
						printf("\n--------------------------------\n");
						printf("\nJersey Number   :>      %-10d\n",playersarr[i].jersey_number);
						printf("--------------------------------\n");
						printf("Player Name     :>      %-10s\n",playersarr[i].name);
						printf("--------------------------------\n");
						printf("Runs Scored     :>      %-10d\n",playersarr[i].runs);
						printf("--------------------------------\n");
						printf("Wickets Taken   :>      %-10d\n",playersarr[i].wickets);
						printf("--------------------------------\n");
						printf("Matches Played  :>      %-10d\n",playersarr[i].matches_played);
						printf("--------------------------------\n");
						
						found=1;
						break;
					}
				}
				if(!found)
				{
					printf("player not found\n");
				}
			}
			break;
			
		case 2:
			{
				printf("Enter Player Name :");
				scanf("%s",&searchname);
					
				for(i=0;i<*size;i++)
				{
					if(strcmp(playersarr[i].name,searchname)==0)
					{
						printf("\n     ....Player Found....\n       ");
						printf("\n--------------------------------\n");
						printf("\nJersey Number   :>      %-10d\n",playersarr[i].jersey_number);
						printf("--------------------------------\n");
						printf("Player Name     :>      %-10s\n",playersarr[i].name);
						printf("--------------------------------\n");
						printf("Runs Scored     :>      %-10d\n",playersarr[i].runs);
						printf("--------------------------------\n");
						printf("Wickets Taken   :>      %-10d\n",playersarr[i].wickets);
						printf("--------------------------------\n");
						printf("Matches Played  :>      %-10d\n",playersarr[i].matches_played);
						printf("--------------------------------\n");
						found=1;
						break;
					}
				}
				if(!found)
				{
					printf("player not found\n");
				}
			}
			break;
	}
}

//4.function to update player data
void update_player(struct Player playersarr[],int size)
{
	int found=0;
	int i;
	
	int jerseynumber;
    printf("\nEnter Jersey Number to update: ");
    scanf("%d", &jerseynumber);
	
	for(i=0;i<size;i++)
	{
		if(playersarr[i].jersey_number==jerseynumber)
		{
			printf("Enter New Runs Scored :");
			scanf("%d",&playersarr[i].runs);
			printf("Enter New Wickets Taken :");
			scanf("%d",&playersarr[i].wickets);
			printf("Enter New Matches Played :");
			scanf("%d",&playersarr[i].matches_played);
			printf("player data updated successfully\n");
			found=1;
			break;
		}
	}
	if(!found)
	{
		printf("Player not found.\n");
	}
	
}

//5.function to display a top 3 players
void display_top_players(struct Player playersarr[],int size)
{
	//sort players by runs
	int choice;
	printf("\n1.Top Players by Runs :");
    printf("\n2.Top Players by Wickets :");
    printf("\nPlease Enter (1. OR 2.) :");
    scanf("%d", &choice);
	int i,j;
	
	switch(choice)
	{
		case 1:
		{
			for(i=1;i<size;i++)
			{
				for(j=0;j<size-i;j++)
				{
					if(playersarr[j].runs<playersarr[j+1].runs)
					{
						struct Player temp=playersarr[j];
						playersarr[j]=playersarr[j+1];
						playersarr[j+1]=temp;
					}
				}
			}
			//display
			//printf("\nTop 3 Players by Runs :\n");
			printf("\n                ****TOP 3 PLAYERS****\n         ");
  		printf("\n--------------------------------------------------------\n"); 
    		printf("  |   NO.  |       PLAYER NAME       |      Runs     |\n"); 
    		printf("-------------------------------------------------------\n");    

			for(i=0;i<size && i<3;i++)
			{
				printf("  |%5d   |%16s         |%10d     |\n",i+1,playersarr[i].name,playersarr[i].runs);

			printf("--------------------------------------------------------\n");
			}
		}
		break;
		
		case 2:
		{
			for(i=1;i<size;i++)
			{
				for(j=0;j<size-i;j++)
				{	
					if(playersarr[j].wickets<playersarr[j+1].wickets)
					{
						struct Player temp=playersarr[j];
						playersarr[j]=playersarr[j+1];
						playersarr[j+1]=temp;
					}
				}
			}
			//display
			//printf("\nTop 3 Players by Runs :\n");
			printf("\n                ****TOP 3 PLAYERS****\n         ");
  		printf("\n--------------------------------------------------------\n"); 
    		printf("  |   NO.  |       PLAYER NAME       |      Wickets     |\n"); 
    		printf("-------------------------------------------------------\n");    

			for(i=0;i<size && i<3;i++)
			{
				printf("  |%5d   |%16s         |%10d     |\n",i+1,playersarr[i].name,playersarr[i].wickets);

			printf("--------------------------------------------------------\n");
			}
		}
		break;
	}
}

//6.function display all players
void display_all_players(struct Player* playersarr,int size)
{
	    int i;
        printf("                             ....***ALL PLAYER RECORD***....                           ");
		printf("\n");
		printf("---------------------------------------------------------------------------------------------\n");
		printf("|   JERSY NO.   |       NAME       |      RUN         |      WICKET      |   NO.Of MATCHES  |\n");
		printf("---------------------------------------------------------------------------------------------\n");
		for(i=0;i<size;i++)
		{
			printf("|     %-10d|       %-11s|      %-11d |  %8d        |%10d        |\n",playersarr[i].jersey_number,playersarr[i].name,playersarr[i].runs,playersarr[i].wickets,playersarr[i].matches_played);
    	printf("---------------------------------------------------------------------------------------------\n");
		}
}

//7. hardcodded function
void added_players(struct Player playersarr[], int* size) 
{
	playersarr[0].jersey_number=07;
	strcpy(playersarr[0].name,"Dhoni");
	playersarr[0].runs=8000;
	playersarr[0].wickets=160;
	playersarr[0].matches_played=115;
	
	playersarr[1].jersey_number=18;
	strcpy(playersarr[1].name,"Virat");
	playersarr[1].runs=12500;
	playersarr[1].wickets=180;
	playersarr[1].matches_played=105;
	
	playersarr[2].jersey_number=45;
	strcpy(playersarr[2].name,"Rohit");
	playersarr[2].runs=7000;
	playersarr[2].wickets=110;
	playersarr[2].matches_played=160;
	
	playersarr[3].jersey_number=10;
	strcpy(playersarr[3].name,"Sachin");
	playersarr[3].runs=12000;
	playersarr[3].wickets=370;
	playersarr[3].matches_played=230;
	
	playersarr[4].jersey_number=34;
	strcpy(playersarr[4].name,"Hardik");
	playersarr[4].runs=4500;
	playersarr[4].wickets=230;
	playersarr[4].matches_played=135;
	
	playersarr[5].jersey_number=20;
	strcpy(playersarr[5].name,"Bumrah");
	playersarr[5].runs=3600;
	playersarr[5].wickets=670;
	playersarr[5].matches_played=155;
}
