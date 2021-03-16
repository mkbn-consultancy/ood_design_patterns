#include "netAddress.h"

NetAddress::NetAddress(Builder& builder) : _protocol(builder.getProtocol()),
_url(builder.getUrl()),
_port(builder.getPort()),
_path(builder.getPath()),
_description(builder.getDescription())
{}
