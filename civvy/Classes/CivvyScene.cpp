#include "CivvyScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

CivvyScene* CivvyScene::createScene()
{
	return CivvyScene::create();
}

// on "init" you need to initialize your instance
bool CivvyScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CivvyScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	//auto menu = Menu::create(closeItem, NULL);
	//menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("asdfasdf", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("terrain_base.plist");

	Sprite* Sprite1 = Sprite::createWithSpriteFrameName("arctic.png");

	double spriteWidthX = (Sprite1->getBoundingBox().getMaxX() - Sprite1->getBoundingBox().getMinX());
	double spriteHeightY = (Sprite1->getBoundingBox().getMaxY() - Sprite1->getBoundingBox().getMinY());

	Sprite1->setPosition(256.0, 256.0);

	Sprite* Sprite2 = Sprite::createWithSpriteFrameName("desert.png");

	Sprite2->setPosition(256.0 + spriteWidthX, 256.0);

	Sprite* Sprite3 = Sprite::createWithSpriteFrameName("arctic.png");

	Sprite3->setPosition(256.0 + spriteWidthX / 2.0, 256.0 + spriteHeightY / 2.0);

	Sprite* Sprite4 = Sprite::createWithSpriteFrameName("desert.png");

	Sprite4->setPosition(256.0 + spriteWidthX / 2.0 + spriteWidthX, 256.0 + spriteHeightY / 2.0);

	addChild(Sprite1);
	addChild(Sprite2);
	addChild(Sprite3);
	addChild(Sprite4);

	return true;
}


void CivvyScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
