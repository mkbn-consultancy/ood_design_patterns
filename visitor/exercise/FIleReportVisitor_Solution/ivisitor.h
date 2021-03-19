#pragma once

//forward declaration
class IFile;
class MP3File;
class TextFile;

class IFileVisitor
{
public:
	virtual void visit(IFile*) = 0;
	virtual void visit(MP3File*) = 0;
	virtual void visit(TextFile*) = 0;
};
