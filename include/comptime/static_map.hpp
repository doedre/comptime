#pragma once

#include <cstddef>
#include <initializer_list>

#include <comptime/ct_factory.hpp>

namespace comptime {

  template<
      typename KeyT,
      typename MappedT>
  struct static_map_value {
    KeyT key;
    MappedT value;

    constexpr static_map_value(KeyT k, MappedT v) :
        key(k),
        value(v)
    {}

    constexpr static_map_value() :
        key(),
        value()
    {}
  };

  template<
      typename KeyT,
      typename MappedT,
      std::size_t Capacity>
  class static_map {
   private:
    using MapValue = static_map_value<KeyT, MappedT>;

    MapValue storage_[Capacity];
    std::size_t size_;

   public:
    using key_type = KeyT;
    using mapped_type = MappedT;
    using value_type = MapValue;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = value_type*;
    using const_iterator = const value_type*;

    constexpr static_map() :
        storage_(),
        size_(0)
    {}

    [[nodiscard]] constexpr size_type max_size() const noexcept
    {
      return Capacity;
    }

    [[nodiscard]] constexpr size_type size() const noexcept
    {
      return size_;
    }

    [[nodiscard]] constexpr bool empty() const noexcept
    {
      return size_ == 0;
    }

    constexpr void clear() noexcept
    {
      for (auto i = this->begin(); i != this->end(); ++i) {
        i->key = key_type();
        i->value = mapped_type();
        i = nullptr;
      }
      size_ = 0;
    }

    [[nodiscard]] constexpr iterator begin() noexcept
    {
      return &(storage_[0]);
    }

    [[nodiscard]] constexpr const_iterator cbegin() const noexcept
    {
      return &(storage_[0]);
    }

    [[nodiscard]] constexpr iterator end() noexcept
    {
      return &(storage_[size_]);
    }

    [[nodiscard]] constexpr const_iterator cend() const noexcept
    {
      return &(storage_[size_]);
    }
    
    [[nodiscard]] constexpr iterator find(const key_type& key) noexcept
    {
      for (auto i = this->begin(); i != this->end(); ++i) {
        if (i->key == key)
          return i;
      }

      return nullptr;
    }

    [[nodiscard]] constexpr const_iterator find(const key_type& key) const noexcept
    {
      for (auto i = this->cbegin(); i != this->cend(); ++i) {
        if (i->key == key)
          return i;
      }

      return nullptr;
    }

    constexpr iterator insert(const value_type& val) noexcept
    {
      if (size_ == Capacity)
        return nullptr;

      const auto f = find(val.key);
      if (f != nullptr)
        return f;

      storage_[size_] = val;
      ++size_;
      return &(storage_[size_]);
    }

    constexpr iterator insert_or_assign(const value_type& val) noexcept
    {
      if (size_ == Capacity)
        return nullptr;

      const auto f = find(val.key);
      if (f != nullptr) {
        f->value = val.value;
        return f;
      }

      storage_[size_] = val;
      ++size_;
      return &(storage_[size_]);
    }

    constexpr iterator erase(iterator pos) noexcept
    {
      for (auto i = pos; i != this->end() - 1; ++i) {
        i->key = (i + 1)->key;
        i->value = (i + 1)->value;
      }

      --size_;
      return pos;
    }

    constexpr bool erase(const key_type& key) noexcept
    {
      auto f = find(key);
      if (!f)
        return false;

      return erase(f);
    }
  };

  template<typename... T>
  using static_map_t = static_map<T..., sizeof...(T)>;

  template<typename KeyT, typename MappedT, std::size_t Capacity>
  struct static_container_constructor<static_map<KeyT, MappedT, Capacity>> {
    template<typename... Values>
    constexpr static auto ct_make(Values&&... values) noexcept
    {
      return static_map<KeyT, MappedT, sizeof...(values)>(std::forward<Values>(values)...);
    }
  };

} // namespace comptime
