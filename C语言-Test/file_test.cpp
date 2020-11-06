#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<grp.h>
#include<pwd.h>
#include<sys/types.h>
#include <time.h>

int print_type(mode_t st_mode)
{            
	if(S_ISREG(st_mode))
		printf("\033[;35;1m-");
	else if(S_ISDIR(st_mode))
		printf("\033[;35;1md");
	else if(S_ISCHR(st_mode))
		printf("\033[;35;1mc");
	else if(S_ISBLK(st_mode))
		printf("\033[;35;1mb");
	else if(S_ISFIFO(st_mode))
		printf("\033[;35;1mp");
	else if(S_ISLNK(st_mode))
		printf("\033[;35;1ml");
	else if(S_ISSOCK(st_mode))
		printf("\033[;35;1ms");	
	return 0;   
}

void print_perm(mode_t st_mode)
{
   	int i;
	for(i=8;i>=0;i--)
	{
		if(st_mode & (1 << i))//st_mode & (1 << i)的意义
        	{//printf("%d",st_mode & (1 << i));
            		switch(i%3)
            		{
            		case 2: printf("\033[;36;1mr"); break;
            		case 1: printf("\033[;36;1mw"); break;
            		case 0: printf("\033[;36;1mx"); break;
           		}
        	}
       		 else
            	printf("\033[;36;1m-");			
	}
}

void print_usrname(uid_t st_uid)
{
	struct passwd *pw;//Attention!!!!!!!是passwd不是password
	pw=getpwuid(st_uid);
	printf("\033[;35;1m%s",pw->pw_name);
}

void print_grname(gid_t st_gid)
{
	struct group *gr;
	gr=getgrgid(st_gid);
	printf("\033[;36;1m%s",gr->gr_name);
}

void print_time(struct stat currentstat)
{
	struct tm *tm;
	tm=localtime(&currentstat.st_mtime);
	printf("\033[;35;1m%04d-%02d-%02d %02d:%02d",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min);
}

void print_link(nlink_t st_nlink){printf("\033[;36;1m%ld",st_nlink);}
void print_size(off_t st_size){printf("\033[;35;1m%5ld",st_size);}
void print_filename(struct dirent *currentdp){printf("\033[;36;1m%s",currentdp->d_name);}


int main(int argc,char *argv[])//argv[]接收参数 接收一串地址
{
DIR *dp;//打开文件的指针
struct stat currentstat;//一般用来操作普通文件
struct dirent *currentdp;//一般用来操作目录文件
dp=opendir(argv[1]);//打开目录 返回一个地址赋给dp
if(!dp){printf("\033[;31mNo such file or directory\n");exit(0);}
stat(argv[1],&currentstat);//给currentstat赋接收的地址
while(currentdp=readdir(dp))
{
	if(currentdp->d_name[0]!='.')
	if(lstat(currentdp->d_name,&currentstat)!=-2)//-1 0都不行
	{
		print_type(currentstat.st_mode);
		printf("\033[;37;1m|");
		print_link(currentstat.st_nlink);
		printf("\033[;37;1m|");
		print_size(currentstat.st_size);
		printf("\033[;37;1m|");
		print_perm(currentstat.st_mode);
		printf("\033[;37;1m|");
		print_usrname(currentstat.st_uid);
		printf("\033[;37;1m|");
		print_grname(currentstat.st_gid);
		printf("\033[;37;1m|");
		print_time(currentstat);
		printf("\033[;37;1m|");
		print_filename(currentdp);
		//printf("\033[;37;1m |");
		printf("\n");
	}
}
return 0;
}
