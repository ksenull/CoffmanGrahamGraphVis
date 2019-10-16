#pragma once

#include <algorithm>

template <typename T, typename Parameter>
class NamedType
{
public:
	explicit NamedType(const T& value) : value_(value) {}
	explicit NamedType(T&& value) : value_(std::move(value)) {}
	T& get() { return value_; }
	const T& get() const { return value_; }
private:
	T value_;
};