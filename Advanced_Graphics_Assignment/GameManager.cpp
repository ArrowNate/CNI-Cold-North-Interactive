#include "GameManager.h"

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance()
{
	if (sInstance == nullptr) {
		sInstance = new GameManager();
	}
	return sInstance;
}

void GameManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void GameManager::Run() {
	while (!mQuit) {
		mTimer->Update();

		while (SDL_PollEvent(&mEvent)) {
			switch (mEvent.type) {
			case SDL_QUIT:
				mQuit = true;
				break;
			}
		}

		if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
			Update();
			LateUpdate();
			Render();
			mTimer->Reset();
		}
	}
}

void GameManager::Update() {
	mScreenManager->Update();
}

void GameManager::LateUpdate() {
	mPhysicsManager->Update();
}

void GameManager::Render() {
	mGraphics->ClearBackBuffer();
	mScreenManager->Render();
	mGraphics->Render();
}

GameManager::GameManager() : mQuit(false) {
	mGraphics = Graphics::Instance();

	if (!Graphics::Initialized()) {
		mQuit = true;
	}
	mAssetManager = AssetManager::Instance();
	mPhysicsManager = PhysicsManager::Instance();
	mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Friendly, PhysicsManager::CollisionFlags::Hostile | PhysicsManager::CollisionFlags::HostileProjectiles);
	mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::FriendlyProjectiles, PhysicsManager::CollisionFlags::Hostile);
	mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Hostile, PhysicsManager::CollisionFlags::Friendly | PhysicsManager::CollisionFlags::FriendlyProjectiles);
	mPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::HostileProjectiles, PhysicsManager::CollisionFlags::Friendly);

	mTimer = Timer::Instance();

	mScreenManager = ScreenManager::Instance();
}

GameManager::~GameManager() {
	ScreenManager::Release();
	mScreenManager = nullptr;

	Timer::Release();
	mTimer = nullptr;

	AssetManager::Release();
	mAssetManager = nullptr;

	PhysicsManager::Release();
	mPhysicsManager = nullptr;

	Graphics::Release();
	mGraphics = nullptr;

	glfwTerminate();
}