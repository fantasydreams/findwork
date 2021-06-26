cc_library(
      name = "gtest",
      srcs = [
            "googletest/src/gtest-all.cc",
            "googlemock/src/gmock-all.cc",
      ],
      hdrs = glob([
          "**/*.h",
          "googletest/src/*.cc",
          "googlemock/src/*.cc",
      ]),
      includes = [
          "googlemock",
          "googletest",
          "googletest/include",
          "googlemock/include",
      ],
      linkopts = ["-pthread"],
      visibility = ["//visibility:public"],
      copts = ["-std=c++11"]
  )

  cc_library(
      name = "gtest_main",
      srcs = ["googlemock/src/gmock_main.cc"],
      linkopts = ["-pthread"],
      visibility = ["//visibility:public"],
      deps = [":gtest"],
      copts = ["-std=c++11"]
  )