cc_library(
    name = "nocopyable",
    srcs = ["no_copyable.h"],
    copts = ["-std=c++11"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "scopeguard",
    srcs = ["scopeguard.h"],
    copts = ["-std=c++11"],
    deps = [
        "nocopyable",
    ],
    visibility = ["//visibility:public"],
)