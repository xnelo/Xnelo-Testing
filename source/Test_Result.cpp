/**
* @file Test_Result.cpp
* @author Spencer Hoffa
*
* @copyright 2014 Spencer Hoffa
*
* The implementation of the Test_Result class.
*
*/
/*
* The zlib/libpng License
*
* Copyright (c) 2014 Spencer Hoffa
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from the
* use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*		1. The origin of this software must not be misrepresented; you must not
*		claim that you wrote the original software. If you use this software in
*		a product, an acknowledgment in the product documentation would be
*		appreciated but is not required.
*
*		2. Altered source versions must be plainly marked as such, and must not
*		be misrepresented as being the original software.
*
*		3. This notice may not be removed or altered from any source
*		distribution.
*
* This liscense can also be found at: http://opensource.org/licenses/Zlib
*/

#include "Test_Result.hpp"

#include <cstring>

namespace XNELO
{
	namespace TESTING
	{
		TEST_RESULT::TEST_RESULT() : passed(true), name(NULL)
		{
			return;
		}

		TEST_RESULT::TEST_RESULT(const TEST_RESULT & other) : passed(true), name(NULL)
		{
			deepCopy(other);
		}

		TEST_RESULT & TEST_RESULT::operator=(const TEST_RESULT & other)
		{
			if (this != &other)
			{
				deepCopy(other);
			}
			return *this;
		}

		TEST_RESULT::~TEST_RESULT()
		{
			if (name)
			{
				delete[] name;
				name = NULL;
			}
		}

		void TEST_RESULT::deepCopy(const TEST_RESULT & other)
		{
			passed = other.passed;
			name = NULL;
			if (other.name != NULL)
			{
				name = new char[strlen(other.name) + 1];
#if defined(_XNELO_TESTING_WINDOWS_)
				strcpy_s(name, strlen(other.name) + 1, other.name);
#else
				strcpy(name, other.name);
#endif
			}
		}
	}//end namespace TESTING
}//end namespace XNELO