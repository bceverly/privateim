#include "privateim.h"

void *perform_work(void *argument) {
	struct sockaddr_in stSockAddr;
	int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (-1 == SocketFD) {
		printf("can not create socket\n");
		exit(EXIT_FAILURE);
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET;
	stSockAddr.sin_port = htons(4099);
	stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (-1 == bind(SocketFD,(struct sockaddr *)&stSockAddr, sizeof(stSockAddr))) {
		printf("error bind failed\n");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	if (-1 == listen(SocketFD, 10)) {
		printf("error listen failed\n");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	int ConnectFD = accept(SocketFD, NULL, NULL);
	if (0 > ConnectFD) {
		printf("error accept failed\n");
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	char buff[MAX_STRING_SIZE + 1];
	read(ConnectFD, buff, MAX_STRING_SIZE);
	printf("Received: %s\n", buff);

	if (-1 == shutdown(ConnectFD, SHUT_RDWR)) {
		printf("can not shutdown socket\n");
		close(ConnectFD);
		close(SocketFD);
		exit(EXIT_FAILURE);
	}

	close(ConnectFD);
	close(SocketFD);

/*	printf("Hello from the thread!\n");
	sleep(5);*/
	return NULL;
}

int main(int argc, char *argv[]) {
	int ret = 0;
	int port_num = 0;
	char ip_address[MAX_STRING_SIZE + 1];

	if (!parse_command_line(argc, argv, ip_address, &port_num)) {
		return -1;
	}

	pthread_t thread;
	int result_code;

	result_code = pthread_create(&thread, NULL, perform_work, NULL);

    struct sockaddr_in stSockAddr;
    int Res;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
 
    if (-1 == SocketFD)
    {
      perror("cannot create socket");
      exit(EXIT_FAILURE);
    }
 
    memset(&stSockAddr, 0, sizeof(stSockAddr));
 
    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(port_num);
    Res = inet_pton(AF_INET, ip_address, &stSockAddr.sin_addr);
 
    if (0 > Res)
    {
      perror("error: first parameter is not a valid address family");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
    else if (0 == Res)
    {
      perror("char string (second parameter does not contain valid ipaddress)");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
 
    if (-1 == connect(SocketFD, (struct sockaddr *)&stSockAddr, sizeof(stSockAddr)))
    {
      perror("connect failed");
      close(SocketFD);
      exit(EXIT_FAILURE);
    }
 
    write(SocketFD, "Hello", 7);
 
    (void) shutdown(SocketFD, SHUT_RDWR);
 
    close(SocketFD);

	result_code = pthread_join(thread, NULL);

	printf("ip_address = %s, port_num = %d\n", ip_address, port_num);

	return 0;
}