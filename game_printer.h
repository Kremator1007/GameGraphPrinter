#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

enum class VictoryStates { winning, losing, unknown };

std::map<VictoryStates, std::string> victory_state_to_string{
    {VictoryStates::winning, "W"},
    {VictoryStates::losing, "L"},
    {VictoryStates::unknown, "unknown"}};

using i32 = std::int32_t;
using u32 = std::uint32_t;

template <class Game, class GameState, u32 NumOfPlayers>
class GamePrinter {
   public:
	void print_game_graph(GameState game_state, u32 game_depth) {
		num_of_player_whos_turn = (num_of_player_whos_turn + 1) % NumOfPlayers;
		++indentation_depth;
		if (game_depth != 0) {
			if (Game::check_winning_conditions(game_state) ==
			    VictoryStates::unknown) {
				print_game_state_with_formatting(game_state);
				std::vector<GameState> const possible_states_after_one_move =
				    Game::generate_states(game_state);
				for (GameState const& possible_state_after_one_move :
				     possible_states_after_one_move) {
					print_game_graph(possible_state_after_one_move,
					                 game_depth - 1);
				}
			} else {
				print_constatation_of_victory_state(game_state);
			}
		}
		--indentation_depth;
		num_of_player_whos_turn =
		    (num_of_player_whos_turn + NumOfPlayers - 1) % NumOfPlayers;
	}

   private:
	void print_game_state_with_formatting(GameState const& game_state) {
		print_indentation();
		std::cout << player_to_string[num_of_player_whos_turn] << " "
		          << game_state.to_string() << '\n';
	}
	void print_indentation() {
		for (u32 i = 0; i < indentation_depth; ++i) std::cout << "    ";
	}

	void print_constatation_of_victory_state(GameState const& game_state) {
		print_indentation();
		std::cout << player_to_string[num_of_player_whos_turn] << " "
		          << game_state.to_string() << ' '
		          << victory_state_to_string[Game::check_winning_conditions(
		                 game_state)]
		          << '\n';
	}

	u32 indentation_depth = 0xFFFFFFFF;
	u32 num_of_player_whos_turn = NumOfPlayers - 1;
	std::vector<std::string> const player_to_string{"1st", "2nd", "3rd", "4th"};
};
