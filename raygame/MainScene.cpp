#include "MainScene.h"
#include "Player.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"

void MainScene::start()
{
    Player* player = new Player(50, 50, "Player");
    player->getTransform()->setScale({ 50, 50 });
    addActor(player);
}