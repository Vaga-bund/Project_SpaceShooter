#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
protected:
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_width;
	int m_height;
	int m_currentFrame;
	int m_currentRow;
	std::string m_textureID;
public:
	Vector2D getPosition() const { return m_position; }

	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getID() const { return m_textureID; }
	int m_numFrames;

	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};
	virtual ~SDLGameObject() {}
};