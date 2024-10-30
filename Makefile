FullGame: clean
	g++ main.cpp MainMenu.cpp $(NormalInclude) $(BattleInclude) -o FullGame
	./FullGame

NormalGame: clean
	g++ Tests/NormalMain.cpp $(NormalInclude) -o NormalGame
	./NormalGame

BattleGame: clean
	g++ Tests/BattleMain.cpp $(BattleInclude) $(MenuInclude) -o BattleGame

NormalInclude := Normal/NGame.cpp Normal/NRules.cpp Normal/NPromptsAndResponses.cpp Normal/NBoard.cpp Normal/NSpace.cpp

BattleInclude := Battle/BGame.cpp Battle/BRules.cpp Battle/BPromptsAndResponses.cpp Battle/BBoard.cpp Battle/BSpace.cpp

MenuInclude := Battle/BCharMenu.cpp Battle/BClassMenu.cpp

clean:
	@rm -f FullGame
	@rm -f NormalGame
	@rm -f BattleGame