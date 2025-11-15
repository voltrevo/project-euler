#include <ranges>

template <typename State, typename Fn>
struct fold_left {
    State state;
    Fn combine;

    fold_left(State state, Fn combine): state(state), combine(combine) {}

    template <std::ranges::input_range R>
    State operator()(R&& rng) {
        for (auto&& x : rng) {
            state = combine(state, x);
        }

        return state;
    }

    template <std::ranges::input_range R>
    friend State operator|(R&& rng, fold_left self) {
        return self(rng);
    }
};
