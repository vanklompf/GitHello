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

			Assert::AreEqual(6ull, byteAccumulate_HandCraftedDoWhilePtr(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedDoWhilePtr_singleValue)
		{
			uint8_t test_array[] = { 101};

			Assert::AreEqual(101ull, byteAccumulate_HandCraftedDoWhilePtr(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedForArray)
		{
			uint8_t test_array[] = { 1, 2, 3 };

			Assert::AreEqual(6ull, byteAccumulate_HandCraftedForArray(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_HandCraftedForArray_singleValue)
		{
			uint8_t test_array[] = { 101 };

			Assert::AreEqual(101ull, byteAccumulate_HandCraftedForArray(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_StlPlainArary)
		{
			uint8_t test_array[] = { 1, 2, 3 };

			Assert::AreEqual(6ull, byteAccumulate_StlPlainArary(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_StlPlainArary_singleValue)
		{
			uint8_t test_array[] = { 101 };

			Assert::AreEqual(101ull, byteAccumulate_StlPlainArary(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_StlVector)
		{
			std::vector<uint8_t> test_vector = { 1, 2, 3};

			Assert::AreEqual(6ull, byteAccumulate_StlVector(test_vector));
		}

		TEST_METHOD(TestByteAccumulate_StlVector_singleValue)
		{
			std::vector<uint8_t> test_vector = { 101};

			Assert::AreEqual(101ull, byteAccumulate_StlVector(test_vector));
		}

		TEST_METHOD(TestByteAccumulate_Unrolled)
		{
			uint8_t test_array[] = { 1, 2, 3 };

			Assert::AreEqual(6ull, byteAccumulate_Unrolled(test_array, 3));
		}

		TEST_METHOD(TestByteAccumulate_Unrolled_singleValue)
		{
			uint8_t test_array[] = { 101 };

			Assert::AreEqual(101ull, byteAccumulate_Unrolled(test_array, 1));
		}

		TEST_METHOD(TestByteAccumulate_Unrolled_endUnaligned)
		{
			uint8_t test_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

			Assert::AreEqual(91ull, byteAccumulate_Unrolled(test_array, 13));
		}
	};
}