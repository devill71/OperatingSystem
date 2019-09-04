# OperatingSystem
Btech 2nd year os projects
this project has the code of the shell equiavalent of linux for assignement lvl in classes
this code caan can execute self made commands and system commands 
for system commands(ls,ls-l,mkdir,etc..)we have used a function from exec family called execvp.
for output redirecting we have used the system command from exec family namely execlp.
for those who dont know execvp ->this function is used to execute any built in function in linux.
for those who dont know execlp ->this function stops the running program and creates the image of the function passed to it and starts executing that function
in this code to execute system commands we first fork the main process and execute the system commands while parent process wait for the child to finsih.
used getcwd command to get the directory of the area where the code is present.
