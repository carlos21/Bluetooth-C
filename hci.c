#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char **argv) {
	
	int dev_id = hci_get_route(NULL);
	printf("dev_id: %i\n", dev_id);
	
	int fh = hci_open_dev(dev_id);
	printf("fh: %i\n", fh);
}
