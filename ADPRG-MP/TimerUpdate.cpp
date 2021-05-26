#include "TimerUpdate.h"
#include "UIText.h"

TimerUpdate::~TimerUpdate() {
	AComponent::~AComponent();
}

void TimerUpdate::perform() {
	this->timer -= this->deltaTime.asSeconds();
	UIText* text = (UIText*)this->getOwner();
	text->setText(to_string(int(timer)));
}