
#include "BioEnemyShip.h"
#include "Level.h"


BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime& gameTime)
{
	//added and edited
	float rand = (Math::GetRandomFloat() + .6) * 4;
	if (IsActive())
	{
		float x = cos(gameTime.GetTotalTime() * Math::PI + GetIndex());
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f + rand;
		float y = Math::GetRandomInt(30, 70) * gameTime.GetElapsedTime();
		TranslatePosition(x, y);

		if (!IsOnScreen()) Deactivate();
	}
	
	EnemyShip::Update(gameTime);
}


void BioEnemyShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
