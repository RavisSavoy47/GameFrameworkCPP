#pragma once
#include "Component.h"
class MoveComponent :
	public Component
{
public:
	MoveComponent();
	MoveComponent(Actor* owner, const char* name, float speed);
	~MoveComponent();

	void start() override; 
	void update(float deltaTime) override;
	void draw() override;
	void end() override;

private:
	float m_velocity;
};

