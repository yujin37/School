#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#define BUF_SIZE 1024

int remove_directory(char *path)
{
    DIR *dirp;
    char buffer[BUFSIZ];
    struct dirent *dentry;
    struct stat finfo;
    
    if(stat(path, &finfo) == -1)                            // get state information of path
    {
        fprintf(stderr, "Error: stat %s\n", path);
        return -1;
    }

    if(remove(path) == 0)                                   // remove a file or an empty directory
        printf("Sucess: remove %s\n", path);
    else
    {
        if(S_ISDIR(finfo.st_mode))                          // when path is a directory 
        {
            chdir(path);
            getcwd(buffer, BUF_SIZE);
            
            dirp = opendir(buffer);

            while(dentry = readdir(dirp))
            {
                if((strcmp(dentry->d_name, ".") == 0) || (strcmp(dentry->d_name, "..") == 0))                   
                    continue;
                
                if(remove_directory(dentry->d_name) == -1)
                {
                    fprintf(stderr, "Error: remove %s\n", dentry->d_name);
                    return -1;
                }
            }        

            chdir("..");

            if(remove(path) == 0)                           // remove a empty directory 
                printf("Sucess: remove %s\n", path);
            else
            {
                fprintf(stderr, "Error: remove %s\n", path);;
                return -1;
            }
        }
        else
        {
            fprintf(stderr, "Error: remove %s\n", path);;
            return -1;
        }
    }
    
    return 0;
}    

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Insufficient arguments!\n");   
        return -1;
    }

    if(remove_directory(argv[1]) == -1)
        return -1;

    return 0;
}