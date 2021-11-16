/*

Written by Harun Selman Karakaş - 2021

*/

/*

IMPORTANT!!!!!

Before starting keep in mind that this code will only work in UNIX based systems!
So if you try to run this file on a Windows OS machine, it probably will not work.

*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>


#define BUFFER_SIZE 1000


int indexOf(FILE *fptr, const char *word, int *line, int *col);
int pid_collector(int line_ind, char *file_path);


int main() {

	FILE *fptr;
    char file_path[100] = "";							//Enter here path of the psaux.txt file (If you didn't change anything on the code its going to be at desktop) you created (See line 40 for more information)
    char word[50] = "";									//Enter here name of the process you want to kill immediately (E.g. Safari, Spotify, Sublime Text, etc.)
    int line, col, pid;

    while(1){
	    system("cd ~/Desktop && ps aux > psaux.txt");	//Creates a txt file at desktop named psaux that includes all the system processes currently working


	    fptr = fopen(file_path, "r");

	    if (fptr == NULL){
	        printf("Unable to open file.\n");
	        printf("Please check you have read/write previleges.\n");

	        exit(EXIT_FAILURE);
	    }

	    if(indexOf(fptr, word, &line, &col) != -1){
	    	pid = pid_collector(line, file_path);
	    	printf("PID of Sublime Text is %d on the line %d\n", pid, line);
	    	kill(pid, 9);
	    	printf("Program successfully executed.\n");
	    	break;
	    }
	    else{
	    	printf("Program still working, going to sleep for 1 sec.\n");
	    	sleep(1);
	    }
	    
	}

	fclose(fptr);
    return 0;
}


int indexOf(FILE *fptr, const char *word, int *line, int *col){
    char str[BUFFER_SIZE];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL){
        *line += 1;

        pos = strstr(str, word);

        if (pos != NULL){
            *col = (pos - str);
            break;
        }
    }

    if (*col == -1)
        *line = -1;

    return *col;
}


int pid_collector(int line_ind, char *file_path){

	int ret, val, pid;
	char temp;

    FILE* file = fopen(file_path, "r");

    char line[256];

    int i = 0;

    while (fgets(line, sizeof(line), file)) {

        i++;

        if(i == line_ind ){

	        while((ret=fscanf(file,"%d",&val)) != EOF){
	        	if(ret == 1){
	            	pid = val;
	            	break;
	        	}
	        	else
	            	fscanf(file,"%c",&temp);
	        } 
	    }
	}

    fclose(file);

    return pid;

}









