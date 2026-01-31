#include "pch.h"
#include "ResourceManager.h"
#include "Texture.h"

ResourceManager::ResourceManager(ComPtr<ID3D11Device> device)
	:_device(device)
{
}

void ResourceManager::Init()
{

}

void ResourceManager::CreateDefaultTexture()
{
	auto texture = make_shared<Texture>(_device);
	texture->SetName(L"Red");
	texture->Create(L"Test.png");
	Add(texture->GetName(), texture);
}

void ResourceManager::CreateDefaultMesh()
{
}

void ResourceManager::CreateDefaultShader()
{
}

void ResourceManager::CreateDefaultMaterial()
{
}

void ResourceManager::CreateDefaultAnimation()
{
}
