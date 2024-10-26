fullGame:
	g++ $(BaseInclude) $(MenuInclude) $(NormalInclude) $(BattleInclude) $(ClassInclude) -o full
	./full

BaseInclude := main.cpp MainMenu.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

NormalInclude := Normal/NormalGame.cpp Normal/NormalRules.cpp Normal/NormalPrompts.cpp Normal/NormalResponses.cpp Normal/NormalBoard.cpp Normal/NormalSpace.cpp

BattleInclude := Battle/BattleLoop.cpp Battle/BattleRules.cpp Battle/BattlePrompts.cpp Battle/BattleResponses.cpp Battle/BattleBoard.cpp Battle/BattleSpace.cpp 

ClassInclude := Battle/Classes/Alchemist.cpp Battle/Classes/Paladin.cpp