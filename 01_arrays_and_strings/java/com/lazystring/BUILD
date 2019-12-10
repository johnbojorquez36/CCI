load("@rules_java//java:defs.bzl", "java_library", "java_test")

java_test(
    name = "combined_test",
    srcs = ["CombinedTest.java"],
    test_class = "com.lazystring.CombinedTest",
    deps = [
        ":compress",
        ":one_away",
        ":unique",
        ":urlify",
    ],
)

java_library(
    name = "compress",
    srcs = ["Compress.java"],
    deps = [],
)

java_library(
    name = "one_away",
    srcs = ["OneAway.java"],
    deps = [],
)

java_library(
    name = "unique",
    srcs = ["Unique.java"],
    deps = [],
)

java_library(
    name = "urlify",
    srcs = ["URLify.java"],
    deps = [],
)