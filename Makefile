fullGame:
	g++ $(BaseInclude) $(MenuInclude) $(CommonInclude) $(NormalInclude) $(BattleInclude) $(ClassInclude) -o full
	./full

NormalGame:
	g++ $()


BaseInclude := main.cpp MainMenu.cpp

MenuInclude := Battle/CharMenu.cpp Battle/ClassMenu.cpp

CommonInclude := Common/Space.cpp Common/Board.cpp

NormalInclude := Normal/NormalGame.cpp Normal/NormalRules.cpp Normal/NormalPrompts.cpp Normal/NormalResponses.cpp

BattleInclude := Battle/BattleLoop.cpp Battle/BattleRules.cpp Battle/BattlePrompts.cpp Battle/BattleResponses.cpp

ClassInclude := Battle/Classes/Alchemist.cpp Battle/Classes/Paladin.cpp