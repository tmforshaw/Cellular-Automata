#version 460
#extension GL_ARB_separate_shader_objects : enable

layout( location = 0 ) in vec2 fragTexCoord;
layout( location = 1 ) in flat uint fragSamplerID;

// layout( binding = 1 ) uniform sampler2D texSampler1;

layout( location = 0 ) out vec4 oColour;

void main()
{
	oColour = vec4( 1.0, 0.0, 1.0, 1.0 );
}