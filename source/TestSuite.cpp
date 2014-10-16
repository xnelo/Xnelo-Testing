/**
* TestSuite.cpp
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

#include "TestSuite.hpp"

namespace XNELO
{
	namespace TESTING
	{
		void TestSuite::AddTest(Test *test)
		{
			_tests.push_back(test);
		}

		void TestSuite::AddTestSuite(TestSuite* suite)
		{
			_testSuites.push_back(suite);
		}

		void TestSuite::AddTestFunction(bool(*func) (Test*))
		{
			_testFunction.push_back(func);
		}

		int TestSuite::GetFailed()
		{
			return _failed;
		}

		std::string TestSuite::GetName()
		{
			return _suiteName;
		}

		int TestSuite::GetTotalTests()
		{
			return (int)_tests.size() + (int)_testFunctionTests.size();
		}

		int TestSuite::GetPassed()
		{
			return _passed;
		}

		IReportGenerator * TestSuite::GetReportGenerator()
		{
			return _reportGenerator;
		}

		void TestSuite::SetName(std::string name)
		{
			_suiteName = name;
		}

		void TestSuite::SetName(const char * name)
		{
			_suiteName = std::string(name);
		}

		void TestSuite::SetReportGenerator(IReportGenerator * generator)
		{
			_reportGenerator = generator;
		}

		bool TestSuite::GetSuccess()
		{
			return (GetPassed() == GetTotalTests());
		}

		TestSuite::TestSuite() : _tests(), _passed(0), _failed(0), _suiteName(""), _reportGenerator(NULL)
		{
			return;
		}

		TestSuite::TestSuite(std::string name) : _tests(), _passed(0), _failed(0), _suiteName(name), _reportGenerator(NULL)
		{
			return;
		}

		TestSuite::TestSuite(const char * name) : _tests(), _passed(0), _failed(0), _suiteName(name), _reportGenerator(NULL)
		{
			return;
		}

		TestSuite::~TestSuite()
		{
			/*
			for (int i = 0; i < (int)_tests.size(); i++)
			{
			delete _tests[i];
			}
			*/
			_tests.clear();
			_testSuites.clear();

			for (int i = 0; i < (int)_testFunctionTests.size(); i++)
			{
				delete _testFunctionTests[i];
			}
			_testFunctionTests.clear();
			_testFunction.clear();
		}

		void TestSuite::Analyze()
		{
			_passed = 0;
			_failed = 0;

			for (int i = 0; i < (int)_tests.size(); i++)
			{
				_tests[i]->Analyze();

				if (_tests[i]->GetSuccess())
					_passed++;
				else
					_failed++;
			}

			for (int i = 0; i < (int)_testFunctionTests.size(); i++)
			{
				_testFunctionTests[i]->Analyze();

				if (_testFunctionTests[i]->GetSuccess())
					_passed++;
				else
					_failed++;
			}

			for (int i = 0; i < (int)_testSuites.size(); i++)
			{
				_testSuites[i]->Analyze();

				if (_testSuites[i]->GetSuccess())
					_passed++;
				else
					_failed++;
			}
		}

		void TestSuite::ExecuteTests(bool PrintResults)
		{
			for (unsigned int i = 0; i < _testFunction.size(); i++)
			{
				bool(*fun)(Test*) = _testFunction[i];

				Test * test = new Test();

				fun(test);

				_testFunctionTests.push_back(test);

				test->Analyze();
			}

			for (unsigned int i = 0; i < _testSuites.size(); i++)
			{
				_testSuites[i]->ExecuteTests(false);

				_testSuites[i]->Analyze();
			}

			Analyze();

			if (PrintResults)
				this->PrintResults();
		}

		void TestSuite::PrintResults(bool printTitle)
		{
			if (!_reportGenerator)
				return;

			if (printTitle)
				_reportGenerator->PrintReportTitle("Report Printing...");

			_reportGenerator->StartTestSuite(_suiteName.c_str());

			//Each test ---------
			for (unsigned int i = 0; i < _tests.size(); i++)
			{
				Test * test = _tests[i];

				_reportGenerator->StartTest(test->GetName().c_str());

				for (int j = 0; j < test->GetNumResults(); j++)
				{
					_reportGenerator->PrintTestResult(test->GetTestResult(j));
				}

				_reportGenerator->PrintTestStatistics(test);

				_reportGenerator->EndTest();
			}

			for (unsigned int i = 0; i < _testFunctionTests.size(); i++)
			{
				Test * test = _testFunctionTests[i];

				_reportGenerator->StartTest(test->GetName().c_str());

				for (int j = 0; j < test->GetNumResults(); j++)
				{
					_reportGenerator->PrintTestResult(test->GetTestResult(j));
				}

				_reportGenerator->PrintTestStatistics(test);

				_reportGenerator->EndTest();
			}
			//-------------------

			//Each Test Suite ---
			for (unsigned int i = 0; i < _testSuites.size(); i++)
			{
				_testSuites[i]->SetReportGenerator(_reportGenerator);
				_testSuites[i]->PrintResults(false);
			}
			//-------------------

			_reportGenerator->PrintSuiteStatistics(this);
			_reportGenerator->EndTestSuite();
		}
	}//end namespace TESTING
}//end namespace XNELO

