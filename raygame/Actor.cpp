#include "Actor.h"
#include "Transform2D.h"
#include <string.h>
#include "Collider.h"
#include "Component.h"

Actor::Actor()
{
    m_transform = new Transform2D(this);
}

Actor::~Actor()
{
    delete m_transform;
}


Actor::Actor(float x, float y, const char* name = "Actor")
{
    //Initialze default values
    m_transform = new Transform2D(this);
    m_transform->setLocalPosition({ x,y });
    m_name = name;
}



void Actor::onCollision(Actor* other)
{
}

Component* Actor::addComponent(Component* component)
{
    //Create a new component with a size one greater than our old array
    Component** appendedComponent = new Component* [m_componentCount + 1];
    //Copy the values from the old component to the new component
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedComponent[i] = m_component[i];
    }

    //Set the last value in the new component to be the component we want to add
    appendedComponent[m_componentCount] = component;
    //Set old component to hold the values of the new component
    m_component = appendedComponent;
    m_componentCount++;
}

bool Actor::removeComponent(Component* component)
{
    //Check to see if the component was null
    if (!component)
    {
        return false;
    }

    bool actorRemoved = false;
    //Create a new component with a size one less than our old component
    Component** newComponent = new Component* [m_componentCount - 1];
    //Create variable to access newcomponent index
    int j = 0;
    //Copy values from the old component to the new component
    for (int i = 0; i < m_componentCount; i++)
    {
        if (component != m_component[i])
        {
            newComponent[j] = m_component[i];
            j++;
        }
        else
        {
            actorRemoved = true;
        }
    }
    //Set the old component to the new component
    if (actorRemoved)
    {
        m_component = newComponent;
        m_componentCount--;
    }
    //Return whether or not the removal was successful
    return actorRemoved;
}

bool Actor::removeComponent(const char* componentName)
{
    //Check to see if the component Name was null
    if (!componentName)
    {
        return false;
    }

    bool actorRemoved = false;
    //Create a new component with a size one less than our old component
    Component** newComponent = new Component * [m_componentCount - 1];
    //Create variable to access component index
    int j = 0;
    //Copy values from the old component to the new component
    for (int i = 0; i < m_componentCount; i++)
    {
        if (componentName != m_component[i]->getName())
        {
            newComponent[j] = m_component[i];
            j++;
        }
        else
        {
            actorRemoved = true;
        }
    }
    //Set the old component to the new component
    if (actorRemoved)
    {
        m_component = newComponent;
        m_componentCount--;
    }
    //Return whether or not the removal was successful
    return actorRemoved;
}

Component* Actor::getComponet(const char* componentName)
{
    for (int i = 0; i < m_componentCount; i++)
    {
        if (componentName == m_component[i]->getName())
        {
            return m_component[i];
        }
    }
    return nullptr;
}

void Actor::start()
{
    m_started = true;
}

void Actor::update(float deltaTime)
{
}

void Actor::draw()
{
}

void Actor::end()
{
    m_started = false;
}

void Actor::onDestroy()
{
    //Removes this actor from its parent if it has one
    if (getTransform()->getParent())
        getTransform()->getParent()->removeChild(getTransform());
}

bool Actor::checkForCollision(Actor* other)
{
    //Call check collision if there is a collider attached to this actor
    if (m_collider)
        return m_collider->checkCollision(other);

    return false;
}