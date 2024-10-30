1: clean # Run the Whole Program.
	g++ $(1Include) -o 1_Full_Game
	./1_Full_Game

2: clean # Run a Normal Game.
	g++ $(2Include) -o 2_Normal_Game
	./2_Normal_Game

3: clean # Run a Battle Game.
	g++ $(3Include) -o 3_Battle_Game
	./3_Battle_Game

4: clean # Test the Normal Board functinality.
	g++ $(4Include) -o 4_Normal_Board_Test
	./4_Normal_Board_Test

5: clean # Test the Battle Board functinality.
	g++ $(5Include) -o 5_Battle_Board_Test
	./5_Battle_Board_Test

6: clean # Test the Paladin class functinality.
	g++ $(6Include) -o 6_Paladin_Test
	./6_Paladin_Test

7: clean # Test the Alchemist class functinality.
	g++ $(7Include) -o 7_Alchemist_Test
	./7_Alchemist_Test


1Include := main.cpp MainMenu.cpp $(NormalInclude) $(BattleInclude) $(ClassInclude) $(MenuInclude) 

2Include := Tests/NormalMain.cpp $(NormalInclude)

3Include := Tests/BattleMain.cpp $(BattleInclude) $(ClassInclude) $(MenuInclude) 

4Include := Tests/NormalBoardTest.cpp $(NormalInclude)

5Include := Tests/BattleBoardTest.cpp

6Include := Tests/PaladinTest.cpp

7Include := Tests/AlchemistTest.cpp

NormalInclude := Normal/NGame.cpp Normal/NRules.cpp Normal/NPromptsAndResponses.cpp Normal/NBoard.cpp Normal/NSpace.cpp

BattleInclude := Battle/BGame.cpp Battle/BRules.cpp Battle/BPromptsAndResponses.cpp Battle/BBoard.cpp Battle/BBoardPrinter.cpp Battle/BSpace.cpp

ClassInclude := Battle/Classes/Alchemist.cpp Battle/Classes/Paladin.cpp

MenuInclude := Battle/BCharMenu.cpp Battle/BClassMenu.cpp

clean:
	@rm -f 1_Full_Game
	@rm -f 2_Normal_Game
	@rm -f 3_Battle_Game
	@rm -f 4_Normal_Board_Test
	@rm -f 5_Battle_Board_Test
	@rm -f 6_Paladin_Test
	@rm -f 7_Alchemist_Test