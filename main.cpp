#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define ERROR_S "SERVER ERROR: "
#define DEFAULT_PORT 16001

int main (int ac, char const** av)
{
	int client;
	int server;

	struct sockaddr_in server_address;

	client = socket(AF_INET, SOCK_STREAM, 0);

	if (client < 0)
	{
		std::cout << ERROR_S << "Established socket error!\n";
		exit(1);
	}
	else
		std::cout << "Socket for server was successfully created!\n";
	server_address.sin_port = htons(DEFAULT_PORT);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	int ret = bind(client, reinterpret_cast<struct sockaddr*>(&server_address), sizeof(server_address));
	if (ret < 0)
	{
		std::cout << ERROR_S << "Binding connection. Socket has been alredy establishing!" << std::endl;
		return (-1);
	}
	socklen_t size = sizeof(server_address);
	std::cout << "SERVER: " << "Listening clients...\n";
	listen(client, 1);

	server = accept(client, reinterpret_cast<struct sockaddr*>(&server_address), &size);
	if (server < 0)
	{
		std::cout << ERROR_S << "Can`t accepting client!\n";
	}
	
	return (0);
}