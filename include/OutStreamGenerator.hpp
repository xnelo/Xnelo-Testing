/**
* @file OutStreamGenerator.hpp
* @author Spencer Hoffa
*
* @copyright 2014 Spencer Hoffa
*
* A basic Report Generator that outputs the report information as a basic 
* string. This class inherits from XNELO::TESTING::IReportGenerator.
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

#ifndef ___XNELO_TESTING_OutStreamGenerator_H__2014___
#define ___XNELO_TESTING_OutStreamGenerator_H__2014___

#include "TestingConfiguration.h"

#include "IReportGenerator.hpp"

namespace XNELO
{
	namespace TESTING
	{
		/**
		* A basic implementation of IReportGenerator that outputs the report as 
		* basic text.
		*/
		class OutStreamGenerator : public IReportGenerator
		{
		public:
			/**
			* Default Constructor
			*/
			XNELO_TESTING_API OutStreamGenerator();

			/**
			* Constructor
			*
			* @param stream A pointer to the stream that we output to.
			*/
			XNELO_TESTING_API OutStreamGenerator(std::ostream * stream);

			/**
			* Destructor
			*/
			XNELO_TESTING_API virtual ~OutStreamGenerator();

			/**
			* End the Test we are currently printing.
			*/
			XNELO_TESTING_API virtual void EndTest();

			/**
			* End the current test suite that we are printing/working on.
			*/
			XNELO_TESTING_API virtual void EndTestSuite();

			/**
			* Print the report title.
			*
			* @param title A C-string representation of the title.
			*/
			XNELO_TESTING_API virtual void PrintReportTitle(const char * title);

			/**
			* Print the statistics of the suite.
			*
			* @param suite A pointer to a TestSuite object that we will get the
			*			statistics from.
			*/
			XNELO_TESTING_API virtual void PrintSuiteStatistics(TestSuite * suite);

			/**
			* Print the result of the test.
			*
			* @param result A pointer to a TEST_RESULT object that contains the test
			*			name and the result of the test.
			*/
			XNELO_TESTING_API virtual void PrintTestResult(TEST_RESULT * result);

			/**
			* Print the statistics of the passed in test.
			*
			* @param test A pointer to a Test where we will print the statistics from.
			*/
			XNELO_TESTING_API virtual void PrintTestStatistics(Test * test);

			/**
			* Start printing a test.
			*
			* @param testName A C-String that contains the title of the test.
			*/
			XNELO_TESTING_API virtual void StartTest(const char * testName);

			/**
			* Start Printing a test suite.
			*
			* @param suiteTitle A C-string representation of the suite title we are starting.
			*/
			XNELO_TESTING_API virtual void StartTestSuite(const char * suiteTitle);
		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_OutStreamGenerator_H__2014___