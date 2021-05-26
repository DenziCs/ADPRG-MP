#include "TransitionUpdate.h"

TransitionUpdate::TransitionUpdate(string name, string nextScene, float timer) : AComponent(name, Script) {
	this->next = nextScene;
	this->timer = timer;
}

TransitionUpdate::~TransitionUpdate() {
	AComponent::~AComponent();
}

void TransitionUpdate::perform() {
	this->timer -= this->deltaTime.asSeconds();

	if (timer <= 0) {
		SceneManager::getInstance()->loadScene(next);
	}
}