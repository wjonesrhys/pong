#include <cmath>

#include <collision.hpp>
#include <SFML/Graphics.hpp>
#include <util.hpp>

Collision::Collision(sf::Vector2u windowSize) 
{
    this->windowSize = windowSize;
}

Collision::~Collision() 
{

}

void Collision::checkForCollisions(std::vector<Ball*>& balls, std::vector<Player*>& players, std::vector<Score*>& scores, std::vector<Rectangle*>& rects) 
{
    rectCollidingWall(rects);
    checkRectVsPlayer(rects, players);
    // ballCollidingWall(balls, scores);
    // checkBallVsPlayer(balls, players);
    // paddleCollidingWall(players);
    // ballCollidingBall(balls);
    // ballCollidingPaddle(balls, players);
}

void Collision::ballCollidingBall(std::vector<Ball*>& balls) 
{
//     for (Ball ball : balls) {
//         for (Ball otherBall : balls) {
//             if (distanceBetweenPoints(ball.getPosition(), otherBall.getPosition()) < ball.getRadius()) {
//                 // std::cout << "colliding");
//             } else {
//                 // print ("not colliding");
//             }
//         }
//     }
//     //speed calculation
//     //momentum calc
//     //choose directions to send both in
}

void Collision::ballCollidingPaddle(std::vector<Ball*>& balls, std::vector<Player*>& players) 
{
    sf::Vector2f ballPosition;
    for (Ball* ball : balls) 
    {
        ballPosition = ball->getPosition();
        for (Player* player : players) 
        {
            bool topHalf = player->getPosition().x > ballPosition.x;
            bool verticalFace = false;

            // if (player->getPlayerNum() == 1) 
            // {
            //     if (ball->getPosition().x - ball->getRadius() < player->getPosition().x + player->getWidth()/2 ) 
            //     {
            //         ball->reverseDirectionHorizontal();
            //         ball->setLastPosition();
            //     }
            // }

            // if (player->getPlayerNum() == 2) 
            // {
            //     if (ball->getPosition().x + ball->getRadius() > player->getPosition().x - player->getWidth()/2 ) 
            //     {
            //         ball->reverseDirectionHorizontal();
            //         ball->setLastPosition();
            //     }
            // }
        }
    }
}

void Collision::ballCollidingWall(std::vector<Ball*>& balls, std::vector<Score*>& scores)  
{
    sf::Vector2f ballPosition;
    for (Ball* ball : balls) {

        ballPosition = ball->getPosition();

        if (ballPosition.x + ball->getRadius() > (windowSize.x - ball->getRadius())) 
        {
            scores.at(0)->increaseScore();
            ball->setStartingPosition();
            ball->setRandomDirection();
        }

        if (ballPosition.x - ball->getRadius() < (0 + ball->getRadius())) 
        {
            scores.at(1)->increaseScore();
            ball->setStartingPosition();
            ball->setRandomDirection();
        }

        if (ballPosition.y - ball->getRadius() < 0) 
        {
            ball->reverseDirectionVertical();
        }

        if (ballPosition.y + ball->getRadius() > windowSize.y) 
        {
            ball->reverseDirectionVertical();
        }
    }
}

void Collision::rectCollidingWall(std::vector<Rectangle*>& rects) {
    sf::Vector2f rectPosition;
    for (Rectangle* rect : rects) {

        rectPosition = rect->getPosition();

        if (rectPosition.x > (windowSize.x - rect->getWidth()/2)) 
        {
            // scores.at(0)->increaseScore();
            rect->setStartingPosition();
            rect->setRandomDirection();
        }

        if (rectPosition.x < (0 + rect->getWidth()/2)) 
        {
            // scores.at(1)->increaseScore();
            rect->setStartingPosition();
            rect->setRandomDirection();
        }

        if (rectPosition.y - rect->getWidth()/2 < 0) 
        {
            rect->reverseDirectionVertical();
        }

        if (rectPosition.y + rect->getWidth()/2 > windowSize.y) 
        {
            rect->reverseDirectionVertical();
        }
    }
}

void Collision::paddleCollidingWall(std::vector<Player*>& players) 
{
    for (Player* player : players) 
    {
        float playerHeight = player->getHeight();

        if (player->getLowestPoint() < 0) 
        {
            player->setPosition(player->getPosition().x, playerHeight/2);
        }

        if (player->getHighestPoint() > windowSize.y) 
        {
            player->setPosition(player->getPosition().x, windowSize.y - playerHeight/2);
        }
    }
}

void Collision::checkBallVsPlayer(std::vector<Ball*>& balls, std::vector<Player*>& players)
{
    for (Ball* ball : balls) {
        for (Player* player : players) {
            if (BallVsRect(ball, player)) 
            {
                std::cout << "you are witnessing cheating" << std::endl;
                //calculate which side to resolve
                //compensation
                //make it bounce
            }
            // std::cout << AABBCollision(rect, player) << std::endl;
        }
    }
}

void Collision::checkRectVsPlayer(std::vector<Rectangle*>& rects, std::vector<Player*>& players) 
{
    for (Rectangle* rect : rects) {
        for (Player* player : players) {
            if (AABBCollision(rect, player)) 
            {
                bool compensation;
                std::cout << "is top half: " << isTopHalf(rect, player) << std::endl;

                //if inside the bounds then normal collision

                //else do the other checking and resolve accordingly 

                // check for the top or bottom half
                if (isTopHalf(rect, player)) {

                    float horizontalOverlap = rect->getWidth() - (player->getPosition().x - player->getWidth()/2);
                    float verticalOverlap = rect->getHeight() - (player->getPosition().x - player->getWidth()/2);

                    if (player->getPlayerNum() == 1) 
                    {
                        //check which resolution path to take
                        if (horizontalOverlap > verticalOverlap) 
                        {
                            //resolve the position
                            rect->setPosition(sf::Vector2f(rect->getPosition().x - horizontalOverlap, rect->getPosition().y)); 
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y));
                            //resolve the direction
                            rect->reverseDirectionHorizontal();

                        } else {
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y)); 
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y - verticalOverlap));
                            rect->reverseDirectionVertical();
                        }
                    } 
                    if (player->getPlayerNum() == 2) 
                    {
                        if (horizontalOverlap > verticalOverlap) 
                        {
                            rect->setPosition(sf::Vector2f(rect->getPosition().x + horizontalOverlap, rect->getPosition().y)); 
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y));
                            rect->reverseDirectionHorizontal();
                        } else {
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y)); 
                            rect->setPosition(sf::Vector2f(rect->getPosition().x, rect->getPosition().y - verticalOverlap));
                            rect->reverseDirectionVertical();
                        }
                    }
                }
            }
        }
    }
}

bool Collision::AABBCollision(Rectangle* rect, Player* player) 
{
    sf::Vector2f rPos = rect->getPosition();
    sf::Vector2f pPos = player->getPosition();

    if (rPos.x + rect->getWidth()/2 >= pPos.x - player->getWidth()/2 &&     // r1 right edge past r2 left
        rPos.x - rect->getWidth()/2 <= pPos.x + player->getWidth()/2 &&     // r1 left edge past r2 right - checking for it not being past the object also
        rPos.y + rect->getHeight() >= pPos.y &&     // r1 top edge past r2 bottom
        rPos.y <= pPos.y + player->getHeight())       // r1 bottom edge past r2 top
    {                           
        return true;
    }
    return false;
}

bool Collision::BallVsRect(Ball* ball, Player* player) 
{
    sf::Vector2f bPos = ball->getPosition();
    sf::Vector2f pPos = player->getPosition();
    // temporary variables to set edges for testing
    float testX = bPos.x;
    float testY = bPos.y;

    // which edge is closest?
    if (bPos.x < pPos.x)         
        testX = pPos.x;      // test left edge
    else if (bPos.x > pPos.x+player->getWidth()) 
        testX = pPos.x+player->getWidth();   // right edge
    if (bPos.y < pPos.y)         
        testY = pPos.y;      // top edge
    else if (bPos.y > pPos.y+player->getHeight()) 
        testY = pPos.y+player->getHeight();   // bottom edge

    // get distance from closest edges
    float distX = bPos.x-testX;
    float distY = bPos.y-testY;
    float distance = sqrt( (distX*distX) + (distY*distY) );

    // if the distance is less than the radius, collision!
    if (distance <= ball->getRadius()) {
        return true;
    }
    return false;
}

bool Collision::isTopHalf(Rectangle* rect, Player* player) {
    return rect->getPosition().y < player->getPosition().y;
}

float Collision::distanceBetweenPoints(sf::Vector2f p1, sf::Vector2f p2) 
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}