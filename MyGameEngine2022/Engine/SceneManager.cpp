#include "SceneManager.h"
#include "Model.h"
#include "../PlayScene.h"
#include "../TitleScene.h"
#include "../ClearScene.h"

//コンストラクタ
SceneManager::SceneManager(GameObject* parent)
	: GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{
}

//初期化
void SceneManager::Initialize()
{
	//最初のシーンを準備
	currentSceneID_ = SCENE_ID_TITLE;
	nextSceneID_ = currentSceneID_;
	Instantiate<TitleScene>(this);
}

//更新
void SceneManager::Update()
{
    //次のシーンが現在のシーンと違う ＝ シーンを切り替えなければならない
    if (currentSceneID_ != nextSceneID_)
    {
        //そのシーンのオブジェクトを全削除
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();

        //ロードしたデータを全削除
        Model::Release();

        //次のシーンを作成
        switch (nextSceneID_)
        {
        case SCENE_ID_TITLE: Instantiate<TitleScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        case SCENE_ID_CLEAR: Instantiate<ClearScene>(this); break;
        }

        currentSceneID_ = nextSceneID_;
    }
}

//描画
void SceneManager::Draw()
{
}

//開放
void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SCENE_ID next)
{
    nextSceneID_ = next;
}