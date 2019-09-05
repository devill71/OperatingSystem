# OperatingSystem
Btech 2nd year os projects
Group number 24:
-	Hussain Kamraan		IIT2018036
-	Aditya Kumar		IIT2018046
-	Nikhil Kumar Gujrati 	IIT2018048
-	Harsh Kochar		IIT2018049
Under Supervision of Dr. Bibhas Ghoshal and teaching assit Ankur Gogoi.

This project has the code of the shell equiavalent of linux for assignment level in classes.
This code can execute self made commands and system commands.
To compile the code
```
	gcc PersonalShell.c
```
It might show a warning regarding `gets`. But it will work fine.


__Commands__
For system commands(ls,ls-l,mkdir,etc..)we have used a function from exec family called execvp.
For output redirecting we have used the system command from exec family namely execlp.
In this code to execute system commands we first fork the main process and execute the system commands while parent process wait for the child to finsih.
We also used getcwd command to get the directory of the area where the code is present.

__execvp__
-   This function is used to execute any built in function in linux.
__execlp__
-   This function stops the running program and creates the image of the function passed to it and starts executing that function

__Self Made commands would be__
```
   exit
   help
   hello
   google
   know_more
```
