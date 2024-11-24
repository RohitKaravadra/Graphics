#include "Mesh.h"

void Triangle::Init(DXCore& _driver, int _N)
{
	// set triangle vertices
	vertices[0].position = Vec3(0, 1.0f, 0);
	vertices[0].colour = Color(0, 1.0f, 0);
	vertices[1].position = Vec3(-1.0f, -1.0f, 0);
	vertices[1].colour = Color(1.0f, 0, 0);
	vertices[2].position = Vec3(1.0f, -1.0f, 0);
	vertices[2].colour = Color(0, 0, 1.0f);

	// set vertex buffer data
	D3D11_BUFFER_DESC bd;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0;
	bd.MiscFlags = 0;
	bd.ByteWidth = sizeof(Vertex) * _N;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	// create vertex buffer
	D3D11_SUBRESOURCE_DATA uploadData;
	uploadData.pSysMem = vertices;
	uploadData.SysMemPitch = 0;
	uploadData.SysMemSlicePitch = 0;

	// upload vertex buffer to device
	_driver.device->CreateBuffer(&bd, &uploadData, &vertexBuffer);
}

void Triangle::Draw(DXCore& _driver) const
{
	UINT offsets = 0;
	UINT strides = sizeof(Vertex);

	_driver.devicecontext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	_driver.devicecontext->IASetVertexBuffers(0, 1, &vertexBuffer, &strides, &offsets);
	_driver.devicecontext->Draw(3, 0);
}