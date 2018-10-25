/*
 * DependenceUT.cpp
 *
 *  Created on: 2011-10-1
 *      Author: bourneli
 */

#include "gtest.h"
#include "gmock.h"
#include "Dependence_mock.h"
#include "Base.h"

using ::testing::AtLeast;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;
using ::testing::Return;
using ::testing::_;

TEST(OtherTestSuite, MatchesRegexDemo)
{
    EXPECT_THAT("123456799", MatchesRegex("[1-9]*"));  // 被测字符串重头到尾都要符合Regex
    EXPECT_THAT("123456799abcdes", ContainsRegex("[1-9]*")); // 被测试字符串只需要部分符合Regex
}

TEST(DependenceTestSuite, MockShowCase)
{
    DependenceMock oMock;
    EXPECT_CALL(oMock, show())
        .Times(AtLeast(1));

    Foo oFoo;
    oFoo.call(oMock);
}

TEST(DependenceTestSuite, MockShowSomethingCase)
{
    DependenceMock oMock;
    EXPECT_CALL(oMock, show(MatchesRegex(".*error.*"))).Times(AtLeast(1));

    Foo oFoo;
    oFoo.showSomething(oMock, "error happened in log");
}

TEST(DependenceTestSuite, AddSomethingToStringMockCase)
{
    DependenceMock oMock;
    EXPECT_CALL(oMock, addSomethingToString(_))
           .Times(0);

    Foo oFoo;
    oFoo.showAddSomething(oMock, "not yes");
}
