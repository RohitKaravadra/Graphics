#pragma once
#include "Shader.h"

// render target class
class RenderTarget
{
public:
	ID3D11Texture2D* texture;
	ID3D11RenderTargetView* view;
	ID3D11ShaderResourceView* srv; // shader resource view
	RenderTarget(unsigned int _width, unsigned int _height, DXGI_FORMAT _format, DXCore* _driver);
	~RenderTarget();
};

class ZBuffer
{
public:
	ID3D11Texture2D* texture;
	ID3D11DepthStencilView* depthStencilView;
	ID3D11ShaderResourceView* srv;
	ZBuffer(unsigned int _width, unsigned int _height, DXCore* _driver);
	~ZBuffer();
};

// Full screen quad shader for Deffered shading
class FullScreenQuad
{
	ID3D11VertexShader* vertexShader;
	ID3D11PixelShader* pixelShader;

	std::vector<ConstantBuffer> psConstantBuffers;
	std::map<std::string, int> textureBindPointsPS;

	void CompileVertexShader(std::string _location, DXCore& _driver);
	void CompilePixelShader(std::string _location, DXCore& _driver);
	void Apply(DXCore* _driver);
public:
	FullScreenQuad(std::string _vsLocation, std::string _psLocation, DXCore* _driver);
	// draw texture to full screen quad and to screen
	void Draw(DXCore* _driver);
	// Set Texture
	void SetTexture(std::string _name, ID3D11ShaderResourceView* srv, DXCore* _driver);
	~FullScreenQuad();
};

class GBuffer
{
	RenderTarget* albedo;
	RenderTarget* normal;
	RenderTarget* tangent;

	ID3D11RenderTargetView* renderTargetViews[3];
	ID3D11ShaderResourceView* shaderResourceViews[4];

public:
	FullScreenQuad* fullScreenQuad;
	ZBuffer* zBuffer;

	GBuffer(unsigned int _width, unsigned int _height, DXCore* _driver);
	void Clear(DXCore* _driver);
	void Apply(DXCore* _driver);
	void Draw(DXCore* _driver);
	~GBuffer();
};

class DeferredRenderer
{
	GBuffer* gBuffer;
	DXCore* driver;
public:
	void Init(unsigned int _width, unsigned int _height, DXCore* _driver);
	void SetPassOne();
	void SetPassTwo();
	void Draw();
	~DeferredRenderer();
};