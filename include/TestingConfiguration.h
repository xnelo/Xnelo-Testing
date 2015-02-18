/**
* @file TestingConfiguration.h
* @author Spencer Hoffa
*
* @copyright 2014 Spencer Hoffa
*
* This contains all of the configurations definitions to compile the Xnelo 
* Testing library. This library defaults to build as a shared library (.dll on
* windows and .so on linux). To compile as a static library you must define 
* _XNELO_TESTING_STATIC_LIB_ either as a preprocessor directive while compiling
* or as a #define before including Test.hpp.
*/
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
* including commercial applications, and to alter it and redistribute it
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

#ifndef ___XNELO_TESTINGCONFIGURATION_H__2014___
#define ___XNELO_TESTINGCONFIGURATION_H__2014___

//ONLY UNCOMMENT THIS LINE IF YOU ARE INCLUDING 
//THE LIBRARY DIRECTLY INTO YOUR PROJECT
//#define _XNELO_TESTING_STATIC_LIB_ 1 

// WIN32 for Windows32
// WIN64 for Windows64
// The windows platform and API support SDL and WINDOW device
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
#define _XNELO_TESTING_WINDOWS_
#define _XNELO_TESTING_WINDOWS_API_
#endif

#ifdef _XNELO_TESTING_WINDOWS_API_

// To build Xnelo Testing as a static library, you must define _XNELO_TESTING_STATIC_LIB_ 
// in both the Xnelo Testing library, *and* in the user application, before 
// #including <irrlicht.h>
#ifndef _XNELO_TESTING_STATIC_LIB_
#ifdef XNELO_TESTING_EXPORTS
#define XNELO_TESTING_API __declspec(dllexport)
#else
#define XNELO_TESTING_API __declspec(dllimport)
#endif // XNELO_TESTING_EXPORTS
#else//building static library
#define XNELO_TESTING_API
#endif // _XNELO_TESTING_STATIC_LIB_
#else // _XNELO_TESTING_WINDOWS_API_
//linux stuff
#define XNELO_TESTING_API 
#endif //_XNELO_TESTING_WINDOWS_API_

#endif //___XNELO_TESTINGCONFIGURATION_H__2014___