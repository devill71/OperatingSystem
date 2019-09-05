# OperatingSystem
Btech 2nd year os projects

This project has the code of the shell equiavalent of linux for assignement lvl in classes.
This code caan can execute self made commands and system commands.

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
