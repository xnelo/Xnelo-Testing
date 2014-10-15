/**
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

int main(int argc, char * argv[])
{
	
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

	XNELO::TESTING::OutStreamGenerator tmp;

	tmp.SetOuputStream(&std::cout);
	ts.SetReportGenerator(&tmp);

	ts.ExecuteTests();

	return 0;
}