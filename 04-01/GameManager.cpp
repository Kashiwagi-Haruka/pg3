#include "GameManager.h"
Game::Game() { state = new TitleState(); }

Game::~Game() { delete state; }

void Game::ChangeState(IState* newState) {
	delete state;
	state = newState;
}

void Game::Update(char* keys, char* preKeys) {
	state->Update(keys, preKeys);

	if (state->IsFinished()) {

		// ★次のシーンに遷移
		if (dynamic_cast<TitleState*>(state)) {
			ChangeState(new StageState());
		} else if (dynamic_cast<StageState*>(state)) {
			ChangeState(new ClearState());
		} else if (dynamic_cast<ClearState*>(state)) {
			ChangeState(new TitleState());
		}
	}
}

void Game::Draw() { state->Draw(); }