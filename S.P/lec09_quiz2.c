#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

/* insert source codes (optional)*/

int main(int argc, char *argv[])
{
    DIR *dirp = NULL;
    struct dirent *dentry;
    struct stat finfo;
    char fname[BUFSIZ];
    long int fino;

    if(argc != 2){
        printf("Insufficient arguments!\n");
        exit(1);
    }

    chdir(argv[1]);

    dirp = opendir(argv[1]);
    
    if(dirp == NULL){
        fprintf(stderr, "Error on opendir for current directory\n");
        return -1;
    }
    
    /* insert source codes */
    while(dentry=readdir(dirp)){
	    if(stat(dentry->d_name,&finfo)==-1){
		    fprintf(stderr,"Error on stat for %s\n", dentry->d_name);
		    return -1;
	    }
	    if(S_ISDIR(finfo.st_mode)){
		    if(rmdir(dentry->d_name)==-1){
			    fprintf(stderr,"rmdir of %s: error number= %d, error string = %s\n", dentry->d_name, errno, strerror(errno));

			    if((errno ==22)||(errno==39))
				    continue;
			    else
				    return -1;
		    }
		    else
			    printf("rmdir of %s: success\n", dentry->d_name);

		    
		    
	    }
    }

    closedir(dirp); 
}

/* insert source codes (optional)*/
