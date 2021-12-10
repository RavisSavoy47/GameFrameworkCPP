#include "MoveComponent.h"
#include <Vector2.h>
#include "raylib.h"
#include "Actor.h"

MoveComponent::MoveComponent()
{

}

MoveComponent::MoveComponent(Actor* owner, const char* name, float speed) 
	:Component::Component(owner = owner, name = name)

{
	m_speed = speed;
}

MoveComponent::~MoveComponent()
{
}

void MoveComponent::update(float deltaTime)
{
	m_velocity = m_moveDirection.getNormalized() * m_speed * deltaTime;

	m_position = getOwner()->getTransform()->getLocalPosition();

	m_position = m_position + m_velocity;
}


