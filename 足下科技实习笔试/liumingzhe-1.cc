#include <iostream>
#include <optional>
#include <cstring>

/// 1. 现有一个MyData的类，其成员有定长的Vec, Str等；请针对这个类，实现一套序列化/反序列算法
//     序列化：将一个类转换成二进制字节流
//     反序列化: 将二进制字节流转换成一个类

template <typename T, size_t Cap>
struct Vec
{
  T[Cap];
  size_t len;
};

template <size_t Cap>
struct Str
{
  char str[Cap];
  size_t len;
};

struct MyData
{
  Str<128> name{};
  Vec<512> vec{};
};

bool ser_my_data(const MyData &data, uint8_t *buff, size_t len)
{
  // 请补充
  if (len < sizeof(data.name) + sizeof(data.vec))
  {
    return false;
  }

  std::memcpy(buff, &data.name, sizeof(data.name));
  buff += sizeof(data.name);
  std::memcpy(buff, &data.vec, sizeof(data.vec));
  buff += sizeof(data.vec);

  return true;
}

std::optional<MyData> deser_my_data(uint8_t *buff, size_t len)
{
  // 请补充
  MyData data;

  if (len < sizeof(data.name) + sizeof(data.vec))
  {
    return std::nullopt;
  }

  std::memcpy(&data.name, buff, sizeof(data.name));
  buff += sizeof(data.name);
  std::memcpy(&data.vec, buff, sizeof(data.vec));
  buff += sizeof(data.vec);

  return data;
}