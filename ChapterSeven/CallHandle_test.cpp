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
	CallHandle handle;
	Fresher fresher("one");
	RankedCall firstCall(1);
	handle.addEmployee(fresher);
	ASSERT_EQ(fresher.getId(), handle.getCallHandler(firstCall)->getId());
}

TEST(CallHandleTest, AddEmployeeCanNotHandle){
	CallHandle handle;
	Fresher fresher("one");
	RankedCall firstCall(2);
	handle.addEmployee(fresher);
	ASSERT_EQ(nullptr, handle.getCallHandler(firstCall));
}

TEST(CallHandleTest, HandleLevelOne){
	CallHandle handle;
	Fresher fresher("fresher");
	TechLead techLead("techLead");
	ProductManager productManager("productManager");
	RankedCall firstCall(1);
	handle.addEmployee(fresher);
	handle.addEmployee(techLead);
	handle.addEmployee(productManager);

	Employee *emp = handle.getCallHandler(firstCall);
	emp->handleCall(firstCall, handle);

	ASSERT_EQ(fresher.getId(), firstCall.HandledBy);
}

TEST(CallHandleTest, HandleLevelTwo){
	CallHandle handle;
	Fresher fresher("fresher");
	TechLead techLead("techLead");
	ProductManager productManager("productManager");
	DispatchedToLevelTwoCall dispTwo;
	handle.addEmployee(fresher);
	handle.addEmployee(techLead);
	handle.addEmployee(productManager);

	Employee *emp = handle.getCallHandler(dispTwo);
	emp->handleCall(dispTwo, handle);

	ASSERT_EQ(techLead.getId(), dispTwo.HandledBy);
}

TEST(CallHandleTest, HandleLevelThree){
	CallHandle handle;
	Fresher fresher("fresher");
	TechLead techLead("techLead");
	ProductManager productManager("productManager");
	DispatchedToLevelThreeCall dispThree;
	handle.addEmployee(fresher);
	handle.addEmployee(techLead);
	handle.addEmployee(productManager);

	Employee *emp = handle.getCallHandler(dispThree);
	emp->handleCall(dispThree, handle);

	ASSERT_EQ(productManager.getId(), dispThree.HandledBy);
}

TEST(CallHandleTest, PendingCallLevelTwo){
	CallHandle handle;
	Fresher fresher("fresher");
	DispatchedToLevelTwoCall dispTwo;
	handle.addEmployee(fresher);

	Employee *emp = handle.getCallHandler(dispTwo);
	emp->handleCall(dispTwo, handle);

	ASSERT_EQ(1, handle.getNumOfPendingCalls());
}

} /* namespace chapterSeven */
