#pragma once

#include <atomic>

template <typename T>
class TypeFamily {
	static std::atomic_size_t _idCount;

public:
	template<std::derived_from<T> U>
	static std::size_t Type() {
		static const std::size_t ID = _idCount++;
		return ID;
	}
};

template<typename T>
std::atomic_size_t TypeFamily<T>::_idCount{ 0 };
