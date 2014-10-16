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
		/**
		* A test that holds all the tests needed to be run by a 
		* unit test. This can also include other tests suites.
		* Think of this as a hierarchy with the 'Test' class 
		* being the leaf nodes.
		*/
		class TestSuite
		{
		private:
			/**Tests that are added to this suite. These are not deleted by this library.*/
			std::vector<Test*> _tests;
			/**TestSuite s that are added to this suit. These are not deleted by this libraray.*/
			std::vector<TestSuite*> _testSuites;
			/**Single functions that contain tests.*/
			std::vector<bool(*)(Test*)> _testFunction;
			/**Test objects that are created internally to run tests on the passed in test functions.*/
			std::vector<Test*> _testFunctionTests;
			/**Number of tests that passed.*/
			int _passed;
			/**Number of tests that failed.*/
			int _failed;
			/**Name of this test suite.*/
			std::string _suiteName;
			/**The report generator that is used to print the tests.*/
			IReportGenerator * _reportGenerator;
		public:
			/**
			* Default constructor
			*/
			XNELO_TESTING_API TestSuite();
			/**
			* Constructor
			*
			* @param name the name of this test suite.
			*/
			XNELO_TESTING_API TestSuite(const char * name);
			XNELO_TESTING_API TestSuite(std::string name);
			/**
			* Destructor
			*/
			XNELO_TESTING_API ~TestSuite();

			/**
			* Add a test class to this suite. The passed in object will not be
			* deleted by this library.
			*
			* @param test A pointer to a 'Test' class to include in this suite.
			*/
			XNELO_TESTING_API void AddTest(Test* test);
			/**
			* Add a testsuite class to this suite. The passed in object will not be
			* deleted by this library.
			*
			* @param suite A pointer to a 'TestSuite' class to include in this suite.
			*/
			XNELO_TESTING_API void AddTestSuite(TestSuite* suite);
			/**
			* Add a static function to the suite.
			*
			* @param func A pointer to a function that takes a 'Test' class pointer and a bool as the return value.
			*/
			XNELO_TESTING_API void AddTestFunction(bool(*func) (Test *));
			/**
			* Analyze this Suite and compile all the statistics.
			*/
			XNELO_TESTING_API void Analyze();

			/**
			* Execute all the tests, test functions, and other tests suites.
			*
			* @param PrintResults After the tests have been executed do we print the results. Default value is true.
			*/
			XNELO_TESTING_API void ExecuteTests(bool PrintResults = true);

			/**
			* Get the number of failed tests.
			*
			* @return Return an integer with the number of failed tests.
			*/
			XNELO_TESTING_API int GetFailed();
			/**
			* Get the name of this test suite.
			*
			* @return Return a string with this suites name.
			*/
			XNELO_TESTING_API std::string GetName();
			/**
			* Get the total number of tests.
			*
			* @return Returns an integer with the total number of tests run by this suite.
			*/
			XNELO_TESTING_API int GetTotalTests();
			/**
			* Get the number of passed tests.
			*
			* @return Returns an integer with the number of tests that passed.
			*/
			XNELO_TESTING_API int GetPassed();
			/**
			* Returns true if all the tests passed.
			*
			* @param Returns true if all the tests passed. False if even one test fails.
			*/
			XNELO_TESTING_API bool GetSuccess();
			/**
			* Get the Report generator used to print the results.
			*
			* @return Returns a pointer to the current instance of 'IReportGenerator' assigned to this suite.
			*/
			XNELO_TESTING_API IReportGenerator * GetReportGenerator();

			/**
			* Print the results of this suite's test executions.
			*
			* @param printTitle Do you want the title to be printed.
			*/
			XNELO_TESTING_API void PrintResults(bool printTitle = true);

			/**
			* Set the name of this TestSuite.
			*
			* @param name Name of the Test suite.
			*/
			XNELO_TESTING_API void SetName(std::string name);
			XNELO_TESTING_API void SetName(const char * name);
			/**
			* Set the generator that will print the reports for this suite.
			*/
			XNELO_TESTING_API void SetReportGenerator(IReportGenerator * generator);
		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_TestSuite_H__2014___