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
	void CreateInputLayout();
	void CreateVS();
	void CreatePS();

	void CreateRasterizerState();
	void CreateSamplerState();
	void CreateBlendState();
	void CreateSRV();

	void CreateConstantBuffer();

	void LoadShaderFromFile(const wstring& path, const string& name, const string& version, ComPtr<ID3DBlob>& blob);
private:
	HWND _hwnd = nullptr;
	//uint32 _width = 0;
	//uint32 _height = 0;

	shared_ptr<Graphics> _graphics;
private:
	
	// Misc
	D3D11_VIEWPORT _viewport = {0};
	float _clearColor[4] = { 0.f,0.f,0.f,0.f };

private:
	// Geometry

	//vector<Vertex> _vertices;
	//vector<uint32> _indices;
	
	shared_ptr<Geometry<VertexTextureData>> _geometry;
	shared_ptr<VertextBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<InputLayout> _inputLayout;
	//ComPtr<ID3D11InputLayout> _inputLayout = nullptr;

	// VS
	ComPtr<ID3D11VertexShader> _vertexShader = nullptr;
	ComPtr<ID3DBlob> _vsBlob = nullptr;
	//RAS
	ComPtr<ID3D11RasterizerState> _rasterizerState = nullptr;
	
	// PS
	ComPtr<ID3D11PixelShader> _pixelShader = nullptr;
	ComPtr<ID3DBlob> _psBlob = nullptr;

	// SharderResourceView
	ComPtr<ID3D11ShaderResourceView> _shaderResourceView;

	ComPtr<ID3D11SamplerState> _samplerState = nullptr;
	ComPtr<ID3D11BlendState> _blendState = nullptr;
private:
	TransformData _transformData;
	ComPtr<ID3D11Buffer> _constantBuffer;

	Vec3 _localPosition = { 0.f,0.f,0.f };
	Vec3 _localRotation = { 0.f,0.f,0.f };
	Vec3 _localScale = { 1.f,1.f,1.f };
};

