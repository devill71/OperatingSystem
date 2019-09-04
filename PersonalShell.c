
// C Program to design a shell in Linux 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include<readline/readline.h> 
#include<readline/history.h> 
#include<sys/stat.h>
#include<fcntl.h> 
#define MAXCOM 1000 // max number of letters to be supported 
#define MAXLIST 100 // max number of commands to be supported 
  
// Clearing the shell using escape sequences 
#define clear() printf("\033[H\033[J") 
  
// Greeting shell during startup 
void init_shell() 
{ 
    clear(); 
    printf("\n\n\n\n******************"
        "************************"); 
    printf("\n\n\n\t****MY PERSONAL SHELL****"); 
    printf("\n\n\t-GROUP : 20-"); 
    printf("\n\n\n\n*******************"
        "***********************"); 
    char* username = getenv("USER"); 
    printf("\n\n\nUSER is: @%s", username); 
    printf("\n"); 
    sleep(1); 
    clear(); 
} 
  
// Function to take input 
int takeInput(char* str) 
{ 
    char buf[50]; 
  
    //scanf("%s",buf);
    gets(buf);
    if (strlen(buf) != 0) { 
         
        strcpy(str, buf); 
        return 0; 
    } else { 
        return 1; 
    } 
} 
  
// Function to print Current Directory. 
void printDir() 
{ 
    char cwd[1024]; 
    getcwd(cwd, sizeof(cwd)); 
    printf("\nDir: %s/$:", cwd); 
} 
  
// Function where the system command is executed 
void execArgs(char** parsed,int count)
{ 
     char *str=(char *)malloc(50*sizeof(char));
    // Forking a child 
    int pid = fork();
  
    if (pid == -1) { 
        printf("\nFailed forking child.."); 
        return; 
    } else if (pid == 0) {
	if(count==3){
	    if(strcmp(parsed[1],">")==0){
	    	int fileid = open(parsed[2],O_WRONLY|O_CREAT,0666);
	    	close(1);
	    	dup(fileid);
	    	execlp(parsed[0],parsed[0],NULL);
	    	printf("execlp error");
	    }
	}
	if (execvp(parsed[0], parsed) < 0) { 
            printf("\nCould not execute command.."); 
        } 
        exit(0); 
    } else { 
        // waiting for child to terminate 
        wait(NULL);  
        return; 
    } 
}  
  
// Help command builtin 
void openHelp() 
{ 
    puts("\n***WELCOME TO MY SHELL HELP***"
        "\n-Use the shell at your own risk..."
        "\nList of Commands supported:"
        "\n>cd"
        "\n>ls"
        "\n>exit"
        "\n>all other general commands available in UNIX shell"
	"\n"); 
  
    return; 
} 
  
// Function to execute builtin commands 
int ownCmdHandler(char** parsed) 
{ 
    int NoOfOwnCmds = 4, i, switchOwnArg = 0; 
    char* ListOfOwnCmds[NoOfOwnCmds]; 
    char* username; 
  
    ListOfOwnCmds[0] = "exit"; 
    ListOfOwnCmds[1] = "help"; 
    ListOfOwnCmds[2] = "hello"; 
    ListOfOwnCmds[3] = "google"; 
    for (i = 0; i < NoOfOwnCmds; i++) { 
        if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) { 
            switchOwnArg = i + 1; 
            break; 
        } 
    } 
  
    switch (switchOwnArg) { 
    case 1: 
        printf("\nVisit Again\n"); 
        exit(0);  
    case 2: 
        openHelp(); 
        return 1; 
    case 3: 
        username = getenv("USER"); 
        printf("\nHello %s.\nWelcome to my shell"
            "\nUse help to know more..\n", 
            username); 
        return 1; 
    case 4:
	system("firefox http://google.com");
	return 1;
    default: 
        break; 
    } 
  
    return 0; 
}  
  
// function for parsing command words 
int parseSpace(char* str, char** parsed) 
{ 
    int i; 
    int count=0;
  
    for (i = 0; i < MAXLIST; i++) { 
        parsed[i] = strsep(&str, " "); 
  
        if (parsed[i] == NULL) 
            break; 
        if (strlen(parsed[i]) == 0) 
            i--;
       count++;	
    }
   return count; 
} 
  
int processString(char* str, char** parsed,int *count) 
{ 
  
    char* strpiped[2]; 
    *count=parseSpace(str, parsed); 
  
    if (ownCmdHandler(parsed)) 
        return 0; 
    else
        return 1; 
} 
  
int main() 
{ 
    char inputString[MAXCOM], *parsedArgs[MAXLIST];  
    int execFlag = 0;
    init_shell(); 
  
    while (1) { 
        // print shell line 
        printDir();  
	// For counting no. of Commands
	int count=0;
        if (takeInput(inputString)) 
            continue;  
        execFlag = processString(inputString,parsedArgs,&count); 
        // execflag returns zero if there is no command or owncmd 
        // 1 if it is a simple command or it is a builtin command 
        if (execFlag == 1) 
            execArgs(parsedArgs,count);  
    } 
    return 0; 
} 

