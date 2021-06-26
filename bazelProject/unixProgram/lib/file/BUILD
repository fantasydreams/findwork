cc_library(
    name = "myfcntl",
    hdrs = ["myfcntl.h"],
    srcs = ["myfcntl.cc"],
    visibility = ["//visibility:public"],
    deps = ["//lib/err:myerr"],
    copts = ["-std=c++11"]
)


cc_library(
    name = "mode",
    hdrs = ["mode.h"],
    srcs = ["mode.cc"],
    visibility = ["//visibility:public"],
    deps = ["//lib/condition:condition",
            "//lib/err:myerr",
            "//lib/string:stringlib",
        ],
    copts = ["-std=c++11"],
)