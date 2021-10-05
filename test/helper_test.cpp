#include <gtest/gtest.h>
#include <csv.hpp>

#include <iostream>
#include <fstream>
#include <filesystem>

#include <boost/algorithm/string/replace.hpp>

TEST(BasicHelper, CSV) {
    auto fpath = std::string(__FILE__);
    boost::replace_all(fpath, "helper_test.cpp", "test1.csv");
    csv::CSVReader reader(fpath);
    for (auto& x : reader.get_col_names())
    {
        std::cout << x << std::endl;
    }
    for (auto& row : reader) { // Input iterator
        std::cout<<row["date"].get<std::string>()<<","
            << row["time"].get<std::string>() << ","
            <<row["bid"].get<double>() << ","
        <<row["ask"].get<double>()<<std::endl;
    }
}