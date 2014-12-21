/*
 * CallHandle_test.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include "CallHandle.h"
#include "Fresher.h"
#include "TechLead.h"
#include "ProductManager.h"
#include "Call.h"

namespace chapterSeven {

TEST(CallHandleTest, AddEmployee){
	CallHandle handle(3, 5, 1, 1);
	RankedCall firstCall(1);
	ASSERT_EQ("Fresher_1", handle.getCallHandler(firstCall)->getId());
}

TEST(CallHandleTest, AddEmployeeCanNotHandle){
	CallHandle handle(3, 5, 1, 1);
	RankedCall firstCall(4);
	ASSERT_EQ(nullptr, handle.getCallHandler(firstCall));
}

TEST(CallHandleTest, HandleLevelOne){
	CallHandle handle(3, 5, 1, 1);
	RankedCall firstCall(1);

	Employee *emp = handle.getCallHandler(firstCall);
	emp->handleCall(firstCall, handle);

	ASSERT_EQ("Fresher_1", firstCall.HandledBy);
}

TEST(CallHandleTest, HandleLevelTwo){
	CallHandle handle(3, 5, 1, 1);
	DispatchedToLevelTwoCall dispTwo;

	Employee *emp = handle.getCallHandler(dispTwo);
	emp->handleCall(dispTwo, handle);

	ASSERT_EQ("TechLead_1", dispTwo.HandledBy);
}

TEST(CallHandleTest, HandleLevelThree){
	CallHandle handle(3, 5, 1, 1);
	DispatchedToLevelThreeCall dispThree;

	Employee *emp = handle.getCallHandler(dispThree);
	emp->handleCall(dispThree, handle);

	ASSERT_EQ("ProductManager_1", dispThree.HandledBy);
}

TEST(CallHandleTest, NoPendingCalls){
	CallHandle handle(3, 5, 1, 1);
	DispatchedToLevelTwoCall dispTwo;

	Employee *emp = handle.getCallHandler(dispTwo);
	emp->handleCall(dispTwo, handle);

	ASSERT_EQ(0, handle.getNumOfPendingCalls());
}

} /* namespace chapterSeven */
