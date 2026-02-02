#include "pch.h"
#include "CameraMove.h"
#include "GameObject.h"

void CameraMove::Update()
{
	auto pos = GetTransform()->GetPosition();
	pos.x += 0.1f;
	GetTransform()->SetPosition(pos);
}
