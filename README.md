# CTCI (Cracking the Coding Interview)
Solutions to Gayle Laakmann McDowell's **C**racking **t**he **C**oding **I**nterview in C++. Some are also in Java.

All solutions to these problems are my own original work.

# Testing

I'm starting to experiment with using Bazel for running unit tests, because I can't get enough of it at work. So far, only Chapter 1 is partially migrated to use Bazel. To run the tests, you'll need to first install `bazel`. Once installed it's as simple as running:

```sh
$ bazel test 01_arrays_and_strings/java/com/lazystring:combined_test
```

Alternatively, you can run the tests within that directory:

```sh
$ cd 01_arrays_and_strings/java/com/lazystring
$ bazel test :combined_test
```

By default, Bazel will write all the test output to a file. For quick debugging it's useful to print the test output directly to the console. This can be done by adding `--test_output=all` to the above command.
