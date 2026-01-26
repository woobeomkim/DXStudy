#include "pch.h"
#include "VertextBuffer.h"

VertextBuffer::VertextBuffer(ComPtr<ID3D11Device> device)
	: _device(device)
{
}

VertextBuffer::~VertextBuffer()
{
}
