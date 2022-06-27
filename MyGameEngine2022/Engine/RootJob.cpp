#include "RootJob.h"
#include "../PlayScene.h"

RootJob::RootJob()
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize(void)
{
	PlayScene* pPlayScene;
	pPlayScene = new PlayScene();

	pPlayScene->Initialize();
	childList_.œœœœœœ(pPlayScene);
}