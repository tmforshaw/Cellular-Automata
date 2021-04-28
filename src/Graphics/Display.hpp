#pragma once

#include "../Buffers/Buffers.hpp"
#include "../Buffers/Vertex.hpp"
#include "../VulkanUtil/Window.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

class Display
{
private:
public:
};

// clang-format off
const std::vector<Vertex> cubeVertices = {
	{ { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f } },
	{ {  0.5f, -0.5f, -0.5f }, { 0.0f, 0.0f } },
	{ {  0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f } },
	{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f } },
	{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f } },
	{ {  0.5f, -0.5f,  0.5f }, { 0.0f, 0.0f } },
	{ {  0.5f,  0.5f,  0.5f }, { 0.0f, 1.0f } },
	{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f } },
	{ {  0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f } },
	{ { -0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f } },
	{ { -0.5f,  0.5f, -0.5f }, { 0.0f, 1.0f } },
	{ { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f } },
	{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f } },
	{ {  0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f } },
	{ {  0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f } },
	{ {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f } }
};

const std::vector<Vertex> quadVertices = {
  {{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f}}  
};
// clang-format on

const std::vector<IndexBufferType> cubeIndices = {
	0, 2, 1, 2, 0, 3,	  // Front Face
	4, 5, 6, 6, 7, 4,	  // Back Face
	9, 10, 11, 11, 4, 9,  // Right Face
	13, 15, 2, 15, 13, 8, // Left Face
	11, 14, 5, 5, 4, 11,  // Bottom Face
	3, 13, 2, 13, 3, 12	  // Top Face
};