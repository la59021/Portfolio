1: clean # Run the Whole Program.
	g++ -Wall -std=c++11 main.cpp MainMenu.cpp $(NormalInclude) $(BattleInclude) $(ClassInclude) $(MenuInclude) -o 1_Full_Game
	./1_Full_Game

2: clean # Run a Normal Game.
	g++ -Wall -std=c++11 Tests/NormalMain.cpp $(NormalInclude) -o 2_Normal_Game
	./2_Normal_Game

3: clean # Run a Battle Game.
	g++ -Wall -std=c++11 Tests/BattleMain.cpp $(BattleInclude) $(ClassInclude) $(MenuInclude) -o 3_Battle_Game
	./3_Battle_Game

4: clean # Test the Normal Board functinality.
	g++ -Wall -std=c++11 Tests/NBoardTest.cpp Normal/NPromptsAndResponses.cpp Normal/NBoard.cpp Normal/NSpace.cpp -o 4_Normal_Board_Test
	./4_Normal_Board_Test

5: clean # Test the Battle Board functinality.
	g++ -Wall -std=c++11 Tests/BBoardTest.cpp Battle/BBoard.cpp Battle/BSpace.cpp -o 5_Battle_Board_Test
	./5_Battle_Board_Test

6: clean # Test the Paladin class functinality.
	g++ -Wall -std=c++11 Tests/PaladinTest.cpp -o 6_Paladin_Test
	./6_Paladin_Test

7: clean # Test the Alchemist class functinality.
	g++ -Wall -std=c++11 Tests/AlchemistTest.cpp -o 7_Alchemist_Test
	./7_Alchemist_Test

NormalInclude := Normal/NGame.cpp Normal/NRules.cpp Normal/NPromptsAndResponses.cpp Normal/NBoard.cpp Normal/NSpace.cpp

BattleInclude := Battle/BGame.cpp Battle/BRules.cpp Battle/BBoard.cpp Battle/BSpace.cpp

ClassInclude := Battle/Classes/Alchemist.cpp Battle/Classes/Paladin.cpp

MenuInclude := Battle/BCharMenu.cpp Battle/BClassMenu.cpp Terminate.cpp

clean:
	@rm -f 1_Full_Game
	@rm -f 2_Normal_Game
	@rm -f 3_Battle_Game
	@rm -f 4_Normal_Board_Test
	@rm -f 5_Battle_Board_Test
	@rm -f 6_Paladin_Test
	@rm -f 7_Alchemist_Test