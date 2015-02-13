/**
* @file Test.hpp
* @author Spencer Hoffa
*
* @copyright 2014 Spencer Hoffa
*
* A class that handles all of the testing. This class will keep track of each 
* individual tests and whether they wer a success or failure.
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
		/**
		* A class that executes unit test and keeps track of their results.
		*/
		class Test
		{
		private:
			/**Have all the tests been successful.*/
			bool _success;
			/**All the results of the unit tests.*/
			std::vector<TEST_RESULT*> _results;
			/**Whether or not to print results immediatly.*/
			bool _immediateToCOUT;
			/**Output only failed tests.*/
			bool _printOnlyFailed;

			/**Number of tests that passed.*/
			int _passed;
			/**Number of tests that failed.*/
			int _failed;

			/**The name of this test.*/
			std::string _testName;

		public:
			/**
			* Default constructor.
			*/
			XNELO_TESTING_API Test();

			/**
			* Constructor
			*
			* @param name The name of this Test.
			*/
			XNELO_TESTING_API Test(std::string name);

			/**
			* Constructor
			*
			* @param name The name of this Test.
			* @param PrintImmediatlyToCOUT Print the results immediatly to standard output stream.
			* @param printOnlyFailed Print results only if the test failed.
			*/
			XNELO_TESTING_API Test(std::string name, bool PrintImmediatlyToCOUT, bool printOnlyFailed);

			/**
			* Destructor
			*/
			XNELO_TESTING_API ~Test();

			/**
			* Analyze all the tests and create the statistics.
			*/
			XNELO_TESTING_API void Analyze();

			/**
			* Clear all the statistics.
			*/
			XNELO_TESTING_API void Clear();

			/**
			* Get the number of failed tests.
			*
			* @return Returns an integer of the number of Failed tests.
			*/
			XNELO_TESTING_API int GetFailed();

			/**
			* Get the name of this test.
			*
			* @return Returns a string with the name of this test.
			*/
			XNELO_TESTING_API std::string GetName();

			/**
			* Get the number of tests run.
			*
			* @return Returns an integer representing the number of tests run.
			*/
			XNELO_TESTING_API int GetNumResults();

			/**
			* Get the number of passed tests.
			*
			* @return Returns an integer of the number of Passed tests.
			*/
			XNELO_TESTING_API int GetPassed();

			/**
			* Get if all the tests were successful.
			*
			* @return Returns a bool. If all the tests passed then true is
			*			returned and false if even one of the tests failed.
			*/
			XNELO_TESTING_API bool GetSuccess();

			/**
			* Get a specific test result. The index must be between 0 and the
			* value of 'GetNumResults'.
			*
			* @param index The index of the result needed.
			*
			* @return Returns a pointer to a 'TEST_RESULT' object.
			*/
			XNELO_TESTING_API TEST_RESULT* GetTestResult(int index);

			/**
			* Set the name of this test.
			*
			* @param name A C-String with the name of this test.
			*/
			XNELO_TESTING_API void SetName(const char * name);

			/**
			* Set the name of this test
			*
			* @param name a string with the name of this test.
			*/
			XNELO_TESTING_API void SetName(std::string name);

			/**
			* Unit test. Tests if the condition is true and records the results.
			*
			* @param condition A boolean test that executes out to true or false.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(bool condition, std::string& testName);

			/**
			* Unit test. Tests if the condition is true and records the results.
			*
			* @param condition A boolean test that executes out to true or false.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(bool condition, const char *testName);

			/**
			* Unit test. Tests if the actual decimal value is within the tolerance of the expected value.
			*
			* @param actual The actual value of the test.
			* @param expected The expected value of the test.
			* @param tolerance The tolerance the test needs to be within.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(double actual, double expected, double tolerance, const char *testName);

			/**
			* Unit test. Tests if the actual decimal value is within the tolerance of the expected value.
			*
			* @param actual The actual value of the test.
			* @param expected The expected value of the test.
			* @param tolerance The tolerance the test needs to be within.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(double actual, double expected, double tolerance, std::string& testName);

			/**
			* Unit test. Tests if the actual decimal value is within the tolerance of the expected value.
			*
			* @param actual The actual value of the test.
			* @param expected The expected value of the test.
			* @param tolerance The tolerance the test needs to be within.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(float actual, float expected, float tolerance, const char *testName);

			/**
			* Unit test. Tests if the actual decimal value is within the tolerance of the expected value.
			*
			* @param actual The actual value of the test.
			* @param expected The expected value of the test.
			* @param tolerance The tolerance the test needs to be within.
			* @param testName The name of this unit test.
			*
			* @return Returns true if the test passed.
			*/
			XNELO_TESTING_API bool UnitTest(float actual, float expected, float tolerance, std::string& testName);

		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_Test_H__2014___