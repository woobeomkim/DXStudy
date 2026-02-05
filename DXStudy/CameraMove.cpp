#include "pch.h"
#include "CameraMove.h"
#include "GameObject.h"

void CameraMove::Update()
{
	auto pos = GetTransform()->GetLocalPosition();
	pos.x += 0.01f;
	GetTransform()->SetPosition(pos);

}
