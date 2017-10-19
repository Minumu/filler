# filler
In this game, two players fight each other. They play one after the other.
• The goal is to collect as many points as possible by placing the highest number of pieces on the the game board.
• The board is defined by X columns and N lines, it will then become X*N cells.
• At the beginning of each turn, you will receive your game piece.
• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
• To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
• The shape must not exceed the dimensions of the board.
• When the game starts, the board already contains one shape.
• The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.
///-///-///
◦ Player 1 will be represented by “o” and “O”. Player 2 will be represented by “x” and “X”.
◦ The lowercases (“x” or “o”) will highlight the piece last placed on the board. At the following turns, that same piece will be represented by the uppercase letters (“X” or “O”), as it won’t be the piece last placed anymore.
///-///-///
◦ At each turn, the filler will send the updated map and a new token to the player concerned.
◦ The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.
◦ The filler will send the map and a new piece to the other player.
///-///-///
Usage:
./filler_vm -p1 user1 -p2 user2 -f map 
