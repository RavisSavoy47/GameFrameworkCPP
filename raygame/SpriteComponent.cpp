#include "SpriteComponent.h"
#include <raylib.h>
#include "Transform2D.h"
#include "Actor.h"
#include <Matrix3.h>
#include <cmath>

SpriteComponent::SpriteComponent(Texture2D* texture, const char* name) : Component::Component(name)
{
	m_texture = texture;
}

SpriteComponent::SpriteComponent(const char* path, const char* name) : Component::Component(name)
{
	m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
}

SpriteComponent::~SpriteComponent()
{
	RAYLIB_H::UnloadTexture(*m_texture);
	delete m_texture;
}

void SpriteComponent::draw()
{
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01, getOwner()->getTransform()->getGlobalMatrix()->m11 };
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();

	position = position - (forward * getWidth() / 2);
	position = position - (up * getWidth() / 2);

	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	float rotation = atan2(getOwner()->getTransform()->getGlobalMatrix()->m10, getOwner()->getTransform()->getGlobalMatrix()->m00);
}
