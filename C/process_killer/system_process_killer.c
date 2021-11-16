#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <err.h>
#include <signal.h>
#include <string.h>


void get_rss_ind(FILE *fptr, int *lines, int *num_lines_rss);
void get_time_ind(FILE *fptr, int *lines, int *num_lines_time);
int find_pid(FILE *fptr, int line_ind);
void find_command(FILE *fptr, int line_ind);


int main(){
  	int lines_rss[20], lines_time[20];
	int num_lines_rss[0], num_lines_time[0];
	int pids[20], times[20];
	int counter=0, counter2=0, to_be_killed=-99, value=0;
	FILE *fptr;


	while(1){
		system("ps aux > psaux.txt");
		system("awk '{print $2}' psaux.txt > pid.txt");
		system("awk '{print $6}' psaux.txt > rss.txt");
		system("awk '{print $10}' psaux.txt > time.txt");
		system("awk '{print $11}' psaux.txt > command.txt");


		get_rss_ind(fptr, &(lines_rss[0]), &(num_lines_rss[0]));
		get_time_ind(fptr, &(lines_time[0]), &(num_lines_time[0]));
		

		printf("\nUsing more than 300K:\n");
		for(int i = 0; i<num_lines_rss[0]; i++){
			counter += 1;
			counter2 += 1;
			printf("%d- ", counter);
			find_command(fptr, lines_rss[i]);
			pids[counter-1] = find_pid(fptr, lines_rss[i]);
		}

		printf("\nRunnig more than 5 minutes:\n");
		for(int i = 0; i<num_lines_time[0]; i++){
			counter += 1;
			printf("%d- ", counter);
			find_command(fptr, lines_time[i]);
			pids[counter-1] = find_pid(fptr, lines_time[i]);
		}

		printf("\nEnter a number to kill(-1 to exit), or enter 0 for the next refresh ->");

		scanf("%d", &to_be_killed);

		if(to_be_killed == -1){
			printf("Entered -1 nothing going to be killed.\n");
			break;
		}
		else if(to_be_killed == 0){
			sleep(1);
			continue;
		}
		else if(to_be_killed > counter){
			printf("Entered wrong process index. Try again.");
			continue;
		}
		else if(to_be_killed < -1){
			printf("Entered wrong process index. Try again.");
			continue;
		}
		if(to_be_killed > counter2){
			printf("Program going to be killed is: %d\n", find_pid(fptr, lines_time[(to_be_killed-counter2)-1]));
			kill(find_pid(fptr, lines_time[(to_be_killed-counter2)-1]), 9);
			break;
		}
		else{
			printf("Program going to be killed is: %d\n", find_pid(fptr, lines_rss[to_be_killed-1]));
			kill(find_pid(fptr, lines_rss[to_be_killed-1]), 9);
			break;
		}
	}


	printf("Program successfully executed. Terminating...\n");
	return 0;
}


void get_rss_ind(FILE *fptr, int *lines, int *num_lines_rss){
	int counter, counter2=0, line_count=1, temp;
	char ch, number[10];
	fptr = fopen("rss.txt", "r");

	if(fptr == NULL){
		perror("Unable to open the file.");
		exit(1);
	}

	char line[20];
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			temp = atoi(number);
			if((temp/1000) >= 300){
				*(lines + counter2) = line_count;
				counter2 += 1;
				temp = 0;
			}
			memset(number, 0, sizeof(number));
			counter = 0;
			line_count += 1;
		}
		else{
			number[counter] = ch;
			counter += 1;
		}
	}
	if((ch = fgetc(fptr)) == EOF){
		temp = atoi(number);
		if(temp >= 500){
			*(lines + counter2) = line_count;
			counter2 += 1;
			temp = 0;
		}
		memset(number, 0, sizeof(number));
		counter = 0;
		line_count += 1;
	}

	fclose(fptr);
	*num_lines_rss = counter2;
}


void get_time_ind(FILE *fptr, int *lines, int *num_lines_time){
	int counter, counter2=0, line_count=1, temp;
	char ch, time[10], temp_time[3];
	fptr = fopen("time.txt", "r");

	if(fptr == NULL){
		perror("Unable to open the file.");
		exit(1);
	}

	char line[20];
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			if(time[0] == 'T'){
				memset(time, '\0', sizeof(time));
				counter = 0;
				line_count += 1;
				continue;
			}
			if(strlen(time) >= 8){
				*(lines + counter2) = line_count;
				counter2 += 1;
				memset(time, '\0', strlen(time));
				counter = 0;
				line_count += 1;
			}
			else{
				temp_time[0] = time[counter-7];
				temp = atoi(temp_time);
				if(temp >= 5){
					*(lines + counter2) = line_count;
					counter2 += 1;
					temp = 0;
				}
				memset(time, '\0', sizeof(time));
				memset(temp_time, '\0', sizeof(temp_time));
				counter = 0;
				line_count += 1;
			}
		}
		else{
			time[counter] = ch;
			counter += 1;
		}
	}

	fclose(fptr);
	*num_lines_time = counter2;
}


int find_pid(FILE *fptr, int line_ind){
	char ch, pid[6];
	int line_count=1, counter=0, temp;

	fptr = fopen("pid.txt", "r");

	if(fptr == NULL){
		perror("Unable to open the file.");
		exit(1);
	}

	char line[6];
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			if(line_ind == line_count){
				temp = atoi(pid);
				break;
			}
			memset(pid, '\0', sizeof(pid));
			line_count += 1;
			counter = 0;
		}
		else
			if(line_ind == line_count){
				pid[counter] = ch;
				counter += 1;
			}
	}

	fclose(fptr);
	return temp;
}


void find_command(FILE *fptr, int line_ind){
	char ch, command[500];
	int line_count=1, counter=0;

	fptr = fopen("command.txt", "r");

	if(fptr == NULL){
		perror("Unable to open the file.");
		exit(1);
	}

	char line[500];
	while((ch = fgetc(fptr)) != EOF){
		if(ch == '\n'){
			if(line_count == line_ind){
				printf("%s\n", command);
				break;
			}
			line_count += 1;
			counter = 0;
		}
		else
			if(line_ind == line_count){
				command[counter] = ch;
				counter += 1;
			}
	}

	fclose(fptr);
}




