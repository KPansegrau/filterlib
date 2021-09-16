# Filter

Port of the [scipy](https://docs.scipy.org/doc//scipy/reference/generated/scipy.signal.butter.html) digital butterworth filter design methods to C++. The filter can then be used to filter a signal with second order sections online (push sample through sections individually) or offline (process whole signal).
The project uses [CMake](https://cmake.org/) as build-tool and [googletest](http://google.github.io/googletest/primer.html) as testing-framework.

How to build and run the tests (start from top-level directory)
```sh
mkdir build && cd build && cmake .. && cmake --build . && ctest
```
You can then change into the `bin` directory and run the example application
```sh
cd ../bin && ./example
```
The example application will produce `bin/original.txt`, `bin/process_batch.txt` and `bin/process_sample.txt`. You can display their content with
```sh
python3 test_data/vis_example_output.py
```

# Reference
Code from [scipy](https://github.com/scipy/scipy/blob/v1.7.1/scipy/signal/filter_design.py#L2846-L2957) with simplified api.