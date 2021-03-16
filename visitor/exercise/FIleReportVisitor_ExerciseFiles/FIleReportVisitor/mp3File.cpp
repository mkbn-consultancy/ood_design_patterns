#include "mp3File.h"

MP3File::MP3File(const std::string& name, double duration, const std::string& singer) :
	FileImpl(name), _songDuration(duration), _singer(singer) {}


double MP3File::getSongDuration() const { return _songDuration; }

