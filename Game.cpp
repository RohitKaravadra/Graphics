#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Timer.h"
#include "Camera.h"
#include <sstream>

const unsigned int WIDTH = 1000;
const unsigned int HEIGHT = 1000;

//int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
int main()
{
	Window win;
	Timer timer;

	Camera camera(Vec2(WIDTH, HEIGHT), Vec3(0, 5, 50), Vec3(0, 0, 0));

	Matrix planeWorld = Matrix::Translation(Vec3(0, -1, 0));
	Matrix cubeWorld = Matrix::Translation(Vec3(0, 1, 0));
	Matrix sphereWorld = Matrix::Translation(Vec3(2, 1, 0));
	Matrix treeWorld = Matrix::Translation(Vec3(-2, 1, 0)).Mul(Matrix::Scaling(Vec3(0.01f, 0.01f, 0.01f)));

	win.Create(WIDTH, HEIGHT, "My Window", false, 100, 0);
	DXCore& device = win.GetDevice();

	ShaderManager::SetDevice(device);
	ShaderManager::Add("1", "Shaders/StaticMeshVertexShader.hlsl", "Shaders/StaticMeshPixelShader.hlsl");

	Cube cube(device);
	Sphere sphere(10, 10, 1, device);
	Plane plane(device);
	Model tree("Models/Trees/Models/acacia.gem", device);

	win.inputs.SetCursorLock(true);
	float dt, moveSpeed = 10, rotSpeed = 100;

	while (true)
	{
		win.Update();

		dt = timer.dt();

		Vec2 moveDelta = win.inputs.GetAxis() * dt;
		Vec2 rotDelta = -win.inputs.MouseDelta() * dt;

		if (moveDelta.Length() > 0)
			camera.Move(Vec3(moveDelta.x, 0, moveDelta.y) * moveSpeed);
		if (rotDelta.Length() > 0)
			camera.Rotate(rotDelta.x * rotSpeed, rotDelta.y * rotSpeed);

		Matrix vp = camera.GetViewProjMat();

		win.Clear();

		ShaderManager::UpdateConstant("1", ShaderType::Vertex, "staticMeshBuffer", "VP", &vp);

		ShaderManager::UpdateConstant("1", ShaderType::Vertex, "staticMeshBuffer", "W", &planeWorld);
		ShaderManager::Apply("1");
		plane.Draw(device);

		ShaderManager::UpdateConstant("1", ShaderType::Vertex, "staticMeshBuffer", "W", &cubeWorld);
		ShaderManager::Apply("1");
		cube.Draw(device);

		ShaderManager::UpdateConstant("1", ShaderType::Vertex, "staticMeshBuffer", "W", &sphereWorld);
		ShaderManager::Apply("1");
		sphere.Draw(device);

		ShaderManager::UpdateConstant("1", ShaderType::Vertex, "staticMeshBuffer", "W", &treeWorld);
		ShaderManager::Apply("1");
		tree.Draw(device);

		win.Present();

		if (win.inputs.KeyPressed(VK_ESCAPE))
			break;
	}

	return 0;
}