#include "Ball.h"



Ball::Ball()
{
	m_pInput = InputManager::Instance();


	
	DirectionY = 1;
	DirectionX = -1;
	
	Velocity = 350;


}

Ball::~Ball()
{
}

void Ball::Movement()
{
}

void Ball::Update()
{
}

void Ball::Render()
{
}
