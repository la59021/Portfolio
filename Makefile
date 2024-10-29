FullGame: clean
	g++ main.cpp MainMenu.cpp $(NormalInclude) -o FullGame
	./FullGame

NormalGame: clean
	g++ Tests/NormalMain.cpp $(NormalInclude) -o NormalGame
	./NormalGame

BattleGame: clean
	g++ main.cpp MainMenu.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

NormalInclude := Normal/Rules.cpp Normal/PromptsAndResponses.cpp Normal/Board.cpp Normal/Game.cpp Normal/Space.cpp

BattleInclude :=

clean:
	rm -f FullGame
	rm -f NormalGame
	rm -f BattleGame