#pragma once
class Game
{
public :
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	void CreateGeometry();

private:
	HWND _hwnd = nullptr;

	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;
private:
	
	// Misc
	D3D11_VIEWPORT _viewport = {0};
	float _clearColor[4] = { 0.f,0.f,0.f,0.f };

private:
	// Geometry

	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;

	// VS
	shared_ptr<VertexShader> _vertexShader = nullptr;
	//RAS
	shared_ptr<RasterizerState> _rasterizerState;
	// PS
	shared_ptr<PixelShader> _pixelShader = nullptr;

	// SharderResourceView
	shared_ptr<Texture> _texture1;

	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _blendState;
private:
	TransformData _transformData;
	shared_ptr<ConstantBuffer<TransformData>> _constantBuffer;

	Vec3 _localPosition = { 0.f,0.f,0.f };
	Vec3 _localRotation = { 0.f,0.f,0.f };
	Vec3 _localScale = { 1.f,1.f,1.f };
};

