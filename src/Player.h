//
// Created by haimash on 7/24/25.
//

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "raylib.h"

class Player {
public:
    Player();

    [[nodiscard]] bool Init(Vector2 position, Vector2 size);

    void Update();
    void Draw() const;
    void OnGroundCollision(float groundY);
    Rectangle GetRect() const;

private:
    Rectangle m_rect;
    Vector2 m_velocity;
    bool m_onGround;
};


#endif //PLATFORMER_PLAYER_H
