#ifndef CORENUMERIC_H
#define CORENUMERIC_H

#include <iostream>
#include <concepts>
#include <iterator>
#include <vector>


using namespace std;


namespace core_numeric {

    template <typename C>
    concept Iterable = requires (C c) {
        begin(c);
        end(c);
    };

    template <typename T>
    concept Addable = requires (T a, T b) {
        { a + b } -> same_as<T>;
    };

    template <typename T>
    concept Divisible = requires (T a, size_t n) {
        { a / n } -> same_as<T>;
    };

    template <typename T>
    concept Multipliable = requires (T a, T b) {
        { a * b } -> std::same_as<T>;
    };

    template <typename T>
    concept Comparable = requires (T a, T b) {
        { a < b } -> std::convertible_to<bool>;
    };

    template <typename T>
    concept Numeric = Addable<T> && Multipliable<T> && Comparable<T>;



    template <Iterable C>
    requires Addable<typename C::value_type>
    auto sum(const C& container) {
        using T = typename C::value_type;
        T result{};
        for (const auto& value : container) result = result + value;
        return result;
    }



    template <Iterable C>
    requires Divisible<typename C::value_type>
    auto mean(const C& container) {
        auto s = sum(container);
        size_t n = distance(begin(container), end(container));

        if (n == 0)
            return static_cast<typename C::value_type>(0);
        return s / n;
    }



    template <Iterable C>
    requires Addable<typename C::value_type>
    auto variance(const C& container) {
        using T = typename C::value_type;

        auto mu = mean(container);

        T sum_sq_diff{};
        size_t n = 0;

        for (const auto& x : container) {
            auto diff = x - mu;
            sum_sq_diff = sum_sq_diff + (diff * diff);
            n++;
        }
        if (n == 0)
            return static_cast<T>(0);

        return sum_sq_diff / n;
    }


    template <Iterable C>
    requires Numeric<typename C::value_type>
    auto max(const C& container) {
        auto it = std::begin(container);
        auto end = std::end(container);
        if (it == end) return typename C::value_type{};

        auto current_max = *it;
        for (++it; it != end; ++it) {
            if (current_max < *it) {
                current_max = *it;
            }
        }
        return current_max;
    }


    template <Iterable C, typename Op>
    requires Addable<typename C::value_type>
    auto transform_reduce(const C& container, Op func) {

        using T = typename C::value_type;
        T result {};

        for (auto const& value : container) {

            result = result + func(value);
        }
        return result;
    }


    template <Addable... Args>
    auto sum_variadic(Args... args) {
        if constexpr ((is_integral_v<Args> && ...)) {
            return (args + ...);
        } else {
            return (args + ...);
        }
    }

    template <Addable... Args>
    auto mean_variadic(Args... args) {
        auto s = sum_variadic(args...);
        return s / sizeof...(args);
    }


    template<typename... Args>
    requires (Comparable<Args> && ...)
    auto max_variadic(Args... args) {

        using T = std::common_type_t<Args...>;

        T max_number = std::numeric_limits<T>::lowest();

        ((max_number = (args > max_number? args : max_number)), ...);

        return max_number;
    }


        template <Addable... Args>
        auto variance_variadic(Args... args) {
            auto mu = mean_variadic(args...);
            auto count = sizeof...(args);

            auto sum_sq_diff = (((args - mu) * (args - mu)) + ...);
            return sum_sq_diff / count;
        }
    }


#endif //CORENUMERIC_H
