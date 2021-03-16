#include "gameBasics.h"

void GameBasics::gameLoop() {
	_board = createBoard();
	decideFirstPlayer();
	while (!hasWinner()) {
		makeMove();
	}
	announceWinner();
}
