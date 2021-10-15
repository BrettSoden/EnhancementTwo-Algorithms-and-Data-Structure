// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
#include "gtest/gtest.h"

//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0

    add_entries(1);

    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeIsGreater)
{
    //the maz size is greater than the below entries
    EXPECT_TRUE(collection->max_size() > 0);

    EXPECT_TRUE(collection->max_size() > 1);

    EXPECT_TRUE(collection->max_size() > 5);

    EXPECT_TRUE(collection->max_size() > 10);
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, GreaterThanOrEqualToo)
{
    //the collection is greater than or equal to 0, 1 5, and 10
    EXPECT_TRUE(collection->size() >= 0, 1, 5, 10);
}


// TODO: Create a test to verify resizing increases the collection

TEST_F(CollectionTest, VerifyIncreaseSize)
{
    // the collection is resized to a number greater than its previous size
    collection->resize(101);
    // the collection size is greater than 100 
    ASSERT_TRUE(collection->size() > 100);
}

// TODO: Create a test to verify resizing decreases the collection

TEST_F(CollectionTest, VerifyDecreaseSize)
{
    // collection resized to fifty
    collection->resize(50);
    // the collection size is less than 51
    ASSERT_TRUE(collection->size() < 51);

}

// TODO: Create a test to verify resizing decreases the collection to zero

TEST_F(CollectionTest, VerifyDecreaseSizeZero)
{
    // resizeing the size to zero results in an emtpy size
    collection->resize(0);

    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection

TEST_F(CollectionTest, ClearEraseCollection)
{
    collection->clear();
    // The collection is erazed by clear and now the size is zerp
    ASSERT_EQ(collection->size(), 0);

}

// TODO: Create a test to verify erase(begin,end) erases the collection

TEST_F(CollectionTest, EraseBeginEnd)
{
    erase(begin, end);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection

TEST_F(CollectionTest, ReserveIncreaseCapacity)
{
    //The collections reserve is pushed to over 100
    collection->push_back(rand() % 101);
    //The collections size does not equal 101 despite the increase in capacity
    ASSERT_NE(collection->size(), 101);

}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test

TEST_F(CollectionTest, OutOfRangeException)
{

    ASSERT_FALSE(collection->at(101)) << "Collection is out of range.";
}


// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

//Assert that size does not go above 100 entries.
TEST_F(CollectionTest, GreaterThanOrEqualToo100)
{
    //collection size is not greater than or equal to 100 while max size is
    EXPECT_TRUE(collection->size() >= 100);
    //collection's max size is greater than its default size
    EXPECT_FALSE(collection->max_size() >= 100);

}

//Add a large amount of entries and assert that they can be resized to a lower number
TEST_F(CollectionTest, AddTooManyAndResize)
{
    // if empty, the size must be 0
    add_entries(1000);
    //collection resized to 99
    collection->resize(99);
    //assert that the colelction size is now equal to 99
    ASSERT_EQ(collection->size(), 99);

}

Test_F(CollectionTest, OutOfRangeResize)
{
    //add 1000 entries
    add_entries(1000);
    //collectio resized to 100 entries
    collection->resize(100);
    //10 entries added on top of resize
    add_entries(10);
    //assert too large
    ASSERT_FALSE(collection->at(111)) << "Collection is too large.";
}
Test_F(CollectionTest, VerifyCollectionIsZero)
{
    //collection is tested for 0
    collection->resize(0);
    //Assert not equal followed cout prompt
    ASSERT_FALSE(collection->size()->at(1)); << "Collection is empty.";
    //collection is not smaller than zero entries
    EXPECT_FALSE(collection->size() < 0);
    //collection is not larger than zero entries
    EXPECT_FALSE(collection->size() > 0);
    //collection is exactly zero entries
    EXPECT_TRUE(collection->size() == 0);
}
TEST_F(CollectionTest, ReserveDecreaseCapacity)
{
    //collection reserve decreased to 90
    collection->push_back(rand() % 90);
    //collection reserve is too small
    ASSERT_FALSE(collection->at(95)) << "Collection size too large.";

}
Test_F(CollectionTest, VerifyTrueSizeWithFalseSize)
{
    //collection tested for what its not
    collection->resize(101);
    //collection is not greater than 101
    EXPECT_FALSE(collection->size > 101);
    //collection is not greater than or equal to 102
    EXPECT_FALSE(collection->size >= 102);
    //collection is not less than or equal to 100
    ASSERT_FALSE(collection->size <=100)
    //collection is not equal to 102
    ASSERT_NE(collection->size, 102);
    
}
