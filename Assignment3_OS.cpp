//Implement Interprocess Communication using PIPE/Shared Memory/Message Passing 
#include<iostream>
using namespace std;
#include<cstring>
#include<unistd.h>
int main()
{
	//pipe creates unidirectional pipe(one writing end(1), one reding end(0))
	int fd[2],n;
	char buffer[100];
	pid_t p;
	pipe(fd);     //returns file descriptors(reading,writing) in fd
	p=fork();
	if(p>0)
	{
		cout<<"---------------------------------------"<<endl;
		cout<<"This is a parent process with id= "<<getpid()<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"--> Enter your message: ";
		fgets(buffer,100,stdin);
		int len=strlen(buffer);
		write(fd[1],buffer,len);
		cout<<"---------------------------------------"<<endl;
		cout<<"Passing value to child (with pid= "<<p<<") ..."<<endl;
		cout<<"---------------------------------------"<<endl;
	}
	else
	{
		n=read(fd[0],buffer,100);
		cout<<"---------------------------------------"<<endl;
		cout<<"Child (with pid= "<<getpid()<<") received data.."<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"Received data: "<<endl;

		write(1,buffer,n);
		cout<<"Reverse of the message: "<<endl;
		for(int i=n-2;i>=0;i--)
		{
			cout<<buffer[i];
		}
		cout<<endl;
	}
}

//Commands: gcc filename.c ---> ./a.out

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
 int fd[2],n;
 // fd[0] -- read
 // fd[1] -- write
 char buffer[100];
 pid_t p;
pipe(fd);
 p = fork();
 if(p > 0){
 // parent
 printf("Parent Passing value to child\n");
 write(fd[1],"Hello\n",6);
 // ssize_t write(int _fd, const void *_buf, size_t __nbyte)
 }
 else{
 printf("Child printing received value\n");
 n = read(fd[0],buffer,100);
 // ssize_t read(int, void *, size_t)
 write(1,buffer,n);
 }
}
*/
