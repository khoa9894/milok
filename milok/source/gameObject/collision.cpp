#include "collision.h"

void CollisionManager::addObj(skeleton* hitBox)
{
    m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(skeleton* a, skeleton* b)
{
    return a->getGlobalBounds().intersects(b->getGlobalBounds());

}

void CollisionManager::Update()
{
    for (auto a : m_listObj) {
        if (a->isAlive() == 0) continue;
        for (auto b : m_listObj) {
            if (b->isAlive() == 0) continue;
            if (a->getTag() == b->getTag()) continue;
            if (!checkCollision(a, b)) continue;
            if (a->getTag() == PLAYER && b->getTag() == CREEP) {
                a->setAlive(0);
                b->setAlive(0);
            }
            if (a->isattack() == 1) {
                a->setAlive(1);
                b->setAlive(0);
               
            }

        }
    }
}
