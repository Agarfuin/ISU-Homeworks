#include <stdio.h>
#include <string.h>

int count_paragraphs(char text[1000],int sentences_each_paragraph[10]);
int find_highest(int sentences_each_paragraph[10],int num);
int search(char text[2000], char keyword[20]);
int get_integers(char text[2000], int years[100],char file_name[20]);

int main(void) {
  char parameters[4][20];
  char text[2000],line[100];
  int counter=0,num_of_paragraphs,sentences_each_paragraph[10],years[100];

  FILE * fptr;
  
  printf("Please enter the file name.\n");
  scanf("%s",parameters[0]);
  printf("Please enter the name.\n");
  scanf(" %[^\n]%*c", parameters[1]);
  printf("Please enter the author.\n");
  scanf(" %[^\n]%*c", parameters[2]);
  printf("Please enter the file protagonist.\n");
  scanf(" %[^\n]%*c", parameters[3]);
  
  fptr = fopen(parameters[0],"r");

  if(fptr != NULL){
    while(fgets(line,100,fptr)!=NULL)
      strcat(text,line);
  }
  else{
    printf("File cannot be opened.");
  }


  fclose(fptr);

  num_of_paragraphs = 1 + count_paragraphs(text,sentences_each_paragraph);
  printf("\n");

  for(int i = 0; i < num_of_paragraphs; i++){
    printf("num of sentences in paragraph %d:%d\n",i+1,sentences_each_paragraph[i]);
  }
  int a = find_highest(sentences_each_paragraph,num_of_paragraphs);
  printf("paragraph %d has the most number of sentences: %d\n",a+1, sentences_each_paragraph[a]);
  for(int i=1;i<4;i++){
    printf("num of %s: %d\n",parameters[i],search(text,parameters[i]));
  }
  counter = get_integers(text,years,parameters[0]);  
  for(int i=0;i<counter;i++){
      printf("%d,",years[i]);
  }
  printf("\n");
  return 0;
}


int count_paragraphs(char text[1000],int sentences_each_paragraph[10]){
    int index = 0, sentence_counter = 0, x = 0;
    while(text[index] != '\0'){
        printf("%c",text[index]);
        if(text[index] == '.')
            sentence_counter++;

        if(text[index] == '\n')
            if(text[index+2] == '\n'){
                sentences_each_paragraph[x] = sentence_counter;
                sentence_counter = 0;
                x++;
                index+=2;    
            }

        index++;
    }
    sentences_each_paragraph[x] = sentence_counter;
    return x;
}

int find_highest(int sentences_each_paragraph[10],int num){
    int index = 0, highest;
    highest = sentences_each_paragraph[0];
    for(int i = 0; i <= num; i++){
        if(sentences_each_paragraph[i]>highest)
            index = i;   
    }

    return index;
}

int search(char text[2000], char keyword[20]){
    int len1,len2,counter,word_count=0,i,j;

    len1 = strlen(text);

    len2 = strlen(keyword);

    for (i = 0; i < len1; i++){
        j = 0;
        counter = 0;
        while (text[i] == keyword[j]){
            counter++;
            i++;
            j++;
        }
        if (counter == len2){
            word_count++;                                   
            counter = 0;
        }

    }

    return word_count;
}


int get_integers(char text[2000], int years[100],char file_name[20]){
    int ret,val,count=0,x,year_storage[100],counter=0;
    char temp;
    FILE * fp;

    fp = fopen(file_name,"r");

    while((ret=fscanf(fp,"%d",&val)) != EOF){
        if(ret == 1){
            year_storage[count] = val;
            count++;
        }
        else
            fscanf(fp,"%c",&temp);

    }

    for(int i = 0; i < count; i++){
        x = year_storage[i] / 100;
        if(x == 18 || x == 19 || x == 20){
            years[counter] = year_storage[i];
            counter++;
        } 
    }
    fclose(fp);
    return counter;
}