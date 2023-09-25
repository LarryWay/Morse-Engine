# Morse-Engine
Author: Larry Wei
Version 1.0.0
## Description
Morse-Engine is a C++ library that translates between the English characters and Morse. The library also supports encoding Morse into binary. 

### How Morse is converted into Binary
Each character used in morse is converted into binary numbers. 
| Morse Character | Binary Equivalent |
| --------------- | ----------------- |
| '-' | 11 |
| '.' | 1 | 
| ' ' | 000 |
| '/' | 111 |

Example:
> morse: " .--. --- --. "<br>
> encoded morse: "101101101000110110110001101101


## Getting Started
### Prerequisites 
-  CMake is installed and on version 3.20+
- C++ compiler supports C++20

### Instructions

Note: In this demonstration, the *Morse-Engine* folder will be in the same directory as your project's directory. Not every project has to be structured this way. 
1. Create your project directory
2. Clone Morse-Engine into project directory
3. Create a *CMakeLists.txt* file in your project directory
4. Create a "main.cpp" C++ file ("main" can be any name)
5. Your project should have 3 parts now. 
	1. *Morse-Engine* 
	2. *CMakeLists.txt*
	3. *main.cpp*
6. Add the following text in *CMakeLists.txt*
	<blockquote>
	cmake_minimum_required(VERSION 3.20)<br>
	project(**name of project**)<br>
	set(CMAKE_CXX_STANDARD 20)<br>
	add_executable(**name of project** main.cpp)<br>
	add_subdirectory(Morse-Engine) <br>
	target_link_libraries(**name of project** MRSE-ENGINE)<br>
 	<blockquote>
8. run command *cmake -S . -B ./build* (Configure cmake and separate build files into separate directory "build")
9. run command *cd build && make* (change directory into "build" and run build / link program)
10. run *./**name of project*** (Execute program)

## Notes
- "engine.hpp" and "mrse_utility" are likely the only files needed. All other files, especially files in the core folder, should be used with caution. 

## To-Do
- Use *morse_dictionary_map* instead of *morse_dictionary*
	- **map** instead of an **array** likely to improve performance
- Add more functions to "engine.hpp", make more versatile.
	- morse to encoded stream
	- encoded stream to morse
- Make functions *constexpr* accessible 
