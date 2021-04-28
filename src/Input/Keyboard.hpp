#pragma once

#include "../VulkanUtil/Timing.hpp"
#include "../VulkanUtil/Window.hpp"

#include <GLFW/glfw3.h>
#include <bitset>
#include <map>

std::map<char, uint16_t> Key {
	{ GLFW_KEY_ESCAPE, 0 },
	{ GLFW_KEY_SPACE, 1 },
	{ GLFW_KEY_LEFT_SHIFT, 2 },
	{ GLFW_KEY_LEFT_CONTROL, 3 },
	{ GLFW_KEY_LEFT_ALT, 4 },

	{ GLFW_KEY_Q, 5 },
	{ GLFW_KEY_W, 6 },
	{ GLFW_KEY_E, 7 },
	{ GLFW_KEY_R, 8 },
	{ GLFW_KEY_T, 9 },
	{ GLFW_KEY_Y, 10 },
	{ GLFW_KEY_U, 11 },
	{ GLFW_KEY_I, 12 },
	{ GLFW_KEY_O, 13 },
	{ GLFW_KEY_P, 14 },
	{ GLFW_KEY_A, 15 },
	{ GLFW_KEY_S, 16 },
	{ GLFW_KEY_D, 17 },
	{ GLFW_KEY_F, 18 },
	{ GLFW_KEY_G, 19 },
	{ GLFW_KEY_H, 20 },
	{ GLFW_KEY_J, 21 },
	{ GLFW_KEY_K, 22 },
	{ GLFW_KEY_L, 23 },
	{ GLFW_KEY_Z, 24 },
	{ GLFW_KEY_X, 25 },
	{ GLFW_KEY_C, 26 },
	{ GLFW_KEY_V, 27 },
	{ GLFW_KEY_B, 28 },
	{ GLFW_KEY_N, 29 },
	{ GLFW_KEY_M, 30 },

	{ GLFW_KEY_0, 31 },
	{ GLFW_KEY_1, 32 },
	{ GLFW_KEY_2, 33 },
	{ GLFW_KEY_3, 34 },
	{ GLFW_KEY_4, 35 },
	{ GLFW_KEY_5, 36 },
	{ GLFW_KEY_6, 37 },
	{ GLFW_KEY_7, 38 },
	{ GLFW_KEY_8, 39 },
	{ GLFW_KEY_9, 40 },

	{ GLFW_KEY_F1, 41 },
	{ GLFW_KEY_F2, 42 },
	{ GLFW_KEY_F3, 43 },
	{ GLFW_KEY_F4, 44 },
	{ GLFW_KEY_F5, 45 },
	{ GLFW_KEY_F6, 46 },
	{ GLFW_KEY_F7, 47 },
	{ GLFW_KEY_F8, 48 },
	{ GLFW_KEY_F9, 49 },
	{ GLFW_KEY_F10, 50 },
	{ GLFW_KEY_F11, 51 },
	{ GLFW_KEY_F12, 52 }
};

static bool		countingFramesBool = false;
static uint32_t frameCount		   = 0;
static float	countingStartTime  = 0.0;

class KeyboardHandler
{
private:
	static std::bitset<sizeof( Key ) / sizeof( Key[0] )> m_keyMap;
	static std::bitset<sizeof( Key ) / sizeof( Key[0] )> m_releasedMap;

public:
	static inline void Set( const char &key, const bool &val )
	{
		if ( Key.count( key ) > 0U ) // Exists in map
		{
			if ( m_keyMap[Key[key]] == true && val == false )
				m_releasedMap[Key[key]] = true;

			m_keyMap[Key[key]] = val;
		}
	}

	static void ProcessInput( GLFWwindow *p_window, const float &deltaT )
	{
		// When escape is pressed, close the window
		if ( m_keyMap[Key[(char)GLFW_KEY_ESCAPE]] ) glfwSetWindowShouldClose( p_window, true );

		// When the F10 key is pressed or released count the fps
		if ( m_keyMap[Key[(char)GLFW_KEY_F10]] )
		{
			if ( countingFramesBool )
			{
				frameCount++;
			}
			else
			{
				frameCount		   = 0;
				countingFramesBool = true;
				countingStartTime  = timeElapsed;
			}
		}
		else if ( m_releasedMap[Key[(char)GLFW_KEY_F10]] )
		{
			std::cout << "Average FPS: " << frameCount / ( timeElapsed - countingStartTime ) << " (over " << ( timeElapsed - countingStartTime ) << "s)" << std::endl;
		}

		// Set all released keys to false
		m_releasedMap = 0;
	}
};

std::bitset<sizeof( Key ) / sizeof( Key[0] )> KeyboardHandler::m_keyMap		 = 0;
std::bitset<sizeof( Key ) / sizeof( Key[0] )> KeyboardHandler::m_releasedMap = 0;