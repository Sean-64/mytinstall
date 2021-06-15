#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


//This function is to clear the current terminal
int cls(){
	printf("\e[1;1H\e[2J");
}

int cRESET(){
	printf("\033[0m");
}

int cCYAN(){
	printf("\033[0;36m");
}

//All the basic GUI
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* ascii = "::::    ::::  :::   ::: ::::::::::: ::::::::::: ::::    :::  :::::::: ::::::::::: :::     :::        :::       \n+:+:+: :+:+:+ :+:   :+:     :+:         :+:     :+:+:   :+: :+:    :+:    :+:   :+: :+:   :+:        :+:       \n+:+ +:+:+ +:+  +:+ +:+      +:+         +:+     :+:+:+  +:+ +:+           +:+  +:+   +:+  +:+        +:+       \n+#+  +:+  +#+   +#++:       +#+         +#+     +#+ +:+ +#+ +#++:++#++    +#+ +#++:++#++: +#+        +#+       \n+#+       +#+    +#+        +#+         +#+     +#+  +#+#+#        +#+    +#+ +#+     +#+ +#+        +#+       \n#+#       #+#    #+#        #+#         #+#     #+#   #+#+# #+#    #+#    #+# #+#     #+# #+#        #+#       \n###       ###    ###        ###     ########### ###    ####  ########     ### ###     ### ########## ##########";

char* menu = "                                                   (Menu) \n_______________________________________________________________________________________________________________";


char* menuFeed =" 1 - Normal				[Download tracks one by one]\n\n 2 - Playlist				[Download entiere playlist]\n\n 3 - Custom				[Download in choosen folder]\n\n 4 - Other				[Next side of Menu]"; 

char* other = "                                                   (Other) \n_______________________________________________________________________________________________________________";

char* otherFeed =" 5 - Addons				[Useful fonctionalities]\n\n 6 - Settings				[Customize stuff from mytinstall]\n\n 7 - Readme!				[Just need to read this !]\n\n 8 - Back 				[Go back to menu]";

char* music ="                                            (Simple Download)\n_______________________________________________________________________________________________________________";

char* musicFeed =" Paste the link : ";

char* playlist="                                               (Playlist)\n_______________________________________________________________________________________________________________";

char* playlistFeed =" Paste the link of the playlist : ";

char* custom="                                               (Custom)\n_______________________________________________________________________________________________________________";

char* customFeed ="";

char* addons="                                                (Addons)\n_______________________________________________________________________________________________________________";

char* addonsFeed ="";

char* settings ="                                                (Settings)\n_______________________________________________________________________________________________________________";

char* settingsFeed ="";

char* readme ="                                                (README)\n_______________________________________________________________________________________________________________";

char* readmeFeed ="";


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char choice;
int ytlink;


int main(){
//////////////////////////////////////////////////////////////////////////   Initialising basic directories
struct stat st = {0};							//
									//
if(stat("/home/sean64/Musique/mytinstall", &st) == -1) {		//
    mkdir("/home/sean64/Musique/mytinstall", 0700);			//
}									//
if(stat("/home/sean64/Musique/mytinstall/Music", &st) == -1) {		//
    mkdir("/home/sean64/Musique/mytinstall/Music", 0700);		//
}									//
if(stat("/home/sean64/Musique/mytinstall/Playlist", &st) == -1) {	//
    mkdir("/home/sean64/Musique/mytinstall/Playlist", 0700);		//
}									//
if(stat("/home/sean64/Musique/mytinstall/SoundBoard", &st) == -1) {     //
    mkdir("/home/sean64/Musique/mytinstall/SoundBoard", 0700);		//
}									//
//////////////////////////////////////////////////////////////////////////
 
MENU:

cls();
cCYAN();
printf("%s\n\n%s\n\n%s\n", ascii, menu,menuFeed);

scanf("%d", &choice);
do {
	switch(choice){
		case 1:
		cls();
		printf("%s\n\n%s\n\n%s", ascii, music, musicFeed);
		getchar();
		break;
	
		case 2:
		cls();
		printf("%s\n\n%s\n\n%s", ascii, playlist, playlistFeed);
		getchar();
		break;

		case 3:
	        cls();
		printf("%s\n\n%s\n\n%s", ascii, custom, customFeed);
		getchar();	
		break;

		case 4:
		cls();
		printf("%s\n\n%s\n\n%s\n", ascii, other, otherFeed);
		scanf("%d", &choice);
		OTHER: do {
			switch(choice){
				case 5:
				cls();
				printf("%s\n\n%s\n\n%s", ascii, addons, addonsFeed);
				getchar();
				break;
	
				case 6:
				cls();
				printf("%s\n\n%s\n\n%s", ascii, settings, settingsFeed);
				getchar();
				break;

				case 7:
				cls();
				printf("%s\n\n%s\n\n%s", ascii, readme, readmeFeed);
				getchar();
				break;

				case 8:
				goto MENU;
				break;

				default :
				choice = 0;
				break;
				}
			}while (choice > 0);	

		default :
		printf("ERROR             [Only use numbers and no other charachters] \n");
		cRESET();
		choice = 0;
		break;
	break;	}	
}while (choice > 0);


cRESET();
	return 0;
}