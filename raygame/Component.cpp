#include "Component.h"

Component::Component()
{

}

Component::Component(Actor* name, const char* componentName)
{
	m_owner = name;
	m_name = componentName;
}

Component::~Component()
{
}

const char* Component::getName()
{
	return m_name;
}

Actor* Component::getOwner()
{
	return m_owner;
}

void Component::start()
{
	m_started = true;
}

void Component::update(float deltaTime)
{
}

void Component::draw()
{
}

void Component::end()
{
}

void Component::onCollision(Actor*)
{
}
