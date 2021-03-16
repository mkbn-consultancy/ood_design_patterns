#include "mp3File.h"
#include "ivisitor.h"

MP3File::MP3File(const std::string& name, double duration, const std::string& singer) :
	FileImpl(name), _songDuration(duration), _singer(singer) {}

void MP3File::accept(IFileVisitor* p) {
	p->visit(this);
}
double MP3File::getSongDuration() const { return _songDuration; }

