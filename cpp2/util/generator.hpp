// generator.hpp
#pragma once
#include <coroutine>
#include <utility>

template<typename T>
struct generator {
    struct promise_type {
        T current;
        generator get_return_object() {
            return generator{
                std::coroutine_handle<promise_type>::from_promise(*this)
            };
        }
        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        std::suspend_always yield_value(T value) noexcept {
            current = std::move(value);
            return {};
        }
        void return_void() noexcept {}
        void unhandled_exception() { std::terminate(); }
    };

    using handle_type = std::coroutine_handle<promise_type>;
    handle_type h{};

    explicit generator(handle_type h_) : h(h_) {}
    generator(const generator&) = delete;
    generator(generator&& other) noexcept : h(std::exchange(other.h, {})) {}
    ~generator() { if (h) h.destroy(); }

    struct iterator {
        handle_type h{};
        bool done = true;

        iterator() = default;
        explicit iterator(handle_type h_) : h(h_), done(!h_ || h_.done()) {}

        iterator& operator++() {
            h.resume();
            done = h.done();
            return *this;
        }
        const T& operator*() const { return h.promise().current; }
        bool operator==(std::default_sentinel_t) const { return done; }
    };

    iterator begin() {
        if (h) {
            h.resume();
            return iterator{h};
        }
        return iterator{};
    }
    std::default_sentinel_t end() { return {}; }
};
