#pragma once

#include "../Buffers/Buffers.hpp"
#include "../Buffers/Vertex.hpp"
#include "../VulkanUtil/Window.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

struct MVP
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};

class Display
{
private:
	// uint16_t m_width;
	// uint16_t m_height;

	MVP m_MVP;

public:
	void Init()
	{
		// Set the MVP matrix
		m_MVP.model = glm::scale( glm::translate( glm::mat4( 1.0f ), glm::vec3( 0.0f, 0.0f, 0.0f ) ), glm::vec3( 100.0f, 100.0f, 100.0f ) );
		m_MVP.view	= glm::mat4( 1.0f );
		m_MVP.proj	= glm::ortho( 0.0f, static_cast<float>( WINDOW_WIDTH ), static_cast<float>( WINDOW_HEIGHT ), 0.0f, -5.0f, 5.0f );
	}

	const MVP& GetMVP() { return m_MVP; }
};

const std::vector<Vertex> quadVertices = {
	{ { 0.0f, 0.0f } },
	{ { 1.0f, 0.0f } },
	{ { 1.0f, 1.0f } },
	{ { 0.0f, 1.0f } }
};

const std::vector<IndexBufferType> quadIndices = {
	0, 1, 2, 2, 3, 0
};