#include "physics_manager.h"

constexpr uint32 VELOCITY_ITERATIONS = 6;
constexpr uint32 POSITION_ITERATIONS = 2;
constexpr unsigned int WINDOW_WIDTH_PIXELS = 600;
constexpr float WINDOW_WIDTH = 10.0;
constexpr unsigned int PIXELS_PER_UNIT = WINDOW_WIDTH_PIXELS / WINDOW_WIDTH;
constexpr float BOX_WIDTH = 1.0;

namespace
{
	b2BodyType get_real_body_type(LeBody::Type type)
	{
		switch (type) {
		case LeBody::Type::STATIC:
			return b2_staticBody;
		case LeBody::Type::DYNAMIC:
			return b2_dynamicBody;
		case LeBody::Type::KINEMATIC:
			return b2_kinematicBody;
		}
		return b2_staticBody;
	}
}

LeBody::LeBody(b2Body* b) : m_body(b)
{
}

float LeBody::get_current_x()  const
{
	b2Vec2 vec = m_body->GetPosition();
	float32 angle = m_body->GetAngle();

	return (vec.x * PIXELS_PER_UNIT + (WINDOW_WIDTH_PIXELS / 2));
}

float LeBody::get_current_y() const
{
	b2Vec2 vec = m_body->GetPosition();
	float32 angle = m_body->GetAngle();

	return (WINDOW_WIDTH_PIXELS - vec.y * PIXELS_PER_UNIT);
}

LePhysicsManager::LePhysicsManager()
{
	//TODO add function call to manage :P
	b2Vec2 gravity(0, -9.8);
	m_world = new b2World(gravity);
}

LeBody* LePhysicsManager::create_body(LeBody::Type type, float width, float height )
{
	b2Body* body;
	{
		// Falling box
		b2BodyDef bodyDef;
		bodyDef.type = get_real_body_type(type);
		bodyDef.position.Set(0.0f, WINDOW_WIDTH);
		bodyDef.angle = 3.1415f / 3.0;
		body = m_world->CreateBody(&bodyDef);
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(width, height);
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 0.5f;
		body->CreateFixture(&fixtureDef);
	}
	//return body;
	return new LeBody(body);
}

void LePhysicsManager::update()
{
	m_world->Step(0.01, VELOCITY_ITERATIONS, POSITION_ITERATIONS);
}

