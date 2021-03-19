#include "ifile.h"
#include "mp3File.h"
#include "textFile.h"
#include "musicAvgVisitor.h"

#include <vector>

int main()
{
	MP3File mp3File1("yesterday", 3.4, "beatles");
	MP3File mp3File2("my heart will go on", 4.2, "celine dion");
	MP3File mp3File3("mode ani", 3.4, "omer adam");
	TextFile textFile1("myThesis", 10000);
	TextFile textFile2("The C++ Lanugage", 3461);
	TextFile textFile3("5 Baloons", 25);

	std::vector<IFile*> filesPool;

	filesPool.push_back(&mp3File1);
	filesPool.push_back(&mp3File2);
	filesPool.push_back(&textFile2);
	filesPool.push_back(&mp3File3);
	filesPool.push_back(&textFile1);
	filesPool.push_back(&textFile3);

	//get average duration of music files
	MusicAvgCalcVisitor visitor;
	for (auto p : filesPool) {
		visitor.visit(p);
	}

	//print the result:
	std::cout << "The average duration of the music files is: " << visitor.getAvg() << std::endl;

	return 0;


}