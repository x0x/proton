Duchat
======
Duchat provides implementation of a dummy chat protocol, used for
development testing of proton.

Duchat is disabled by default in standard proton builds. It can be enabled with:

    mkdir -p build && cd build && cmake -DHAS_DUMMY=ON .. && make -s

