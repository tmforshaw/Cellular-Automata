#version 460
#extension GL_ARB_separate_shader_objects : enable

layout( location = 0 ) in vec2 inPosition;
layout( location = 1 ) in uint inSamplerID;

// clang-format off
layout( binding = 0 ) uniform VertexUniformBufferObject
{
	vec4 colour;
	mat4 model;
	mat4 view;
	mat4 proj;
} ubo;
// clang-format on

layout( location = 0 ) out vec2 oFragTexCoord;
layout( location = 1 ) out flat uint oFragSamplerID;

void main()
{
	// Position for the vertex shader output
	gl_Position = ubo.proj * ubo.view * ubo.model * vec4( inPosition, 0.0, 1.0 );

	// Ouput variables
	oFragTexCoord  = inPosition;
	oFragSamplerID = inSamplerID;
}