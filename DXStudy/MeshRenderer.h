#pragma once
#include "Component.h"
class MeshRenderer : public Component
{
	using Super = Component;
public:
	MeshRenderer(ComPtr<ID3D11Device> device, ComPtr<ID3D11DeviceContext> deviceContext);
	virtual ~MeshRenderer();
	
	virtual void Update() override;
	void Render(shared_ptr<Pipeline> pipeline);
private:
	ComPtr<ID3D11Device> _device;
	friend class RenderManager;
	// Geometry
	// Mesh
	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;

	// Material
	// VS
	shared_ptr<VertexShader> _vertexShader = nullptr;

	// PS
	shared_ptr<PixelShader> _pixelShader = nullptr;


private:
	shared_ptr<Texture> _texture1;

};

