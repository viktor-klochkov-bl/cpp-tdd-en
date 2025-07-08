// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#ifndef ORDER_PROCESSOR_TEST_COUT_REDIRECT_H
#define ORDER_PROCESSOR_TEST_COUT_REDIRECT_H

#include <iostream>
#include <sstream>
#include <string>

class CoutRedirect
{
public:
    CoutRedirect()
    {
        coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(ss.rdbuf());
    }

    ~CoutRedirect() { std::cout.rdbuf(coutbuf); }

    std::string get_output() { return ss.str(); }

private:
    std::streambuf* coutbuf;
    std::stringstream ss;
};

#endif // ORDER_PROCESSOR_TEST_COUT_REDIRECT_H
