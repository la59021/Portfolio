FullGame: clean
	g++ main.cpp MainMenu.cpp $(NormalInclude) $(BattleInclude) $(MenuInclude) -o FullGame
	./FullGame

NormalGame: clean
	g++ Tests/NormalMain.cpp $(NormalInclude) -o NormalGame
	./NormalGame

BattleGame: clean
	g++ Tests/BattleMain.cpp $(BattleInclude) $(MenuInclude) -o BattleGame

NormalInclude := Normal/Game.cpp Normal/Rules.cpp Normal/PromptsAndResponses.cpp Normal/Board.cpp Normal/Space.cpp

BattleInclude := Battle/Game.cpp Battle/Rules.cpp Battle/PromptsAndResponses.cpp Battle/Board.cpp Battle/Space.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

clean:
	@rm -f FullGame
	@rm -f NormalGame
	@rm -f BattleGame