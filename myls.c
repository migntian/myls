
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include <pwd.h>
#include<grp.h>
#include<sys/time.h>
void file_ls(md)
{

	struct stat sbuf;
	char type[11]="?---------";
	if((md & S_IFMT)==S_IFREG) type[0]='-';
	if((md & S_IFMT)==S_IFSOCK) type[0]='s';
	if((md & S_IFMT)==S_IFBLK) type[0]='b';	
	if((md & S_IFMT)==S_IFDIR) type[0]='d';
	if((md & S_IFMT)==S_IFCHR) type[0]='c';
	if((md & S_IFMT)==S_IFIFO) type[0]='p';
	if((md & S_IFMT)==S_IFLNK) type[0]='l';

    if(md & S_IRUSR) type[1]='r';
	if(md & S_IWUSR) type[2]='w';
	if(md & S_IXUSR) type[3]='x';

	if(md & S_IRGRP) type[4]='r';
	if(md & S_IWGRP) type[5]='w';
	if(md & S_IXGRP) type[6]='x';
	
	if(md & S_IROTH) type[7]='r';
	if(md & S_IWOTH) type[8]='w';
	if(md & S_IXOTH) type[9]='x';
	printf("%s ",type);
//	printf("%d\n",sbuf.st_nlink);
}



int main(int argc,char *argv[])
{
	if(argc !=2)
	{
		fprintf(stderr,"usage:%s filaneme\n",argv[0]);
		exit(1);
	}
	struct stat sbuf;
	if(lstat(argv[1],&sbuf)==-1){
		printf("tan 90\n");
		return 1;}
	file_ls(sbuf.st_mode);
	printf("%d ",sbuf.st_nlink);
	struct passwd *pu=getpwuid(sbuf.st_uid);
	if(pu !=NULL)
		printf("%s ",pu->pw_name);
	struct group *pg=getgrgid(sbuf.st_gid);
//	if(pg != NULL)
//		printf("%s ",pg->gr_name);
	printf("%d ",sbuf.st_size);
	//struct tm *ptm = localtime(&sbuf.st_mtime);
	//printf("%04d-%02d-%02d",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday);
//	printf("%02d:%02d:%02d",ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
//	printf("%s",argv[1]);
//	if(S_ISLINK(sbuf.st_mode)){
//		printf("->");
//		char targname[256]={};
//		readlink(argv[1],targname,sizeof(targname));
//	}
	printf("\n");
	return 0;
}

