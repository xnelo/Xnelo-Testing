/**
* OutStreamGenerator.hpp
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

#ifndef ___XNELO_TESTING_OutStreamGenerator_H__2014___
#define ___XNELO_TESTING_OutStreamGenerator_H__2014___

#include "TestingConfiguration.h"

#include "IReportGenerator.hpp"

namespace XNELO
{
	namespace TESTING
	{
		/**
		* An implementation of IReportGenerator.
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
			* Overidden function
			*/
			XNELO_TESTING_API virtual void PrintReportTitle(const char * title);
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void StartTestSuite(const char * suiteTitle);
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void EndTestSuite();
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void PrintSuiteStatistics(TestSuite * suite);

			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void StartTest(const char * testName);
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void EndTest();
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void PrintTestResult(TEST_RESULT * result);
			/**
			* Overidden function
			*/
			XNELO_TESTING_API virtual void PrintTestStatistics(Test * test);
		};
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_OutStreamGenerator_H__2014___