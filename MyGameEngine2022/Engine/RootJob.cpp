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
	Instantiate<PlayScene>(this);
}

void RootJob::Update()
{

}

void RootJob::Draw()
{
}
void RootJob::Release()
{
}