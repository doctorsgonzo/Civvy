#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
public:
    static MenuScene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	std::function<void()> _startCivvyCallback;

	void MenuScene::setStartCivvyCallback(std::function<void()>);
    
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif // __HELLOWORLD_SCENE_H__
