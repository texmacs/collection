/******************************************************************************
* MODULE     : fast_alloc_test.cpp
* DESCRIPTION: Test the time allocated for memory, the correctness 
*              of the returned result is not tested due to the type 
*			   of the return value.
* COPYRIGHT  : (C) 2019 Ze Wang
*******************************************************************************
* This software falls under the GNU general public license version 3 or later.
* It comes WITHOUT ANY WARRANTY WHATSOEVER. For details, see the file LICENSE
* in the root directory or <http://www.gnu.org/licenses/gpl-3.0.html>.
******************************************************************************/


#include "gtest/gtest.h"
#include "fast_alloc.hpp"
#include "tm_configure.hpp"

struct Complex { 
public: 
double re, im; 
Complex(double re_, double im_): re(re_), im(im_) {} 
~Complex() {} 
}; 

/******************************************************************************
* Tests on Common routines for memory. It mainly contains two functions 
* fast_new and new.
******************************************************************************/

TEST(fast_alloc,time_new=fast_new+new_){
	EXPECT_TRUE(tm_new<char>());
	EXPECT_TRUE(tm_new<char>('a'));
	EXPECT_TRUE(tm_new<Complex>(35.8, 26.2));
	EXPECT_TRUE(tm_new<int>(1));
	EXPECT_TRUE(tm_new<short int>(1));
	EXPECT_TRUE(tm_new<long int>(1));
}

/******************************************************************************
* Tests on Common routines for functions fast_new.
******************************************************************************/

TEST(fast_alloc,fast_new){
	EXPECT_TRUE(fast_new(sizeof(int)));
	EXPECT_TRUE(fast_new(sizeof(double)));
	EXPECT_TRUE(fast_new(sizeof(char)));
	EXPECT_TRUE(fast_new(sizeof(Complex)));
	EXPECT_TRUE(fast_new(sizeof(short int)));
	EXPECT_TRUE(fast_new(sizeof(long int)));
}


