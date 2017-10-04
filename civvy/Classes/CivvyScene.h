#ifndef __CIVVY_SCENE_H__
#define __CIVVY_SCENE_H__

#include "cocos2d.h"

class CivvyScene : public cocos2d::Scene
{
public:
	static CivvyScene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(CivvyScene);
};

#endif // __HELLOWORLD_SCENE_H__
