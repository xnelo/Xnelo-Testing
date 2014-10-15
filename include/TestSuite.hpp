/**
* TestSuite.hpp
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

#ifndef ___XNELO_TESTING_TestSuite_H__2014___
#define ___XNELO_TESTING_TestSuite_H__2014___

#include "TestingConfiguration.h"

#include "Test.hpp"
#include "IReportGenerator.hpp"

#include <vector>
#include <string>

namespace XNELO
{
	namespace TESTING
	{
		class TestSuite
		{
		private:
			std::vector<Test*> _tests;
			std::vector<bool(*)(Test*)> _testFunction;
			std::vector<Test*> _testFunctionTests;
			int _passed;
			int _failed;
			std::string _suiteName;
			IReportGenerator * _reportGenerator;
		public:
			XNELO_TESTING_API TestSuite();
			XNELO_TESTING_API TestSuite(const char * name);
			XNELO_TESTING_API TestSuite(std::string name);
			XNELO_TESTING_API ~TestSuite();

			XNELO_TESTING_API void AddTest(Test* test);
			XNELO_TESTING_API void AddTestFunction(bool(*func) (Test *));
			XNELO_TESTING_API void Analyze();

			XNELO_TESTING_API void ExecuteTests(bool PrintResults = true);

			XNELO_TESTING_API int GetFailed();
			XNELO_TESTING_API std::string GetName();
			XNELO_TESTING_API int GetTotalTests();
			XNELO_TESTING_API int GetPassed();
			XNELO_TESTING_API bool GetSuccess();
			XNELO_TESTING_API IReportGenerator * GetReportGenerator();

			XNELO_TESTING_API void PrintResults();

			XNELO_TESTING_API void SetName(std::string name);
			XNELO_TESTING_API void SetName(const char * name);
			XNELO_TESTING_API void SetReportGenerator(IReportGenerator * generator);
		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_TestSuite_H__2014___