cc_library(
	name = "linkComm",
	hdrs = ["linkcomm.h"],
	srcs = ["linkcomm.cpp"],
	visibility = ["//visibility:public"],
)

cc_library(
	name = "AddTwoNum",
	hdrs = ["2.AddTwoNumbers.h"],
	srcs = ["2.AddTwoNumbers.cpp"],
    copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "AddTwoNumTest",
	srcs  = ["2.AddTwoNumberstest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["AddTwoNum",
			 "@googletest//:gtest_main"],
)


cc_library(
	name = "143ReorderList",
	hdrs = ["143.ReorderList.h"],
	srcs = ["143.ReorderList.cpp"],
    copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "143ReorderListTest",
	srcs  = ["143.ReorderListTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["143ReorderList",
			 "@googletest//:gtest_main"],
)



cc_library(
	name = "142LinkedListCycleII",
	hdrs = ["142.LinkedListCycleII.h"],
	srcs = ["142.LinkedListCycleII.cpp"],
	copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "142LinkedListCycleIITest",
	srcs  = ["142.LinkedListCycleIITest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["142LinkedListCycleII",
			 "@googletest//:gtest_main"],
)

cc_library(
	name = "206ReverseLinkedList",
	hdrs = ["206.ReverseLinkedList.h"],
	srcs = ["206.ReverseLinkedList.cpp"],
	copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "206ReverseLinkedListTest",
	srcs  = ["206.ReverseLinkedListTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["206ReverseLinkedList",
			 "@googletest//:gtest_main"],
)

cc_library(
	name = "21MergeTwoSortedLists",
	hdrs = ["21.MergeTwoSortedLists.h"],
	srcs = ["21.MergeTwoSortedLists.cpp"],
	copts = ["-std=c++11"],
	deps  = ["linkComm"],
)

cc_binary(
	name  = "21MergeTwoSortedListsTest",
	srcs  = ["21.MergeTwoSortedListsTest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["21MergeTwoSortedLists",
			 "@googletest//:gtest_main"],
)