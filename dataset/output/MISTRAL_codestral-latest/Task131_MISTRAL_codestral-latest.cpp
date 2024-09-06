#include <iostream>
#include <sstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/string.hpp>

std::string deserialize_data(const std::string& data) {
    std::stringstream ss(data);
    boost::archive::binary_iarchive ia(ss);
    std::string result;
    ia >> result;
    return result;
}