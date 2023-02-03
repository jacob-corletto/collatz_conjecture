#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int n = 0;
	pid_t pid;
	
	std::cout<<"please enter a non negative non 0 number"<<std::endl;
	std::cin>> n;

	pid = fork();
	if(pid == 0){
		std::cout<<"child process"<<std::endl;
		if(n > 0){
			std::cout << n <<std::endl;
			while (n != 1){
				if(n%2 ==0){
					n = n/2;
				}
				else if(n%2 ==1){
					n = (3*n)+1;
				}
				std::cout<< n <<std::endl;
			}
		}
		else{
			std::range_error("please enter a non negative non 0 number");
		}
		std::cout<<"end of child process"<<std::endl;
	}
	else{
		std::cout<<"parent process"<<std::endl;
		wait(NULL);
		std::cout<<"end of parent process"<<std::endl;
	}
}