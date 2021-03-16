#pragma once
#include "gameBasics.h"
#include "chessBoard.h"
#include <iostream> //for debug printouts only

class ChessGame : public GameBasics {
public:
	ChessGame() {"creating a Chess game...\n";}
protected:	
	//factory method:
	virtual IGameBoard* createBoard() {
		std::cout<<"--creating a Chess board...\n";
		return new ChessBoard;
	}

	//empty methods just to make it compile:
	virtual void decideFirstPlayer() {
		std::cout<<"--white plays first...\n";
	}
	virtual bool hasWinner() { return true; }
	virtual void makeMove() {}
	virtual void announceWinner() {}
};