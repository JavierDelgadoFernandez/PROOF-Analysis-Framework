#!/bin/bash

docker build -t paf .
docker run paf /bin/sh -c "cd /opt/PAF/test/ && mkdir build && cd build &&
                               cmake -DCMAKE_BUILD_TYPE=Debug .. && make &&
                               ctest"

