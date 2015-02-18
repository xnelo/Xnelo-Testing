/*
* The zlib / libpng License
*
* Copyright(c) 2014 Spencer Hoffa
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from the
* use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
*including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions :
*
*		1. The origin of this software must not be misrepresented; you must not
*		claim that you wrote the original software.If you use this software in
*		a product, an acknowledgment in the product documentation would be
*		appreciated but is not required.
*
*		2. Altered source versions must be plainly marked as such, and must not
*		be misrepresented as being the original software.
*
*		3. This notice may not be removed or altered from any source
*		distribution.
*
* This liscense can also be found at : http://opensource.org/licenses/Zlib
*/

#include <iostream>

#include "../include/Testing.hpp"

bool testfunction(XNELO::TESTING::Test * test)
{
	test->SetName("Static Testing Function");

	test->UnitTest(true, "Test1Passed");
	test->UnitTest(1.0 == 1.0, "Test2Passed");
	test->UnitTest(3 > 2, "Test3Passed");

	return test->GetSuccess();
}

bool testfunction2(XNELO::TESTING::Test * test)
{ 
	test->SetName("Static Testing Function 2");

	test->UnitTest(true, "Test1Passed");
	test->UnitTest(true, "Test2Passed");

	return test->GetSuccess();
}

int main(int argc, char * argv[])
{
	//create the tests
	XNELO::TESTING::TestSuite ts;
	ts.SetName("Test Suite Example");

	XNELO::TESTING::Test t;
	t.SetName("Test");
	t.UnitTest(true, "Test1Passed");
	t.UnitTest(false, "Test2Failed");

	t.UnitTest(10.0, 10.0, 0.0001, "Test Tolerance Double");
	t.UnitTest(10.0f, 10.0f, 0.0001f, "Test Tolerance float");
	t.UnitTest(10.0f, 10.000001f, 0.0001f, "Test Tolerance float");
	t.UnitTest(-10.0f, -9.99999999f, 0.0001f, "Test Tolerance float");
	t.UnitTest(10.0f, 9.99999999f, 0.0001f, "Test Tolerance float");

	ts.AddTest(&t);

	XNELO::TESTING::TestSuite ts2;
	ts2.SetName("Test Suite Example 2");
	ts2.AddTestFunction(&testfunction);
	ts2.AddTestFunction(&testfunction2);

	ts.AddTestSuite(&ts2);

	//create the report generator
	XNELO::TESTING::OutStreamGenerator tmp;

	//set the stream... this could be a file
	//but here we use cout
	tmp.SetOutputStream(&std::cout);
	//set the test suite's report generator
	ts.SetReportGenerator(&tmp);

	ts.ExecuteTests();

	return 0;
}