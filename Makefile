FullGame:
	g++ $(BaseInclude) $(MenuInclude) $(CommonInclude) $(NormalInclude) $(BattleInclude) $(ClassInclude) -o FullGame
	./FullGame

NormalGame:
	g++ Tests/NormalTTT.cpp $(NormalInclude) $(CommonInclude) Classes/Human.cpp -o NormalGame
	./NormalGame

BattleGame:
	g++ Tests/BattleTTT.cpp $(BattleInclude) $(CommonInclude) $(ClassInclude) -o BattleGame
	./BattleGame

BoardTest:
	g++ Tests/BoardTest.cpp $(CommonInclude) -o BoardTest
	./BoardTest

BaseInclude := main.cpp MainMenu.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

CommonInclude := Common/Space.cpp Common/Board.cpp

NormalInclude := Normal/NormalLoop.cpp Normal/NormalRules.cpp Normal/NormalResponses.cpp

BattleInclude := Battle/BattleLoop.cpp Battle/BattleRules.cpp Battle/BattlePrompts.cpp Battle/BattleResponses.cpp

ClassInclude := Classes/Alchemist.cpp Classes/Paladin.cpp

clean:
	rm -f FullGame
	rm -f NormalGame
	rm -f BattleGame
	rm -f BoardTest