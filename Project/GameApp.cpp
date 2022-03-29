/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"SceneFactory.h"

CSceneBase* g_pScene = NULL;

bool		g_bDebug = false;

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectory("Resource");
	std::srand(time(NULL));


	CSceneFactory factory;

	g_pScene = factory.CreateScene(SceneType::SCENETYPE_BATTL);
	g_pScene->Initialize();

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();

	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		g_bDebug = !g_bDebug;
	}

	g_pScene->Update();
	if (g_bDebug)
	{
		g_pScene->UpdateDebug();
	}

	int StageNo = 0;
	if (g_pScene->IsEnd())
	{
		SceneType change = g_pScene->GetNextScene();
		g_pScene->Release();
		delete g_pScene;
		g_pScene = NULL;

		CSceneFactory scene;
		g_pScene = scene.CreateScene(change);
		g_pScene->Initialize();
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(1.0f,1.0f,1.0f,1.0f,1.0f,0);

	g_pScene->Render();
	if (g_bDebug)
	{
		g_pScene->RenderDebug();
	}

	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	g_pScene->Release();
	if (g_pScene)
	{
		delete g_pScene;
		g_pScene = NULL;
	}
	CMonsterDataList::GetInstance().Release();
	return TRUE;
}