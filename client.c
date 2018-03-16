#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <unistd.h>

int main(int argc, char **argv) {
	
	static const short BLUETOOTH_CHANNEL = 13;
	
	struct sockaddr_rc addr = { 0 };
	
	// HARD CODDED MAC ADDRESS OF THE SERVER
	char dest[18] = "B8:27:EB:9F:51:D4";
	
	// allocate socket
	int socketDesc = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	
	// set the connection parameters (who to connect to)
	addr.rc_family = AF_BLUETOOTH;
	addr.rc_channel = BLUETOOTH_CHANNEL;
	str2ba(dest, &addr.rc_bdaddr);
	
	// connect to server
	printf("Trying to connect\n");
	int status = connect(socketDesc, (struct sockaddr *)&addr, sizeof(addr));
	printf("status: %i \n", status);
	// send a message
	if (status == 0) {
		char message[] = "Te amo mi florcita :3";
		status = write(socketDesc, message, sizeof(message));
	}
	
	if (status < 0) {
		printf("I cannot connect\n");
	}
	
	// close connection
	close(socketDesc);
}
