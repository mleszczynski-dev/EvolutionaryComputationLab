#pragma once

#include <functional>

#include <memory>
#include <type_traits>

template<typename T>
concept EnableSharedFromThis =
    std::is_base_of<std::enable_shared_from_this<T>, T>::value;

// template <EnableSharedFromThis Derived>
class AbstractSocket
{
public:
	virtual ~AbstractSocket() = default;

    virtual void close() = 0;

    // void setDisconnectedCallback(std::function<void()> callback);
    void setErrorCallback(std::function<void()> callback);

protected:
    // std::function<void()> disconnectedCallback_;
    std::function<void()> errorCallback_;
};
