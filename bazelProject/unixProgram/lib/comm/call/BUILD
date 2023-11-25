cc_library(
    name = "singlecall",
    srcs = ["singlecall.h"],
    copts = ["-std=c++11"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "single_test",
    srcs = ["single_test.cpp"],
    deps = ["//lib/comm/call:singlecall",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)