/**
* Test.cpp
* @author Spencer Hoffa
*
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

#include "Test.hpp"

#include <iostream>
#include <cmath>
#include <cstring>

namespace XNELO
{
	namespace TESTING
	{

		void Test::Clear()
		{
			_success = true;

			for (int i = 0; i < (int)_results.size(); i++)
			{
				delete _results[i];
			}
			_results.clear();

			_passed = 0;
			_failed = 0;
		}

		int Test::GetFailed()
		{
			return _failed;
		}

		std::string Test::GetName()
		{
			return _testName;
		}

		int Test::GetPassed()
		{
			return _passed;
		}

		bool Test::GetSuccess()
		{
			return _success;
		}

		bool Test::UnitTest(bool condition, std::string &testName)
		{
			return UnitTest(condition, testName.c_str());
		}

		bool Test::UnitTest(double actual, double expected, double tolerance, std::string& testName)
		{
			return UnitTest(actual, expected, tolerance, testName.c_str());
		}

		bool Test::UnitTest(float actual, float expected, float tolerance, std::string& testName)
		{
			return UnitTest(actual, expected, tolerance, testName.c_str());
		}

		int Test::GetNumResults()
		{
			return (int)_results.size();
		}

		TEST_RESULT* Test::GetTestResult(int index)
		{
			if ((index > (int)_results.size()) || (index < 0))
				return NULL;

			return _results[index];
		}

		void Test::SetName(const char * name)
		{
			_testName = std::string(name);
		}

		void Test::SetName(std::string name)
		{
			_testName = name;
		}

		Test::Test() : _success(true), _results(), _immediateToCOUT(false),
			_printOnlyFailed(false), _passed(0), _failed(0), _testName("")
		{
			return;
		}

		Test::Test(std::string name) : _success(true), _results(), _immediateToCOUT(false),
			_printOnlyFailed(false), _passed(0), _failed(0), _testName(name)
		{
			return;
		}

		Test::Test(std::string name, bool PrintImmediatlyToCOUT, bool printOnlyFailed) :
			_success(true), _results(), _immediateToCOUT(PrintImmediatlyToCOUT),
			_printOnlyFailed(printOnlyFailed), _passed(0), _failed(0), _testName(name)
		{
			return;
		}

		Test::~Test()
		{
			for (unsigned int i = 0; i < _results.size(); i++)
			{
				delete _results[i];
			}
			_results.clear();
		}

		void Test::Analyze()
		{
			_passed = 0;
			_failed = 0;

			for (int i = 0; i < (int)_results.size(); i++)
			{
				if (_results[i]->passed)
					_passed++;
				else
					_failed++;
			}
		}

		bool Test::UnitTest(double actual, double expected, double tolerance, const char * testName)
		{
			return UnitTest(std::abs(actual - expected) < tolerance, testName);
		}

		bool Test::UnitTest(float actual, float expected, float tolerance, const char * testName)
		{
			return UnitTest(std::abs(actual - expected) < tolerance, testName);
		}

		bool Test::UnitTest(bool condition, const char * testName)
		{
			if (_immediateToCOUT)
			{
				if (_printOnlyFailed)
				{
					if (!condition)
						std::cout << testName << ": " << "[FAILED]" << std::endl;
				}
				else
				{
					std::cout << testName << ": " << (condition ? "[PASSED]" : "[FAILED]") << std::endl;
				}
			}

			if (!condition)
				_success = false;

			//create a test result
			TEST_RESULT* result = new TEST_RESULT();
			result->passed = condition;
			result->name = new char[strlen(testName) + 1];
			strcpy(result->name, testName);

			_results.push_back(result);

			return condition;
		}

	}//end namespace TEST
}//end namespace XNELO

