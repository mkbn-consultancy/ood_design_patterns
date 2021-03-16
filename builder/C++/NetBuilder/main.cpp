#include <string>
#include "builder.h"
#include "netAddress.h"

int main() {
	NetAddress* p = NetAddress::Builder().setProtocol("TCP").setUrl("192.168.56.1").build();
}
