FROM javierdelgado/root

# Some required environment variables
# LD_LIBRARY_PATH is not read properly from ROOT so it is set manually here
ENV PAFPATH=/opt/PAF
ENV PAFREPOSITORIES=./packages
ENV PATH=$PATH:$PAFPATH/bin
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/:$PAFPATH/lib

# Copies and compile the code
COPY . $PAFPATH
WORKDIR $PAFPATH/build/
RUN bash -c "cmake .. && make install && rm -rf $PAFPATH/build/"
VOLUME $PAFPATH
