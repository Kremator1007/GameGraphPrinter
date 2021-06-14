#include "game_printer.h"

struct GameState {
	u32 first_heap_size = 0, second_heap_size = 0;
	std::string to_string() const {
		return "(" + std::to_string(first_heap_size) + ", " +
		       std::to_string(second_heap_size) + ")";
	}
};
struct Game {
	static VictoryStates check_winning_conditions(GameState game_state) {
		if (game_state.first_heap_size + game_state.second_heap_size >= 82)
			return VictoryStates::losing;
		else
			return VictoryStates::unknown;
	}
	static std::vector<GameState> generate_states(GameState game_state) {
		u32 const fst = game_state.first_heap_size;
		u32 const snd = game_state.second_heap_size;
		return {{fst, snd + 2}, {fst + 2, snd}, {fst, snd * 2}, {fst * 2, snd}};
	}
};

int main() {
	GamePrinter<Game, GameState, u32{2}> printer;
	printer.print_game_graph({9, 60}, 4);
}
