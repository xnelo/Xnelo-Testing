/**
* IReportGenerator.hpp
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

#ifndef ___XNELO_TESTING_IReportGenerator_H__2014___
#define ___XNELO_TESTING_IReportGenerator_H__2014___

#include "TestingConfiguration.h"

#include "Test_Result.hpp"
#include "Test.hpp"

#include <ostream>

namespace XNELO
{
	namespace TESTING
	{
		//predefine TestSuite
		class TestSuite;

		/**
		* Creates an Interface for all Report Generators.
		*/
		class IReportGenerator
		{
		protected:
			std::ostream * _stream;
		public:
			/**
			* Default Constructor
			*/
			XNELO_TESTING_API IReportGenerator();
			/**
			* Constructor.
			*
			* @param stream A pointer to an std::ostream object where the output of 
			*			this report generator will go.
			*/
			XNELO_TESTING_API IReportGenerator(std::ostream * stream);
			/**
			* Destructor.
			*/
			XNELO_TESTING_API virtual ~IReportGenerator();
			/**
			* Set the Output stream for this report generator.
			*/
			XNELO_TESTING_API virtual void SetOutputStream(std::ostream* stream);

			/**
			* Print the report title.
			*
			* @param title A C-string representation of the title.
			*/
			XNELO_TESTING_API virtual void PrintReportTitle(const char * title) = 0;
			XNELO_TESTING_API virtual void StartTestSuite(const char * suiteTitle) = 0;
			XNELO_TESTING_API virtual void EndTestSuite() = 0;
			XNELO_TESTING_API virtual void PrintSuiteStatistics(TestSuite * suite) = 0;

			XNELO_TESTING_API virtual void StartTest(const char * testName) = 0;
			XNELO_TESTING_API virtual void EndTest() = 0;
			XNELO_TESTING_API virtual void PrintTestResult(TEST_RESULT * result) = 0;
			XNELO_TESTING_API virtual void PrintTestStatistics(Test * test) = 0;
		};

		inline IReportGenerator::IReportGenerator() : _stream(NULL)
		{
			return;
		}

		inline IReportGenerator::IReportGenerator(std::ostream * stream) : _stream(stream)
		{
			return;
		}

		inline IReportGenerator::~IReportGenerator()
		{
			_stream = NULL;
		}

		inline void IReportGenerator::SetOutputStream(std::ostream* stream)
		{
			_stream = stream;
		}
	}//end namespace TESTING
}//end namespace XNELO

#endif //___XNELO_TESTING_IReportGenerator_H__2014___