
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int fd;
    char message[100];
    char buffer[100];

    mkfifo("myfifo", 0666);

    if(fork() == 0)
    {
        // Child process - Reader
        fd = open("myfifo", O_RDONLY);

        read(fd, buffer, sizeof(buffer));

        printf("Received: %s", buffer);

        close(fd);
    }
    else
    {
        // Parent process - Writer
        fd = open("myfifo", O_WRONLY);

        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        write(fd, message, strlen(message)+1);

        close(fd);

        wait(NULL);

        unlink("myfifo");
    }

    return 0;
}
