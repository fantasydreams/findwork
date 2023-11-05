cc_library(
    name = "thread_pool",
    hdrs = ["thread_pool.h"],
    srcs = ["thread_pool.cpp"],
    copts = [
        "-std=c++11",
    ],

    deps = [
        "//lib/comm/class:nocopyable",
        "//lib/comm/class:exception",
    ],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "thread_pool_test",
    srcs = [
            "thread_pool_test.cpp",
        ],
    deps = [
            ":thread_pool",
            "@googletest//:gtest_main",
        ],
    copts = ["-std=c++11"],
)