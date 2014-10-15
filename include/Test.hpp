/**
* Test.hpp
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

#ifndef ___XNELO_TESTING_Test_H__2014___
#define ___XNELO_TESTING_Test_H__2014___

#include "TestingConfiguration.h"

#include "Test_Result.hpp"

#include <vector>
#include <string>

namespace XNELO
{
	namespace TESTING
	{
		class Test
		{
		private:
			bool _success;
			std::vector<TEST_RESULT*> _results;
			bool _immediateToCOUT;
			bool _printOnlyFailed;

			int _passed;
			int _failed;

			std::string _testName;

		public:
			XNELO_TESTING_API Test();
			XNELO_TESTING_API Test(std::string name);
			XNELO_TESTING_API Test(std::string name, bool PrintImmediatlyToCOUT, bool printOnlyFailed);
			XNELO_TESTING_API ~Test();

			XNELO_TESTING_API void Analyze();

			XNELO_TESTING_API void Clear();

			XNELO_TESTING_API bool UnitTest(bool condition, std::string& testName);
			XNELO_TESTING_API bool UnitTest(bool condition, const char *testName);
			XNELO_TESTING_API bool UnitTest(double actual, double expected, double tolerance, const char *testName);
			XNELO_TESTING_API bool UnitTest(double actual, double expected, double tolerance, std::string& testName);
			XNELO_TESTING_API bool UnitTest(float actual, float expected, float tolerance, const char *testName);
			XNELO_TESTING_API bool UnitTest(float actual, float expected, float tolerance, std::string& testName);

			XNELO_TESTING_API int GetFailed();
			XNELO_TESTING_API std::string GetName();
			XNELO_TESTING_API int GetPassed();
			XNELO_TESTING_API bool GetSuccess();
			XNELO_TESTING_API int GetNumResults();
			XNELO_TESTING_API TEST_RESULT* GetTestResult(int index);

			XNELO_TESTING_API void SetName(const char * name);
			XNELO_TESTING_API void SetName(std::string name);
		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_Test_H__2014___