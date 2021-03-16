#include "musicAvgVisitor.h"
#include "mp3File.h"
#include "textFile.h"

MusicAvgCalcVisitor::MusicAvgCalcVisitor() : _counter(0), _sumDuration(0) {}

void MusicAvgCalcVisitor::visit(IFile* p) {
	p->accept(this);
}

void MusicAvgCalcVisitor::visit(MP3File* p) {
	_counter++;
	_sumDuration += p->getSongDuration();
}

void MusicAvgCalcVisitor::visit(TextFile* p) {
	return;
}

double MusicAvgCalcVisitor::getAvg() const {
	return _counter ? (_sumDuration / _counter) : -1;
}
