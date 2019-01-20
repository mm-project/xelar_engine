#ifndef LE_PHYSICS_MANAGER
#define LE_PHYSICS_MANAGER 

#include <Box2D/Box2D.h>

class LeBody
{
public:
	enum Type { STATIC, DYNAMIC, KINEMATIC };

	LeBody(b2Body*);

public:
	float get_current_x() const;

	float get_current_y() const;

private:
	b2Body* m_body;
};

class LePhysicsManager
{
public:
	static LePhysicsManager* get();

public:
	LeBody* create_body(LeBody::Type, float, float);

	void update();

private:
	LePhysicsManager();

	static LePhysicsManager* m_manager;
	b2World* m_world;
};

#endif