#pragma once
#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;
class Serializer
{
public:
  template <typename T>
  void serialize(stringstream &ss, T &&data)
  {
    boost::archive::text_oarchive oa(ss,boost::archive::no_header);
    oa << data;
  }
  template <typename T, typename... params>
  void serialize(stringstream &ss, T &&data, params &&...args)
  {
    serialize(ss,  forward<T>(data));
    if (sizeof...(args) != 0)
      serialize(ss, forward<params>(args)...);
  }
};

class Deserializer
{
public:
  template <typename T>
  void deserialize(stringstream &ss, T &data)
  {
    boost::archive::text_iarchive ia(ss,boost::archive::no_header);
    ia >> data;
  }
//  template <typename T, typename... params>
//  void deserialize(stringstream &ss, T &&data, params &&...args)
//  {
//    deserialize(ss,  forward<T>(data));
//    if (sizeof...(args) != 0)
//      deserialize(ss, forward<params>(args)...);
//  }
};
