//
// Created by haimash on 7/24/25.
//

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

#include "raylib.h"

class Player {
public:
    Player();
    /// Initializes the player with a position and size.
    /// @param position Initial position of the player.
    /// @param size Width and height of the player.
    /// @return True on success.
    [[nodiscard]]
    bool Init(Vector2 position, Vector2 size);

    /// Updates the player's movement and state.
    void Update();

    /// Draws the player to the screen.
    void Draw() const;

    /// Adjusts player state upon collision with the ground.
    /// @param groundY The Y position of the ground tile collided with.
    void OnGroundCollision(float groundY);

    /// Returns the bounding rectangle of the player.
    /// @return Rectangle representing the player's position and size.
    Rectangle GetRect() const;

private:
    Rectangle m_rect;
    Vector2 m_velocity;
    bool m_onGround;
};


#endif //PLATFORMER_PLAYER_H
