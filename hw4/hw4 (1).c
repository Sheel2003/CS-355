#include<stdio.h>
#include<stdlib.h>
#include<utmp.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>

void show_info(struct utmp *);
void show_time(long);

int main(){
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);
    
    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1){
        perror(UTMP_FILE);
        exit(1);
    }
    while(read(utmpfd, &current_record, reclen)== reclen){
        show_info(&current_record);
        
    }
    close(utmpfd);
    return 0;
}
void show_time(long time){
    char buf[BUFSIZ];
    struct tm *info = localtime(&time);
    strftime(buf,sizeof(buf),"%b %d %I:%M", info);
    printf("%s",buf);

}
void show_info(struct utmp *utbufp){
    if(utbufp->ut_type != USER_PROCESS){
        return;
    }
    printf("%s", utbufp->ut_user);
    printf("  ");
    printf("%s", utbufp->ut_line);
    printf("  ");
    show_time(utbufp->ut_time);
    printf(" ");

    printf("\n");
}