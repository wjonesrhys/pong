#ifndef COLLISION_H
#define COLLISION_H

#include <player.hpp>
#include <ball.hpp>
#include <score.hpp>
#include <rectangle.hpp>

class Collision {
    private:
        sf::Vector2u windowSize;

    public:
        Collision(sf::Vector2u windowSize);
        ~Collision();
        
        void checkForCollisions(std::vector<Ball*>& balls, std::vector<Player*>& players, std::vector<Score*>& scores, std::vector<Rectangle*>& rects);

        void ballCollidingBall(std::vector<Ball*>& balls);
        void ballCollidingPaddle(std::vector<Ball*>& balls, std::vector<Player*>& players);
        void ballCollidingWall(std::vector<Ball*>& balls, std::vector<Score*>& scores);
        void rectCollidingWall(std::vector<Rectangle*>& rects);

        void paddleCollidingWall(std::vector<Player*>& players);
        

        void checkRectVsPlayer(std::vector<Rectangle*>& rects, std::vector<Player*>& players);
        void checkBallVsPlayer(std::vector<Ball*>& balls, std::vector<Player*>& players);

        bool AABBCollision(Rectangle* rect, Player* player);
        bool BallVsRect(Ball* ball, Player* player);

        bool isTopHalf(Rectangle* rect, Player* player);

        float distanceBetweenPoints(sf::Vector2f p1, sf::Vector2f p2);
};

#endif