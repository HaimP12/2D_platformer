//
// Created by haimash on 7/24/25.
//

#include "Player.h"

Player::Player() : m_rect(), m_velocity(), m_onGround(false)
{

}

bool Player::Init(Vector2 position, Vector2 size)
{
    m_rect = {position.x, position.y, size.x, size.y};
    m_velocity = {0, 0};
    m_onGround = false;
    return true;
}

void Player::Update()
{
    constexpr float gravity = 0.5f;

    m_velocity.y += gravity;

    if (IsKeyPressed(KEY_SPACE) && m_onGround)
    {
        m_velocity.y = -10.0f;
        m_onGround = false;
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        m_rect.x += 4;
    }
    if (IsKeyDown(KEY_LEFT))
    {
        m_rect.x -= 4;
    }

    m_rect.y += m_velocity.y;
}

void Player::Draw() const
{
    DrawRectangleRec(m_rect, RED);
}

void Player::OnGroundCollision(float groundY)
{
    m_rect.y = groundY - m_rect.height;
    m_velocity.y = 0;
    m_onGround = true;
}

Rectangle Player::GetRect() const
{
    return m_rect;
}
