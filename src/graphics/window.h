#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
namespace sparx {

	namespace graphics {
#define MAX_KEYS	1024
#define MAX_BUTTONS 32
		class Window
		{

		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

			bool m_Keys[MAX_KEYS];							// Must be static probably ...
			bool m_MouseButtons[MAX_BUTTONS];				// ...for callbacks
			double mX, mY;

		public:
			Window(const char *title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth()  const { return m_Width; };		// inline avoids creation of stack frame
			inline int getHeight() const { return m_Height; };

			bool isKeyPressed(unsigned int keycode) const;			// Consts because they are getting values, not setting any
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;


		private:
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
		
	}



}