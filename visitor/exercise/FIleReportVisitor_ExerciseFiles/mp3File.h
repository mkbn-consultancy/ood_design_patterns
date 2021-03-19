#pragma once
#include "fileImpl.h"

class MP3File : public FileImpl
{
public:
	MP3File(const std::string& name, double duration, const std::string& singer);


	double getSongDuration() const;
private:
	double _songDuration;
	std::string _singer;
};

