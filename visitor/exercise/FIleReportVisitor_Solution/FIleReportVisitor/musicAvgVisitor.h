#pragma once
#include "ivisitor.h"

class MusicAvgCalcVisitor : IFileVisitor
{
public:
	MusicAvgCalcVisitor();

	virtual void visit(IFile* p);
	virtual void visit(MP3File* p);
	virtual void visit(TextFile* p);

	double getAvg() const;
private:
	int _counter;
	double _sumDuration;
};