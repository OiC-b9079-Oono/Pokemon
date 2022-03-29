#pragma once
#include "SceneTitle.h"
#include "SceneBattle.h"
#include "SceneOption.h"

class CSceneFactory 
{
public:
	CSceneBase* CreateScene(SceneType scene_type) {
		switch (scene_type)
		{
		case SCENETYPE_TITLE:
			return new CScenTitle();
		case SCENETYPE_BATTL:
			return new CSceneBattle();
		case SCENETYPE_OPTION:
			return new CSceneOption();
		default:
			break;
		}
		return nullptr;
	}
};