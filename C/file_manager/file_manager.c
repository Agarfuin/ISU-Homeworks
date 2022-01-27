/*

---------------------------------------------------------------------------INTRODUCTION---------------------------------------------------------------------------


Authors: Harun Selman Karakas, Umut Nuri Ugur, Sena Ozkanca - January 2022

This is a file management system that enables user to:

	1) Create a new file.
	2) Rename an existing file.
	3) Delete a file.
	4) Copy a file.
	5) Move a file from one directory to another.
	6) Append text at the end of a file.
	7) Insert text to the desired position of a file.
	8) Remove all the text from a file.
	9) Display the content of a file.

This work is done due to the term project for Istinye University COE303-Operating Systems course.
Lecturer: Dr. Ahmet Feyzi Ates

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void create_file(char *filename);
void rename_file(char *oldname, char *newname);
void delete_file(char *filename);
void copy_file(char *filename, char *newname);
void move_file(char *filename, char *destination);
void append_text(char *filename, char *content, int contentsize);
void insert_text(char *filename, char *content, int contentsize, int position);
void remove_all_text(char *filename);
void show_content(char *filename, int pagesize);
int count_characters(char *filename);
int does_exist(char *filename);
void flush_input();


int main(){
	char input[500];
	char function_name[500];
	char file_address[500];
	char new_address[500];
	char content[500];
	char number[10];
	int position;
	int pagesize;

	while(1){
		printf("Type 'help' to get information or if you want to get help on a specific command, you can also type 'command/h' for information about that command.\nType -1 to exit.\n\n");
		fgets(input, sizeof(input), stdin);
		input[strlen(input)-1] = '\0';

		sscanf(input, "%s", function_name);

		if(strcmp(function_name, "-1")==0){
			printf("\nEntered -1, terminating...\n");
			break;
		}

		if(strcmp(function_name, "help")==0){
			printf("\nHere are the commands that this program offers:\ncreate_file\t\t\trename_file\t\t\tdelete_file\ncopy_file\t\t\tmove_file\t\t\tappend_text\ninsert_text\t\t\tremove_all_text\t\t\tshow_content\n\nIMPORTANT REMINDER:\nFile names, directory paths should consist of English characters and shouldn't include white spaces inside!\nTexts to be inserted/appended also shouldn't contain non-English characters but can contain white spaces.\n\n");
			continue;
		}

		if(strcmp(function_name, "create_file/h")==0){
			printf("\ncreate_file function takes 1 parameter inside which is the name of the file.\nIf you want to create the file at the directory of this program, you can just pass the name or if you want to create it in some other directory, you need to pass the exact address.\nE.g. create_file test.txt or\ncreate_file C:\\Users\\User_Name\\Desktop\\test.txt\n\n");
			continue;
		}

		if(strcmp(function_name, "rename_file/h")==0){
			printf("\nrename_file function takes 2 parameters inside. First one is the file to be renamed and second one is the new name of the file.\nIf you want to rename the file at the directory of this program, you can just pass the name or if you want to create it in some other directory, you need to pass the exact address.\nE.g. rename_file file.txt new_name.txt or\nrename_file C:\\Users\\User_Name\\Desktop\\file.txt C:\\Users\\User_Name\\Desktop\\new_name.txt\n\n");
			continue;
		}

		if(strcmp(function_name, "delete_file/h")==0){
			printf("\ndelete_file function takes 1 parameter inside which is the name of the file.\nIf you want to delete the file at the directory of this program, you can just pass the name or if you want to delete file in some other directory, you need to pass the exact address.\nE.g. delete_file test.txt or\ndelete_file C:\\Users\\User_Name\\Desktop\\test.txt\n\n");
			continue;
		}

		if(strcmp(function_name, "copy_file/h")==0){
			printf("\ncopy_file function takes 2 parameters inside. First one is the file to be copied and second one is the name of the copy of the file.\nIf you want to copy the file at the directory of this program, you can just pass the name or if you want to create it in some other directory, you need to pass the exact address.\nE.g. copy_file file.txt copy_name.txt or\ncopy_file C:\\Users\\User_Name\\Desktop\\file.txt C:\\Users\\User_Name\\Desktop\\copy_name.txt\n\n");
			continue;
		}

		if(strcmp(function_name, "move_file/h")==0){
			printf("\nmove_file function takes 2 parameters inside. First one is the file to be moved and second one is the directory path for the file to be moved.\nIf you want to move the file at the directory of this program, you can just pass the name or if you want to move file from some other directory, you need to pass the exact address.\nRemember to include the slash(/)[if you are using a windows machine use backslash(\\) instead] at the end of the path.\nE.g. move_file file.txt C:\\Users\\User_Name\\Desktop\\ or\nmove_file C:\\Users\\User_Name\\Desktop\\file.txt C:\\Users\\User_Name\\Documents\\ or\nmove_file file.txt /home/user_name/desktop/\n\n");
			continue;
		}

		if(strcmp(function_name, "append_text/h")==0){
			printf("\nappend_text function takes 2 parameters inside. First one is the file to be text appended at the end and second one is the content of the text to be appended. The text to be appended can consists of maximum of 500 characters.\nIf you want to append text to the file at the directory of this program, you can just pass the name or if you want to append text to the file from some other directory, you need to pass the exact address.\nIMPORTANT REMINDER!\nUse double quotation marks \" not single quotation marks ' while writing your text.\nE.g. append_text file.txt \"Append this at the end of the file.\" or\nappend_text C:\\Users\\User_Name\\Desktop\\file.txt \"Append this at the end of the file.\"\n\n");
			continue;
		}

		if(strcmp(function_name, "insert_text/h")==0){
			printf("\ninsert_text function takes 3 parameters inside. First one is the file to be text inserted, second one is the content of the text to be inserted, and third one is the position of the text to be inserted. The text to be inserted can consists of maximum of 500 characters.\nHere position parameter is in order to character indices inside the file. Remember white spaces and new lines also counts as characters.\nIMPORTANT REMINDER!\nUse double quotation marks \" not single quotation marks ' while writing your text.\nE.g. insert_text file.txt \"Append this to the file.\" 5 or\ninsert_text C:\\Users\\User_Name\\Desktop\\file.txt \"Append this to the file.\" 5\n\n");
			continue;
		}

		if(strcmp(function_name, "remove_all_text/h")==0){
			printf("\nremove_all_text funciton takes 1 parameter inside which is the name of the file.\nIf you want to remove all the text of a file at the directory of this program, you can just pass the name or if you want to remove all the text of the file from some other directory, you need to pass the exact address.\nE.g. remove_all_text file.txt or\nremove_all_text C:\\Users\\User_Name\\Desktop\\file.txt\n\n");
			continue;
		}

		if(strcmp(function_name, "show_content/h")==0){
			printf("\nshow_content function takes 2 parameters inside. First one is the file to be shown its content and second one is the size of each page.\nIf you want to show contents of a file at the directory of this program, you can just pass the name or if you want to show content of a file from some other directory, you need to pass the exact address.\nHere size of each page refers to number of lines to be printed in each step. You can give any positive integer as page size.\nE.g. show_content file.txt 6 or\nshow_content C:\\Users\\User_Name\\Desktop\\file.txt 6\n\n");
			continue;
		}

		if(strcmp(function_name, "create_file")==0){
			sscanf(input, "%s %s", function_name, file_address);
			printf("\n");
			if(does_exist(file_address)!=0){
				create_file(file_address);
				printf("File successfully created. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				printf("File already exists. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
		}

		if(strcmp(function_name, "rename_file")==0){
			sscanf(input, "%s %s %s", function_name, file_address, new_address);
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(new_address, 0, sizeof(new_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				if(does_exist(new_address)!=0){
					rename_file(file_address, new_address);
					printf("File successfully renamed. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(new_address, 0, sizeof(new_address));
					memset(input, 0, sizeof(input));
					continue;
				}
				else{
					printf("New name of the file already exists. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(new_address, 0, sizeof(new_address));
					memset(input, 0, sizeof(input));
					continue;
				}
			}
		}

		if(strcmp(function_name, "delete_file")==0){
			sscanf(input, "%s %s", function_name, file_address);
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				delete_file(file_address);
				printf("File successfully deleted. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
		}

		if(strcmp(function_name, "copy_file")==0){
			sscanf(input, "%s %s %s", function_name, file_address, new_address);
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(new_address, 0, sizeof(new_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				if(does_exist(new_address)!=0){
					copy_file(file_address, new_address);
					printf("File successfully copied. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(new_address, 0, sizeof(new_address));
					memset(input, 0, sizeof(input));
					continue;
				}
				else{
					printf("Name of the file to be copied already exists. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(new_address, 0, sizeof(new_address));
					memset(input, 0, sizeof(input));
					continue;
				}
			}
		}

		if(strcmp(function_name, "move_file")==0){
			sscanf(input, "%s %s %s", function_name, file_address, new_address);
			printf("\n");
			file_address[strlen(file_address)] = '\0';
			new_address[strlen(new_address)] = '\0';
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(new_address, 0, sizeof(new_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				move_file(file_address, new_address);
				printf("File successfully moved. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(new_address, 0, sizeof(new_address));
				memset(input, 0, sizeof(input));
				continue;
			}
		}

		if(strcmp(function_name, "append_text")==0){
			sscanf(input, "%s %s", function_name, file_address);
			memset(content, 0, sizeof(content));
			for(int i = 0;i<strlen(input);i++){
				if(input[i]=='\"'){
					int j = 0;
					i++;
					while(input[i]!='\"'){
						content[j] = input[i];
						i++;
						j++;
					}
					break;
				}
			}
			content[strlen(content)] = '\0';
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(content, 0, sizeof(content));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				append_text(file_address, content, strlen(content));
				printf("Text successfully appended. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(content, 0, sizeof(content));
				memset(input, 0, sizeof(input));
				continue;
			}
		}

		if(strcmp(function_name, "insert_text")==0){
			sscanf(input, "%s %s %d", function_name, file_address, &position);
			memset(content, 0, sizeof(content));
			for(int i = 0;i<strlen(input);i++){
				if(input[i]=='\"'){
					int j = 0;
					i++;
					while(input[i]!='\"'){
						content[j] = input[i];
						i++;
						j++;
					}
					i++;
					content[j+1] = '\0';
					j = 0;
					while(input[i]!='\0'){
						number[j] = input[i];
						i++;
						j++;
					}
					position = atoi(number);
					break;
				}
			}
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(content, 0, sizeof(content));
				memset(input, 0, sizeof(input));
				position = -1;
				continue;
			}
			else{
				if(position<0){
					printf("Entered invalid position. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(content, 0, sizeof(content));
					memset(input, 0, sizeof(input));
					position = -1;
					continue;
				}
				else{
					insert_text(file_address, content, strlen(content), position);
					printf("Text successfully inserted. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(content, 0, sizeof(content));
					memset(input, 0, sizeof(input));
					position = -1;
					continue;
				}
			}
		}

		if(strcmp(function_name, "remove_all_text")==0){
			sscanf(input, "%s %s", function_name, file_address);
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
			else{
				remove_all_text(file_address);
				printf("All text successfully removed. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				continue;
			}
		}

		if(strcmp(function_name, "show_content")==0){
			sscanf(input, "%s %s %d", function_name, file_address, &pagesize);
			printf("\n");
			if(does_exist(file_address)!=0){
				printf("There is no such file exist. Returning to main menu...\n\n");
				memset(function_name, 0, sizeof(function_name));
				memset(file_address, 0, sizeof(file_address));
				memset(input, 0, sizeof(input));
				pagesize = -1;
				continue;
			}
			else{
				if(pagesize<=0){
					printf("Entered invalid pagesize. Returning to main menu...\n\n");
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(input, 0, sizeof(input));
					pagesize = -1;
					continue;
				}
				else{
					show_content(file_address, pagesize);
					memset(function_name, 0, sizeof(function_name));
					memset(file_address, 0, sizeof(file_address));
					memset(input, 0, sizeof(input));
					pagesize = -1;
					continue;
				}
			}
		}

		else{
			printf("You entered an invalid command. Returning to main menu...\n\n");
			memset(input, 0, sizeof(input));
			continue;
		}
	}

	return 0;
}


//Creates a file at the desired location
//Exits if fails
void create_file(char *filename){
	FILE *fptr;
	if((fptr = fopen(filename, "w")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	fclose(fptr);
	fptr = NULL;
}


//Checks wether a file in a specific location exists or not
//Returns 0 if exists unless 1
int does_exist(char *filename){
	if(access(filename, F_OK )==0)
		return 0;
	else
		return 1;
}


//Returns total number of characters inside a file
//Including whitespaces and line breaks
int count_characters(char *filename){
	FILE *fptr;
	int count = 0;
	char ch;
	if((fptr = fopen(filename, "r")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	while(!feof(fptr)){
		ch = fgetc(fptr);
		count++;
	}
	fclose(fptr);
	fptr = NULL;
	return count - 1;
}


void flush_input(){
	int ch;
	while((ch = getchar()) != '\n' && ch != EOF);
}


void rename_file(char *oldname, char *newname){
    FILE *fptr;
    char ch;
    int i=0;

	//Gets the number of characters inside the file given as input
    int size = count_characters(oldname);
    if((fptr = fopen(oldname, "r")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}

	//Copying all the content of input file to a local array
    char file[size];
    while((ch = fgetc(fptr)) != EOF ){
        file[i] = ch;
        i++;
    }
    fclose(fptr);

	//Creating a new file with the name given in input and
	//Writing coppied content to the new file
    FILE *newFptr;
	if((newFptr = fopen(newname, "w")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
    for(int i = 0;i<size;i++)
        fputc(file[i], newFptr);

    fclose(newFptr);
    newFptr = NULL;

	//Removes old file
   	remove(oldname);
}


//Deletes an existing file
void delete_file(char *filename){
	remove(filename);
}


void copy_file(char *filename, char *newname){
	FILE *fptr;
	char ch;
	int i=0;
	//Gets the number of characters inside the file given as input
	int size = count_characters(filename);

	if((fptr = fopen(filename, "r")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	
	//Copying all the content of input file to a local array
	char file[size];
	while((ch = fgetc(fptr)) != EOF){
		file[i] = ch;
		i++;
	}

	fclose(fptr);
	fptr = NULL;

	//Creating a new file with the name given in input and
	//Writing coppied content to the new file
	FILE *newFptr;
	if((newFptr = fopen(newname, "w")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	for(int i = 0;i<size;i++){
		fputc(file[i], newFptr);
	}

	fclose(newFptr);
	newFptr = NULL;
}


void move_file(char *filename, char *destination){
	char only_name[50];
	int j = 0;
	filename[strlen(filename)] = '\0';
	//This loop generates an array 'only_name'
	//Which basically consists of filename and extension of it without its path
	memset(only_name, 0, sizeof(only_name));
	for(int i = 0; i<strlen(filename); i++){
		if(filename[i] == '/' || filename[i] == '\\'){
			memset(only_name, 0, sizeof(only_name));
			j = 0;
			continue;
		}
		only_name[j] = filename[i];
		j++;
	}
	//Combines the file name(only name not its path) and the path to be moved 
	strcat(destination, only_name);
	destination[strlen(destination)] = '\0';
	//Creates a copy of old file in the path given in input
	//And removes old file
	rename_file(filename, destination);
}


void append_text(char *filename, char *content, int contentsize){
	FILE *fptr;

	//Opens the file in 'append' mode
	if((fptr = fopen(filename, "a")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	//Inserts text at the end of the file
	for(int i = 0;i<contentsize;i++){
		fputc(content[i], fptr);
	}

	fclose(fptr);
	fptr = NULL;
}


void insert_text(char *filename, char *content, int contentsize, int position){
	FILE *fptr;
	//Gets the number of characters inside the file given as input
	int size = count_characters(filename);

	//If user gives invalid location exits with error code 10
	if(size<position){
		printf("This file does not contain that position.\n");
		exit(10);
	}
	char newcontent[size+contentsize];
	char ch;
	int i=0, j=0;
	if((fptr = fopen(filename, "r")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}

	//Copying all the content of input file to a local array
	//Up until it reaches the position given in input
	//After it reaches the position,
	//Starts to write conent to be inserted which is given as input
	//After writing all the content wanted to be inserted,
	//Continues to write the file's content where it stopped
	while((ch = fgetc(fptr)) != EOF){
		if(i==position){
			while(content[j]!='\0'){
				newcontent[i] = content[j];
				i++;
				j++;
			}
		}
		newcontent[i] = ch;
		i++;
	}
	newcontent[i] = '\0';
	fclose(fptr);
	fptr = NULL;
	//Removes the file given as input
	remove(filename);

	//Creates a new file with same name as removed file
	//Writes all the stored content inside
	FILE *newFptr;
	if((newFptr = fopen(filename, "w")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}
	for(int i = 0;i<strlen(newcontent);i++){
		fputc(newcontent[i], newFptr);
	}
	
	fclose(newFptr);
	newFptr = NULL;
}


//Opens the file in write mode and does nothing
//Overwrites the content it previously had and now it has nothing inside
void remove_all_text(char *filename){
	fopen(filename, "w");
}


void show_content(char *filename, int pagesize){
	FILE *fptr;
	//Gets the number of characters inside the file given as input
	int size = count_characters(filename);
	int flag = -1;

	//Creates a char array with size of number of all the characters inside the file
	//In order to the possibility of the file being consist of only 1 line
	char line[size];
	char input, c;
	int line_count=0;
	int index=0;

	//Opens the file in 'reading' mode
	if((fptr = fopen(filename, "r")) == NULL){
		printf("Couldn't open the file.\n");
		exit(20);
	}

	//Stores all the characters inside the file up until it sees a line break
	//When it sees a line break prints everything it stored and increases counter as 1
	memset(line, 0, size);
	while((c=fgetc(fptr))!=EOF){
		if(c=='\n'){
			line_count += 1;
			line[index] = c;
			index++;
			printf("%s", line);
			//If counter mod pagesize equals 0 asks user if they want to continue reading or not
			if(line_count%pagesize==0){
				line_count = 0;
				printf("\nPress enter to continue, else to exit.\n");
				scanf("%c", &input);
				if(input!='\n'){
					printf("Entered something else. Returning to main menu..\n\n");
					flush_input();
					flag = 1;
					fclose(fptr);
					fptr = NULL;
					break;
				}
			}
			//Clears the array and sets index to 0
			memset(line, 0, size);
			index = 0;
		}
		else{
			line[index] = c;
			index++;
		}
	}
	//Finally prints the last line which was stored but couldn't printed.
	if(flag != 1){
		printf("%s\n", line);
		memset(line, 0, size);
		printf("Content successfully shown. Returning to main menu...\n\n");
		fclose(fptr);
		fptr = NULL;
	}
	flag = -1;
}









