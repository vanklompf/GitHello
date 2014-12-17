#include "stdafx.h"
#include "CppUnitTest.h"
#include "byte_accumulate.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(byteAccumulateTests)
	{
	public:
		
		TEST_METHOD(TestByteAccumulate_HandCraftedDoWhilePtr)
		{
			uint8_t test_array[] = { 1, 2, 3};

			Assert::AreEqual(6u, byteAccumulate_HandCraftedDoWhilePtr(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedDoWhilePtr_singleValue)
		{
			uint8_t test_array[] = { 101};

			Assert::AreEqual(101u, byteAccumulate_HandCraftedDoWhilePtr(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedForArray)
		{
			uint8_t test_array[] = { 1, 2, 3 };

			Assert::AreEqual(6u, byteAccumulate_HandCraftedForArray(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedForArray_singleValue)
		{
			uint8_t test_array[] = { 101 };

			Assert::AreEqual(101u, byteAccumulate_HandCraftedForArray(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_StlPlainArary)
		{
			uint8_t test_array[] = { 1, 2, 3 };

			Assert::AreEqual(6u, byteAccumulate_StlPlainArary(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_StlPlainArary_singleValue)
		{
			uint8_t test_array[] = { 101 };

			Assert::AreEqual(101u, byteAccumulate_StlPlainArary(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_StlVector)
		{
			std::vector<uint8_t> test_vector = { 1, 2, 3};

			Assert::AreEqual(6u, byteAccumulate_StlVector(test_vector));
		}

		TEST_METHOD(TestByteAccumulate_StlVector_singleValue)
		{
			std::vector<uint8_t> test_vector = { 101};

			Assert::AreEqual(101u, byteAccumulate_StlVector(test_vector));
		}
	};
}