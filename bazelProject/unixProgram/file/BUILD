cc_binary(
    name  = "fcntl_getfl",
    srcs  = ["fcntl_getfl.cc"],
    copts = ["-std=c++11"],
    deps  = ["//lib/err:myerr"],
)

cc_binary(
    name = "set_file_flag",
    srcs = ["setflag.cc"],
    copts = ["-std=c++11"],
    deps = ["//lib/file:myfcntl"],
)

cc_binary(
    name = "umask",
    srcs = ["umask.cc",
            "umask.h",
        ],
    deps = ["//lib/err:myerr",
            "//lib/condition:condition",
            "//lib/string:stringlib",
            "//lib/file:mode",
        ],
    copts = ["-std=c++11"],
)


cc_binary(
	name = "seek",
	srcs = ["seek.cc"],
	deps = ["//lib/term:term",
		],
	copts = ["-std=c++11"],
)

cc_binary(
	name = "link",
	srcs = ["link.cc"],
	deps = ["//lib/term:term",
            "//lib/condition:condition",
            "//lib/err:myerr",
		],
	copts = ["-std=c++11"],
)