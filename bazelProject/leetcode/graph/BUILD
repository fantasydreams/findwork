cc_library(
	name = "210CourseScheduleII",
	hdrs = ["210.CourseScheduleII.h"],
	srcs = ["210.CourseScheduleII.cpp"]
)

cc_binary(
	name  = "210CourseScheduleIITest",
	srcs  = ["210.CourseScheduleIITest.cpp"],
	copts = ["-std=c++11"],
	deps  = ["210CourseScheduleII",
			 "@googletest//:gtest_main"],
)