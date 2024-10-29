FullGame:
	g++ $(BaseInclude) $(MenuInclude) $(NormalInclude) $(BattleInclude) $(ClassInclude) -o FullGame
	./FullGame

NormalGame:
	g++ main.cpp MainMenu.cpp $(NormalInclude) -o NormalGame
	./NormalGame

BaseInclude := main.cpp MainMenu.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

NormalInclude := Normal/Rules.cpp Normal/PromptsAndResponses.cpp Normal/Board.cpp Normal/Game.cpp Normal/Space.cpp


clean:
	rm -f FullGame
	rm -f NormalGame
	rm -f BattleGame
	rm -f BoardTest