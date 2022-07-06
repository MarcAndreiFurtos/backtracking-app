#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// array in which we recreate the maze
char maze[1000][1000];
// maze size on x and y axis
int x,y;
// this function reads a line from the maze at a time and gets 
// the length for for the x and y coordinates 
void maze_lenght(FILE *input){
    char buffer[1001];
	int ok = 0;
	while(fgets(buffer,1000,input))
	{
		y++;
		if(ok < 2)
		{
			ok++;
			x = strlen(buffer);
		}
 } 
 fseek(input,0,SEEK_SET);
}


// this function initializes the maze as a character array 
void initialize_maze(FILE *input){
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
		{
			fscanf(input,"%c",&maze[i][j]);
		}
	}
}
// this function prints the maze ,it will be used inside of a diferent function 
// and called once the function finds the exit 
void printf_solution(){
    FILE *output = fopen("solution.dat","w");
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
		{
			fprintf(output,"%c",maze[i][j]);
		}
	}
}
int movexy(int i, int j)
{
   
	if(maze[i][j] == 'E')
	{
		printf_solution();
	}
	if((i > 0) && (i < y) && (j > 0) && (j < x) && maze[i][j] != '#' && maze[i][j] != '.')
	{
		maze[i][j] = '.';
		movexy(i-1,j);
		movexy(i,j-1);
		movexy(i+1,j);
		movexy(i,j+1);
		maze[i][j] = ' ';
	}
	return 0;
}

 
int main(int argc , char *argv[]){
    if (argc<2){
        printf("please input more arguments");
        exit(EXIT_FAILURE);
    }
    FILE *input=fopen(argv[1],"r");
    if(!input){
        free(input);
        exit(EXIT_FAILURE);
    }
  
    maze_lenght(input);
    initialize_maze(input);
    movexy(1,1);
return 0;
}