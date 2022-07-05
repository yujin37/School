#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    DIR *dirp = NULL;
    struct dirent *dentry;
    struct stat finfo;

    if(argc != 2)
    {
        printf("Insufficient arguments!\n");
        exit(1);
    }

    chdir(argv[1]);

    dirp = opendir(argv[1]);  
    
    if(dirp == NULL)
    {
        fprintf(stderr, "Error on opendir for current directory\n");
        return -1;
    }
    
    /* insert source codes */
    while(dentry=readdir(dirp)){
	    if(stat(dentry->d_name,&finfo)==-1){
		    fprintf(stderr,"Error on stat for %s\n", dentry->d_name);
		    return -1;
	    }
	    if(S_ISREG(finfo.st_mode)){
		    if(finfo.st_size==0){
			    if(remove(dentry->d_name)==-1){
				    fprintf(stderr,"Error on remove for %s\n", dentry->d_name);
				    return -1;
			    }
			    else
				    printf("file name: %s, file size (byte): %ld, removed\n", dentry->d_name,finfo.st_size);
		    }
	    }
    }
    closedir(dirp); 
}
