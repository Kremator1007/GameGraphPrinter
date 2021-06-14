**Game graph printer**

The following project is aimed to provide help for all the students that are preparing for All-Russian exam in informatics this year. 

To make use of this repository:
- Clone it during the actual exam
- Provide the following member functions for your Game and GameState classes (note that the `generate_states(GameState const& state)` method must return all possible gameStates after one move is done):
```
    std::string GameState::to_string() const
    static VictoryStates Game::check_winning_conditions()
    static std::vector<GameState> generate_states(GameState)
```
Please be wary of the fact that the following assumptions are made:
- Your methods' implementations don't mutate any global state; otherwise the behavior is not well-defined
- The game is assumed to be symmetric - that is, the first and the second player obey exactly the same rules (that are implicitly conveyed via 'generate_states' method)

The library ("game_printer.h") will print the game graph for the needed depth in a human-readable manner, marking winning/losing (by rules) position as W / L respectively, using indentation to increase readability and marking which player must make a move now.

You can see below the possible output of a program (copied fron the output of example.cpp):
```
1st (9, 60)
    2nd (9, 62)
        1st (9, 64)
            2nd (9, 66)
            2nd (11, 64)
            2nd (9, 128) L
            2nd (18, 64) L
        1st (11, 62)
            2nd (11, 64)
            2nd (13, 62)
            2nd (11, 124) L
            2nd (22, 62) L
        1st (9, 124) L
        1st (18, 62)
            2nd (18, 64) L
            2nd (20, 62) L
            2nd (18, 124) L
            2nd (36, 62) L
    2nd (11, 60)
        1st (11, 62)
            2nd (11, 64)
            2nd (13, 62)
            2nd (11, 124) L
            2nd (22, 62) L
        1st (13, 60)
            2nd (13, 62)
            2nd (15, 60)
            2nd (13, 120) L
            2nd (26, 60) L
        1st (11, 120) L
        1st (22, 60) L
    2nd (9, 120) L
    2nd (18, 60)
        1st (18, 62)
            2nd (18, 64) L
            2nd (20, 62) L
            2nd (18, 124) L
            2nd (36, 62) L
        1st (20, 60)
            2nd (20, 62) L
            2nd (22, 60) L
            2nd (20, 120) L
            2nd (40, 60) L
        1st (18, 120) L
        1st (36, 60) L
```
I wish you best of luck on your exam!