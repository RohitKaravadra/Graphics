#pragma once
#include "Shader.h"

class FullScreenQuad
{
	ID3D11VertexShader* vertexShader;
	ID3D11PixelShader* pixelShader;

	std::vector<ConstantBuffer> psConstantBuffers;
	std::map<std::string, int> textureBindPointsPS;

	void CompileVertexShader(std::string _shader, DXCore& _driver);
	void CompilePixelShader(std::string _shader, DXCore& _driver);
	void Apply(DXCore* _driver);
public:
	FullScreenQuad(std::string _vsLocation, std::string _psLocation, DXCore* _driver);
	void UpdateTexture(std::string _name, ID3D11ShaderResourceView* srv, DXCore* _driver);
	void Draw(DXCore* _driver);
	~FullScreenQuad();
};
