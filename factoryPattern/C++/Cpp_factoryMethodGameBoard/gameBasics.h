#pragma once
//forward declaration
class IGameBoard;

class GameBasics {
public:
	void gameLoop();	//the template method
protected:
	virtual IGameBoard* createBoard() = 0;	//factory method
	virtual void decideFirstPlayer() = 0;
	virtual bool hasWinner() = 0;
	virtual void makeMove() = 0;
	virtual void announceWinner() = 0;
private:
	IGameBoard* _board;
};
