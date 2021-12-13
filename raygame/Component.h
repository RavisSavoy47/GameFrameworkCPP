#pragma once
class Actor;

class Component
{
public:
	Component();
	Component(const char* name);
	virtual ~Component();

	/// <summary>
	/// Gets the name of this component instance
	/// </summary>
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Assigns the owner of this component if it doesn't already have one
	/// </summary>
	/// <param name="owner">The new owner of this component</param>
	void assignOwner(Actor* owner);

	/// <summary>
	/// Gets the actor that this component is attached to
	/// </summary>
	const char* getName() { return m_name; } 

	/// <summary>
	/// Gets whether or not or not the start function for this component instance has been called
	/// </summary>
	bool getStarted() { return m_started; }

	/// <summary>
   /// Called when this actor is destroyed 
   /// </summary>
	virtual void onDestroy();

	//Function called by actor class
	virtual void start() { m_started = true; }
	virtual void update(float deltaTime) {}
	virtual void draw() {}
	virtual void end() {}
	virtual void onCollision(Actor* other) {}

private:
	bool m_started;
	Actor* m_owner;
	const char* m_name;
};

