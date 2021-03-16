#pragma once
#include "builder.h"
#include <string>

class NetAddress
{
public:
	class Builder {
	public:
		const std::string&	getProtocol() const { return _protocol; }
		const std::string&	getUrl() const { return _url; }
		int					getPort() const { return _port; }
		const std::string&	getPath() const { return _path; }
		const std::string&	getDescription() const { return _description; }

		Builder&			setProtocol(const std::string& protocol) { _protocol = protocol; return *this; }
		Builder&			setUrl(const std::string& url) { _url = url; return *this; }

		NetAddress*			build() { return new NetAddress(*this); }

	private:
		std::string	_protocol;
		std::string	_url;
		int			_port;
		std::string	_path;
		std::string	_description;
	};

private:
	NetAddress(Builder& builder);
	friend NetAddress* NetAddress::Builder::build();
private:
	const std::string	_protocol;
	const std::string	_url;
	const int			_port;
	const std::string	_path;
	const std::string	_description;
};
